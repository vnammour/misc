/* Sat Jul 25 12:37:36 PM IDT 2026 */
/* By: vnammour */
#include <stddef.h>
#define BUFSIZE 8192
static char allocbuf[BUFSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    if (allocbuf + BUFSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else return 0;
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + BUFSIZE)
        allocp = p;
}

size_t memoryat() {
    return allocp - allocbuf;
}
