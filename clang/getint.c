/* Thu Jul 23 11:25:06 AM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <ctype.h>
#define N 10
int getch();
void ungetch(int);

int getint(int *p) {
    int c;
    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    int sign = c == '-' ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            return 0;
        }
    }
    int base = 10;
    for (*p = 0; isdigit(c); *p = *p * base + (c - '0'), c = getch());
    *p *= sign;
    if (c != EOF) ungetch(c);
    return c;
}
// textbook
int getint2(int *p) {
    int c, sign;
    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); // it is not a number
        return 0;
    }
    sign = c == '-' ? -1 : 1;
    if (c == '+' || c == '-') c = getch();
    for (*p = 0; isdigit(c); c = getch())
        *p = 10 * *p + (c - '0');
    *p *= sign;
    if (c != EOF) ungetch(c);
    return c;
}

int main(int argc, char *argv[])
{
    int p[N];
    int c;
    for (int i = 0; i < N && (c = getint(p+i)) != EOF && c != 0; i++)
        printf("p[%d] = %d\n", i, p[i]);
}

int buf[N];
int bufp = 0;
int getch() {
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp < N) buf[bufp++] = c;
    else printf("error: buffer is full\n");
}
