/* Sat Jul 25 12:44:54 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stddef.h>
#define N 10
static char buffer[N];
static char *bufp = buffer;

int getch() {
    return bufp > buffer ? *--bufp : getchar();
}
void ungetch(int c) {
    if (bufp < buffer + N) *bufp++ = c;
}

size_t getLine(char *s, size_t lim) {
    int c;
    char *p = s;
    while (--lim > 0 && (*s++ = c = getch()) != EOF && c != '\n');
    if (c == EOF) --s;
    *s = '\0';
    return s - p;
}
