/* Sun Jul 26 01:58:36 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#define LEN 10
#define NUMBER 0 /* signal that a number was found */
static char buf[LEN];
static char *bufp = buf;
int getch() {
    return bufp > buf ? *--bufp : getchar();
}
void ungetch(int c) {
    if (bufp < buf + LEN) *bufp++ = c;
}

ptrdiff_t getLine(char *s, int lim) {
    int c;
    char *p = s;
    while (--lim > 0 && (c = *s++ = getchar()) != EOF && c != '\n');
    if (c == EOF) --s;
    *s = '\0';
    return s - p;
}

int getop(char *s) {
    while (isspace(*s = getch()));
    if (*s == EOF) return *s;
    int c = 1;
    if (isdigit(*s)) {
        c = NUMBER;
        while(isdigit(*s++ = getch()));
        --s;
    } else if (*s != EOF) ungetch(*s);
    c = c != NUMBER ? *s : NUMBER;
    if (*s == EOF) --s;
    *++s = '\0';
    return c;
}
