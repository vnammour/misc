/* Sun Jul  5 08:59:12 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
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
    size_t count = 1;
    while (m/=10) {
        // m/=10;
        printf("m = %d\n", m);
        ++count;
    }
    printf("count = %d\n", count);*/
    char *s = itoa(minint);
    printf("%s\n", s);
    free(s);
    s = itoa(maxint);
    printf("%s\n", s);
    free(s);
}

char *itoa(int num) {
    int sz = 12;
    char *buf = (char*) malloc(sizeof(char)* sz);
    char *p = buf + sz - 1;
    *p-- = '\0';
    int sign = num < 0 ? -1 : 1;
    int base = 10;
    while (num != 0) {
        *p-- = (num % base) * sign + '0';
        num /= base;
    }
    ++p;
    if (sign == -1) *--p = '-';
    char *temp = (char*) malloc(sizeof(char) * (buf + sz - p));
    if (temp == null) {
        return buf;
    }
    strcpy(temp,p);
    free(buf);
    return temp;
}
