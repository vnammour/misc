/* Mon Jun  8 12:43:53 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
int main(int argc, char *argv[])
{
    // int x = 0xb5;
    int size = sizeof(unsigned int) * 8;
    // printf("%#0*b\n", size, x);
    // printf("%#0*b\n", size, getbits(x,5,3));
    // getbits
    {
	    int y = 0x7d53;
	    printf("y = %#0*b\n", size,y);
	    printf("z = %#0*b\n", size, getbits(y,5,6));
        printf("\n");
    }
    // setbits
    {
	    int x = 0xb58d;
	    int y = 0x7d53;
	    printf("y = %#0*b\n", size,y);
	    printf("x = %#0*b\n", size,x);
	    printf("z = %#0*b\n", size, setbits(x,10,6,y));
        printf("\n");
    }
    // invert
    {
	    int x = 0xb58d;
	    printf("x = %#0*b\n", size,x);
	    printf("z = %#0*b\n", size, invert(x,11,9));
        printf("\n");
    }
}
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p - n + 1)) & ~(~0 << n);
}

// setbits(x,p,n,y): returns x with the n bits that begin at position p
// set to the rightmost n bits of y, leaving the other bits unchanged.
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned mask = ~(~(~0<<n)<<(p-n+1));
    x &= mask;
    y = (y & ~(~0<<n)) << (p-n+1);
    return x | y;
}

// invert: returns x with the n bits that begin at position p inverted
// (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
unsigned invert(unsigned x, int p, int n) {
    // (~(~0 << n))<<(p-n+1); // 1111111000000000 -> 0000000111111111 -> 000111111111000
    return x ^ (~(~0 << n))<<(p-n+1);
}
