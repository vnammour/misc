/* Thu Jul  2 08:19:34 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
// const unsigned intsize = (unsigned)32 << (~((unsigned)0) >> 63);
int atoi(char *s, int *error);
bool isDigit(int c);
bool isSpace(int c); 
const unsigned intsize = 32 << (~((unsigned)0) >> 63);
const int maxint = ((unsigned)1 << (intsize-1)) - 1;
const int minint = -1 <<(intsize-1);
int main(int argc, char *argv[])
{
    printf("%d\n", maxint);
    printf("%d\n", minint);
    char *s = "-2147483648";
    int error = 0;
    printf("%d\n", atoi(s,&error));
    if (error != 0) {
        printf("Error\n");
    }
}

bool isDigit(int c) {
    return c >= '0' && c <= '9';
}

bool isSpace(int c) {
    return c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\r';
}

int atoi(char *s, int *error) {
    if (s == NULL) {
        *error = 1;
        return 0;
    }
    for (; isSpace(*s); s++);
    int sign = *s == '-' ? -1 : 1;
    if (s[0] == '-' || s[0] == '+') ++s;
    int c;
    unsigned int num = 0;
    unsigned int max = (unsigned) maxint;
    if (sign == -1) ++max;
    while (c = *s++) {
        if (!isDigit(c)) {
            *error = 1;
            return 0;
        }
        if (num > max/10) {
            *error = 1;
            return 0;
        }
        num *= 10;
        if (num > max - c + '0') {
            *error = 1;
            return 0;
        }
        num += c-'0';
    }
    *error = 0;
    return num * sign;
}
