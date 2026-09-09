/* Wed Sep  9 04:29:26 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
// unsigned intsize = 32 <<((unsigned)(~0) >> 64);
int intsize = 32;
int maxint = (1 << (intsize-1)) - 1;
int minint = -1 << (intsize-1);
int isdigit(char c) {
    return c >= '0' && c <= '9';
}
int isspace(char c) {
    return c == ' ' || c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == '\f';
}
int myatoi(char *s, int len) {
    char *p = s + len;
    while(s < p && isspace(*s)) ++s;
    int sign = 1;
    if (s < p && (*s == '-' || *s == '+')) {
        if (*s == '-') sign = -1;
        ++s;
    }
    unsigned num = 0;
    unsigned m = maxint;
    unsigned base = 10;
    if (sign < 0) m++;
    while (s < p) {
        if (!isdigit(*s)) break;
        if (num > m / base) {
            num = m; break;
        }
        num *= base;
        if (num > m - (*s - '0')) {
            num = m; break;
        }
        num += (*s - '0');
    }
    int result = 0;
    if (sign < 0 && num > 0) {
        result = (int)(num-1) * sign;
        --result;
    } else result = num * sign;
    return result;
}
int main(int argc, char *argv[])
{
}
