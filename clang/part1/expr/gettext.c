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
    if (isdigit(*s)) {
        while(isdigit(*++s = getch()));
        if (*s != EOF) ungetch(*s);
        *s = '\0';
        return NUMBER;
    }
    *++s = '\0';
    return s[-1];
}

int getop_line(char *line, char *s, int len) {
    static char *p = 0;
    if (p == 0) p = line;
    char *t = s;
    while (isspace(*p)) ++p;
    if (*p == 0) {
        p = 0;
        return EOF;
    }
    if ((*p == '+' || *p == '-') && isdigit(p[1])) *s++ = *p++;
    if (isdigit(*p)) {
        while (isdigit(*p) && s - t < len) *s++ = *p++;
        *s = '\0';
        return NUMBER;
    }
    *s++ = *p++;
    *s = '\0';
    return s[-1];
}

/*#include <string.h>
void test_getop_line() {
    int lim = 512;
    char line[lim];
    int len;
    while ((len = getLine(line,lim)) > 0) {
        char s[len];
        line[strlen(line)-1] = 0; // remove newline
        while (getop_line(line,s,len) != EOF) {
            printf(">%s<\n", s);
        }
    }
    clearerr(stdin);
}

int main(int argc, char *argv[]) {
    test_getop_line();
    char s[100];
    s[0] = '\0';
    int c;
    while ((c = getop(s)) != EOF)
        printf("%c, >%s<\n", c, s);
    s[0] = '\0';
    clearerr(stdin);
    while (getLine(s,100) > 0)
        printf("%s", s);
}*/
