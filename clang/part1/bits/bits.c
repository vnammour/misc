/* Sat Jun  6 04:23:30 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>

const unsigned short shortsize = sizeof(short) * 8;
const short maxshort = (short)((unsigned short)(1 << (shortsize-1)) - 1);
const short minshort = ~maxshort;
const unsigned int intsize = sizeof(int) * 8;
const int maxint = (int)((unsigned int)(1 << (intsize - 1)) - 1);
const int minint = ~maxint;
const unsigned long long longsize = sizeof(long long) * 8;
const long long maxlong = (long long) ((unsigned long long)((1ul << (longsize - 1)) - 1));
const long long minlong = ~maxlong;
typedef unsigned char byte;

void setkthbit(int n, int k);
void clearkthbit(int n, int k);
void togglekthbit(int n, int k);
int extract_a_bit_field(int x, int mask, int shift);

int main(int argc, char *argv[])
{
    int x = 0xbd6d;
    int shift = 7;
    int mask = 0xf << shift;
    int y = extract_a_bit_field(x,mask, shift);
    printf("y = %#b\n", y);
    printf("x = \n");
    printf("%#b\n", x);
    setkthbit(x,4);
    clearkthbit(x,4);
    togglekthbit(x,4);
    {
        // problem: set a bit field in a word x to a value y.
        // idea: invert mask to clear, and OR the shifted value.
        // x = (x & ~mask) | (y << shift);
        // example:
        y = 0x3;
        x = (x & ~mask) | (y <<shift);
        printf("%#b\n", x);
    }
}

void setkthbit(int n, int k) {
    n = n | (1<<k);
    printf("%#b\n",n);
}

void clearkthbit(int n, int k) {
    n = n & ~(1<<k);
    printf("%#b\n", n);
}

void togglekthbit(int n, int k) {
    n = n ^ (1 << k);
    printf("%#b\n", n);
}

int extract_a_bit_field(int x, int mask, int shift) {
    printf("x = %#b\n", x);
    int y = (x & mask) >> shift;
    printf("y = %#b\n", y);
    return y;
    // x <<=7;
    // printf("x = %#b\n", x);
}
