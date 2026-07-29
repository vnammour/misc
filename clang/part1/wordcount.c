/* Sun Jun 21 02:06:04 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stddef.h> // for ssize_t
ssize_t getLine(char *s, int size);
bool isDigit(int c);
void inputcount();
int main(int argc, char *argv[])
{
    inputcount();
    return 0;
}

ssize_t getLine(char *s, int size) {
    char *p = s;
    for (int i = 0; i < size-1 && (*p = getchar()) != EOF && *p != '\n'; i++, p++);
    int temp = *p;
    if (*p == '\n') ++p;
    *p = '\0';
    if (temp == EOF) return temp;
    return p - s;
}

void inputcount() {
    int c, i, nwhite, nother, ndigit[10];
    nwhite = nother = 0;
    for (i = 0; i < 10; i++) ndigit[i] = 0;
    while ((c = getchar()) != EOF) {
        switch(c) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            ndigit[c-'0']++;
            break;
        case ' ': case '\t': case '\n': nwhite++; break;
        default: nother++; break;
        }
    }
    printf("digits = ");
    for (i = 0; i < 10; i++) printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}

bool isDigit(int c) {
    return c - '0' >= 0 && c - '0' <= 9;
}
