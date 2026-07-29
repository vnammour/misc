/* Tue Jul 28 12:54:30 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define uint unsigned
// const uint intsize = 32 << (~((uint)0) >> 63);
const int maxint = ((uint)1 << (sizeof(int) * 8 - 1)) - 1;
const int minint = -1 << (sizeof(int) * 8 - 1);
int a2i(char *s, int *ok) {
    *ok = 0;
    while(isspace(*s)) ++s;
    int sign = *s == '-' ? -1 : 1;
    if (*s == '+' || *s == '-') ++s;
    uint num = 0, base = 10, m = maxint;
    if (sign < 0) ++m;
    while (isdigit(*s)) {
        if (num > m/base) return 0;
        num *= base;
        if (num > m - (*s - '0')) return 0;
        num += *s - '0';
        ++s;
    }
    if (*s == 0) *ok = 1;
    return (int)num * sign;
}
int numdigits(int n) {
    int count = 1;
    while(n/=10) ++count;
    return count;
}
char *i2a(int n) {
    int sign = n < 0 ? -1 : 1;
    // +2: +1 for sign, +1 for null terminator
    int size = sizeof(char) * (numdigits(n) + (sign < 0 ? 1 : 0) + 1);
    char *s = (char*) malloc(size);
    int len = size-1;
    s[len--] = 0;
    int base = 10;
    while (n != 0) {
        s[len--] = (n % base) * sign + '0';
        n /= base;
    }
    if (sign < 0) s[len--] = '-';
    return s;
}
double a2f(char *s) {
    while(isspace(*s)) s++;
    int sign = *s == '-' ? -1 : 1;
    if (*s == '-' || *s == '+') ++s;
    double num = 0;
    int base = 10;
    while (isdigit(*s)) num = num * base + *s - '0', ++s;
    if (*s == '.') ++s;
    double pow = 10;
    while (isdigit(*s)) {
        num += (*s - '0')/pow;
        pow *= base;
        ++s;
    }
    return num * sign;
}
int main(int argc, char *argv[])
{
    char *s = i2a(minint);
    printf("%s\n", s);
    int ok;
    printf("%d\n", a2i(s,&ok));
    free(s);
    printf("%f\n", a2f("-1200013.34"));
    printf("%f\n", a2f(".31444"));
}
