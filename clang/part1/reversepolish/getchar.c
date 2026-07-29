/* Thu Jul 16 06:48:46 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
// #include "stack.h"

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) printf("ungetch: too many characters\n");
    else buf[bufp++] = c;
}
