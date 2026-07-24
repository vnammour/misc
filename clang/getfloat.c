/* Thu Jul 23 01:22:00 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <ctype.h>
#define N 10
int getch();
void ungetch(int);

int getfloat(float *p) {
    int c;
    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }
    int sign = c == '-' ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c) && c != '.') {
            ungetch(c);
            return 0;
        }
    }
    float base = 10, pow = 10;
    for (*p = 0; isdigit(c); *p = *p * base + (c - '0'), c = getch());
    if (c == '.')
        for (c = getch(); isdigit(c); *p += (c - '0')/pow, pow *= base, c = getch());
    *p *= sign;
    if (c != EOF && c != '.') ungetch(c);
    if (c == '.') return 0;
    return c;
}

int main(int argc, char *argv[])
{
    int c;
    float p[N];
    for (int i = 0; i < N && (c = getfloat(p + i)) != EOF && c != 0; ++i)
        printf("p[%d] = %.6f\n", i, p[i]);
}

int buf[N];
int *bufp = buf;
int getch() {
    // return getchar();
    return bufp > buf ? *--bufp : getchar();
}
void ungetch(int c) {
    // ungetc(c,stdin);
    if (bufp < buf + N) *bufp++ = c;
    else printf("buffer overflow\n");
}
