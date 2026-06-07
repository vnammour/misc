/* Thu Jun  4 08:54:51 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strlen

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
char* tobinary(int x);
char *tohex(char*);
int main(int argc, char *argv[])
{
    int n = maxint;
    char *buf = tobinary(n);
    printf("%s\n", buf);
    char *hex = tohex(buf);
    printf("%s\n", hex);
    free(buf);
    free(hex);
}

char* tobinary(int x) {
    int sign = 1, base = 2;
    if (x < 0) sign = -1;
    int size = sizeof(int) * 8 + 1;
    byte *buf = (byte*) malloc(size);
    int i = size - 1;
    buf[i--] = '\0';
    while (x != 0) {
        buf[i--] = x % base * sign + '0';
        x /= base;
    }
    char d = '0';
    if (sign < 0) d = '1';
    while (i>=0) buf[i--] = d;
    return buf;
}

char *tohex(char *buf) {
    int len = strlen(buf);
    // printf("len = %d, len/4 + 1 = %d\n", len, len/4 + 1);
    char *hex = (char*) malloc(len/4 + 3);
    hex[0] = '0'; hex[1] = 'x';
    for (int i = 2; i < len/4 + 1; i++) hex[i] = 0;
    int mul = 16;
    // i indexes buf, j indexes hex
    for (int i = 0, j = 2; i < len; i++) {
        mul /= 2;
        hex[j] += mul * (buf[i] - '0');
        if ((i+1) % 4 == 0) {
            switch (hex[j]) {
                case 10: hex[j] = 'a'; break;
                case 11: hex[j] = 'b'; break;
                case 12: hex[j] = 'c'; break;
                case 13: hex[j] = 'd'; break;
                case 14: hex[j] = 'e'; break;
                case 15: hex[j] = 'f'; break;
                default: hex[j] += '0'; break;
            }
            mul = 16;
            j++;
        }
    }
    hex[len/4 + 2] = '\0';
    return hex;
}

void printconsts() {
    printf("shortsize = %d\n", shortsize);
    printf("maxshort = %d, minshort = %d\n", maxshort, minshort);
    printf("intsize = %d\n", intsize);
    printf("maxint = %d, minint = %d\n", maxint, minint);
    printf("longsize = %ld\n", longsize);
    printf("maxlong = %ld\n", maxlong);
    printf("minlong = %ld\n", minlong);
    printf("sizeof(type) = %d\n", sizeof(byte));
}
