/* Wed Jun  3 07:22:56 PM IDT 2026 */
/* By: vnammour */
/* Ex 2-3: Write the function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The allowable
 * digits are 0 through 9, a through f, and A through F.
 */
#include <stdio.h>
#include <string.h> // for strlen

bool ishexdigit(int c);
int htoi(char *s, bool *ok);
int tolower(int);

int main(int argc, char *argv[])
{
    bool ok = false;
    printf("0xf = %d\n", htoi("0x4ff", &ok));
    if (!ok) printf("unsuccessful\n");
}

int htoi(char *s, bool *ok) {
    if (strlen(s) >= 2) {
        if ((s[1] == 'x' || s[1] == 'X') && s[0] == '0') {
            s += 2;
        }
    }
    int base = 16;
    int num = 0;
    *ok = true;
    for (; *s && *ok; s++) {
        if (!ishexdigit(*s)) {
            *ok = false;
            continue;
        }
        num *= base;
        if (*s >= '0' && *s <= '9') num += *s - '0';
        else num += tolower(*s) - 'a' + 10;
    }
    return num;
}

bool ishexdigit(int c) {
    return c >= '0' && c <= '9'
        || c >= 'A' && c <= 'F'
        || c >= 'a' && c <= 'f';
}

int tolower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    else return c;
}
