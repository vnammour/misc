/* Mon Jul 27 12:25:23 AM IDT 2026 */
/* By: Jamil Nammour */
#include <ctype.h>
#define uint unsigned
// const uint intsize = ~((uint)0) >> 63;
/*const uint intsize = 32 << (~((uint)0) >> 63);
const int maxint = (1 << (intsize-1)) - 1;
const int minint = -1 << (intsize -1);*/
const int maxint = ((uint)1 << (sizeof(int) * 8 -1)) - 1;
const int minint = -1 << (sizeof(int) * 8 -1);

int a2i(char *s, int *ok) {
    *ok = 0; // initially set to false
    while (isspace(*s)) ++s;
    if (*s == 0) return 0;
    int sign = 1;
    if (*s == '-' || *s == '+') ++s, sign = s[-1] == '-' ? -1 : 1;
    uint m = sign == -1 ? (maxint+1) : maxint;
    uint base = 10, num = 0;
    while (isdigit(*s)) {
        if (num > m/base) return 0;
        num *= base;
        if (num > m - (*s - '0')) return 0;
        num += (*s - '0');
        ++s;
    }
    if (*s == 0) *ok = 1;
    return (int)num * sign;
}

/*int main(int argc, char *argv[])
{
    printf("%d\n", maxint);
    char *s = "-2147483648";
    int ok = 0;
    printf("%d\n", a2i(s,&ok));
    printf("Ok? %d\n", ok);
}*/
