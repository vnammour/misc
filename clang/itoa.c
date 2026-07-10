/* Sun Jul  5 08:59:12 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#define null NULL 
const unsigned intsize = 32 << (~((unsigned)0) >> 63);
const int maxint = ((unsigned)1 << (intsize-1)) - 1;
const int minint = -1 << (intsize-1);
char *itoa(int num, char *s, int width);
#define i2a(int) itoa(int,0,0)
int numdecimals(int n);
int main(int argc, char *argv[])
{
    char *s = i2a(minint);
    printf("%s\n", s);
    free(s);
    s = itoa(maxint,0,3);
    printf("%s\n", s);
    free(s);
    printf("decimals: %d\n", numdecimals(-123));
}

int numdecimals(int n) {
    int num = 1;
    for (; (n/=10)!=0; num++);
    return num;
}


char *itoa(int num, char *buf, int width) {
    int sz = 12 + width;
    if (buf == null) {
        buf = (char*) malloc(sizeof(char)* sz);
    }
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
    for (; width > 0; --width) *--p = ' ';
    char *temp = (char*) malloc(sizeof(char) * (buf + sz - p));
    if (temp == null) {
        return buf;
    }
    strcpy(temp,p);
    free(buf);
    return temp;
}
