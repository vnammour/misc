/* Tue Jun  2 07:26:29 PM IDT 2026 */
/* By: vnammour */
/* Determining int size */
// sizeof(int) returns size in bytes; multiplying by 8 gives total bits.
// const int intsize = sizeof(int) * 8;
// #include <stdint.h>
// ~0ULL creates an unsigned long long with all bits set to 1
// const int intsize = 32 << ((~0ULL) >> 63);
// In C, shifting a signed 1 into the sign bit (which happens when you shift by 31 or 63)
// is undefined behavior. To fix this, we perform the shift using an unsigned int, and then
// cast the final result back to a signed int.
// 1U forces the literal to be an unsiged int, making the shift perfectly safe.
// const int maxint = (int)((1U << (intsize-1)) - 1);
// In C, shifting a negative number (-1) is explicitly undefined behavior.
// To safely get MinInt, we take advantage of the fact that MinInt in two's complement
// representation is exactly the bitwise inverse of MaxInt.
// const int minint = ~maxint;
// Alternatively, if you want to use a shift expression that mirrors Go's logic visually,
// you can isolate the bit pattern using an unsigned type first, and then cast it:
// const int minint = (int)(1U << (intsize - 1));

#include <stdio.h>
// Putting it all together - here is a clean, standard-compliant C implementation:
// 1. Calculate the architecture int size safely
const int intsize = sizeof(int) * 8;
// 2. Calculate maxint for native 'int'
// We cast 1U to (unsigned int) to perform the shift safely, then cast the final
// result to a signed int.
const int maxint = (int)((1U << (intsize - 1)) - 1);
// 3. Calculate minint for native 'int'
// The bitwise inverse of maxint always yields minint in two's complement.
const int minint = ~maxint;

int atoi(char *s, bool *ok);
int main(int argc, char *argv[])
{
    printf("intsize = %d, maxint = %d, minint = %d\n", intsize, maxint, minint);
    char *str = "2147483647";
    bool ok = true;
    int n = atoi(str,&ok);
    if (ok) {
        printf("n = %d\n", n);
    } else {
        printf("n = %d\n", n);
        printf("conversion unsuccessful\n");
    }
}

int atoi(char *s, bool *ok) {
    int sign = 1;
    *ok = true;
    if (s != 0 && (s[0] == '-' || s[0] == '+')) {
        if (s[0] == '-') {
            sign = -1;
        }
        ++s;
    }
    int num = 0;
    if (!s || !*s) {
        *ok = false;
        return num;
    }
    int base = 10;
    int temp = 0;
    for (; *s && *ok; ++s) {
        if (*s < '0' || *s > '9') {
            *ok = false;
            continue;
        }
        temp = *s - '0';
        if (sign < 0) {
            if (num * -1 < minint/base) {
                *ok = false;
                continue;
            }
            num *= base;
            if (num * -1 < minint + temp) {
                *ok = false;
                continue;
            }
            num += temp;
        } else {
            if ( num > maxint/base) {
                *ok = false;
                continue;
            }
            num *= base;
            if ( num > maxint - temp) {
                *ok = false;
                continue;
            }
            num += temp;
        }
    }
    return num * sign;
}

int tolower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    else return c;
}
