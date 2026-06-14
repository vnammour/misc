/* Wed Jun 10 11:21:59 AM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
int wordlength(); 
int bitcount(unsigned);
int bitcount2(unsigned);
int main(int argc, char *argv[])
{
    int size = sizeof(unsigned int) * 8;
    int width = 16;
    // getbits
    {
	    int y = 0x7d53;
	    // printf("y = %#0*b\n", size,y);
	    printf("y = 0b%0*b\n",width,y);
	    printf("z = 0b%0*b\n",width,getbits(y,4,3));
        printf("\n");
    }
    // setbits
    {
        int x = 0xb58d;
	    int y = 0x7d53;
        printf("y = 0b%0*b\n", width,y);
        printf("x = 0b%0*b\n", width,x);
        printf("z = 0b%0*b\n", width,setbits(x,9,4,y));
    }
    // invert
    {
        int x = 0xb58d;
        printf("x = 0b%0*b\n", width,x);
        printf("z = 0b%0*b\n", width,invert(x,9,4));
    }
    // rightrot
    {
        // int x = 0b11011101;
        int x = 0x88888887;
        printf("x = 0b%0*b\n", width,x);
        printf("x = 0b%0*b\n", width,rightrot(x,3));
    }
    // bitcount
    {
        int x = 0x88;
        printf("%d\n", bitcount(x));
        printf("%d\n", bitcount2(x));
    }
}

// getbits: returns the (right-adjusted) n-bit field of x that begins at position p.
// We assume that bit position 0 is at the right end and that n and p are sensible
// positive values.
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0<<n);
}
// returns x with the n bits that begin at position p set to the
// rightmost n bits of y, leaving the other bits unchanged.
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return (x & ~(~(~0<<n)<<(p-n+1))) | (y &~(~0<<n))<<(p-n+1);
}

// invert: returns x with the n bits that begin at position p
// inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
// Note: x ^ 0 = x, x ^ 1 = ~x
unsigned invert(unsigned x, int p, int n) {
    return x ^ ~(~0<<n)<<(p-n+1);
}

// rightrot(x,n): returns the value of the integer x rotated to the right
// by n bit positions.
unsigned rightrot(unsigned x, int n) {
    int p = wordlength() - 1;
    return (x & ~(~0<<n))<<(p-n+1) | x>>n;
}

// wordlength: computes word length of the machine
int wordlength() {
    return 8;
    int i;
    unsigned v = (unsigned) ~0;
    for (i = 1; (v = v >> 1) > 0; i++);
    return i;
}

// Section 2.10, bitcount: Declaring the argument x to be unsigned ensures that when it is
// right-shifted, vacated bits will be filled with zeros, not sign bits, regardless of the
// machine the program is run on.
int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01) b++;
    return b;
}

// Ex 2-9
int bitcount2(unsigned x) {
    int b;
    for (b = 0; x != 0; x &= x-1)
        b++;
    return b;
}
