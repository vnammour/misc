/* Sun Jul  5 08:59:12 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define null NULL 
char *itoa(int num);
const unsigned intsize = 32 << (~((unsigned)0) >> 63);
const int maxint = ((unsigned)1 << (intsize-1)) - 1;
const int minint = -1 << (intsize-1);
int main(int argc, char *argv[])
{
    /*printf("%d\n", maxint);
    printf("%d\n", minint);
    unsigned m = maxint;
    size_t count = 0;
    while (m/=10) {
        printf("m = %d\n", m);
        ++count;
    }
    printf("count = %d\n", count);*/
    char *s = itoa(123);
    printf("%s\n", s);
}

char *itoa(int num) {
    int sz = 11;
    char *buf = (char*) malloc(sizeof(char)* sz);
    char *p = buf + sz - 1;
    *p-- = '\0';
    int sign = num < 0 ? -1 : 1;
    int base = 10;
    while (num != 0) {
        *p-- = num % base;
        num /= base;
    }
    if (sign == -1) *p-- = '-';
    return p;
}
