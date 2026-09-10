/* Wed Sep  9 04:29:26 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
// unsigned intsize = 32 <<((unsigned)(~0) >> 64);
// int intsize = 32;
#define intsize 32
int maxint = (int)((1U << (intsize-1)) - 1);
int minint = -1 << (intsize-1);
int isDigit(char c) {
    return c >= '0' && c <= '9';
}
int isSpace(char c) {
    return c == ' ' || c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == '\f';
}
int myAtoi(char *s) {
    if (s == 0) return 0;
    while(*s != 0 && isSpace(*s)) ++s;
    int sign = 1;
    if (*s != 0 && (*s == '-' || *s == '+')) {
        if (*s == '-') sign = -1;
        ++s;
    }
    unsigned num = 0;
    unsigned m = maxint;
    unsigned base = 10;
    if (sign < 0) m++;
    while (*s) {
        if (!isDigit(*s)) break;
        if (num > m / base) {
            num = m; break;
        }
        num *= base;
        if (num > m - (*s - '0')) {
            num = m; break;
        }
        num += (*s - '0');
        ++s;
    }
    int result = 0;
    if (sign < 0 && num > 0) {
        // printf("num = %d\n", num);
        result = (int)(num-1) * sign;
        // printf("result = %d\n", result);
        --result;
        // printf("--result = %d\n", result);
    } else result = num * sign;
    return result;
}
int main(int argc, char *argv[])
{
    // printf("maxint = %d\n", maxint);
    // printf("minint = %d\n", minint);
    char *s = "+2147483646";
    printf("%d\n", myAtoi(s));
}
