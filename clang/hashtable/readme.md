1. On 64-bit Linux, long is 64 bits (signed).
2. -1 * 2654435761L = -2654435761.
3. Wait: & 0xffffffff clears the upper 32 bits,
turning it into 1640531535 (positive on 64-bit Linux),
but on 32-bit systems or Windows (where long is 32-bit signed),
hash_value stays negative and % ht->cap returns a negative index (e.g., -5),
causing another out-of-bounds crash!
Fix: Use uint32_t (from <stdint.h>) or unsigned int so the math is
guaranteed unsigned and % ht->cap is always between 0 and cap - 1


3. Is it better to use uint32_t or uint64_t for hash()?
uint32_t is better here for two reasons:
1. Your input key is a 32-bit int: Multiplying a 32-bit value by the 32-bit Knuth golden ratio prime (2654435761U \(\approx 2^{32} \times \frac{\sqrt{5}-1}{2}\)) naturally wraps around 32-bit unsigned arithmetic, scattering the upper bits evenly.
2. Matching constants: If you switched to uint64_t, multiplying by a 32-bit prime wouldn't scatter bits into the upper 32 bits properly unless you also swapped to the 64-bit golden ratio prime (11400714819323198485ULL \(\approx 2^{64} \times \frac{\sqrt{5}-1}{2}\)). Since your keys are standard 32-bit ints, sticking with uint32_t and 2654435761U is faster, simpler, and mathematically matched.


In hash(), I would choose uint32_t (from <stdint.h>) because your Knuth golden ratio constant (2654435761U) is specifically calculated for 32-bit wrap-around arithmetic (2^32 * (sqrt(5)-1)/2), and uint32_t guarantees an exact 32-bit width on every platform.
Key Trade-offs
Feature	uint32_t (<stdint.h>)	unsigned int (Built-in)
Bit-width guarantee	Always 32 bits on every CPU/OS	At least 16 bits (32 bits on modern Linux/Windows/macOS, 16 bits on older embedded MCUs)
Math alignment	Matches the 32-bit golden ratio constant (2654435761U) cleanly	Could behave slightly differently if int is 16-bit or 64-bit (ILP64)
Dependencies	Requires #include <stdint.h>	Built into the language (zero extra headers)
Recommendation
• Use uint32_t whenever your algorithm relies on exact bit widths or bit-wrapping constants (like Knuth's 32-bit multiplicative hash). Since you already #include <stdlib.h> and <stdio.h>, adding #include <stdint.h> costs nothing and makes your intent crystal clear.
• Use unsigned int only when you are writing minimal, zero-header freestanding code or when the exact bit width doesn't matter (such as simple loop counters or array capacities).

// previous hashkey was:
/*static inline int hash(int data) {
    static long GOLDEN_RATIO_PRIME = 2654435761;
    // 2. Multiply the key by the constant
    // This overflows the integer space intentionally, shuffling the bits
    // thoroughly.
    long hash_value = data * GOLDEN_RATIO_PRIME;
    // 3. Mask to simulate standard 32-bit unsigned integer behavior.
    hash_value &= 0xffffffff;
    return hash_value % ht->cap;
}*/
(Tip: On Arch Linux, you can verify zero memory leaks by compiling with -fsanitize=address or running valgrind ./program after calling destroy().)
