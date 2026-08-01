/* Fri Jul 31 10:48:13 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#define LEN 10
static char buf[LEN];
static char *bufp = buf;

char getch(void) {
    return bufp > buf ? *--bufp : getchar();
}

void ungetch(int c) {
    if (bufp < buf + LEN) *bufp++ = c;
}
