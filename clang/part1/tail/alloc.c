/* Mon Jul 27 03:47:49 PM IDT 2026 */
/* By: vnammour */
#define ALLOCSIZE  65536
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    // if (allocp + n <= allocbuf + ALLOCSIZE)
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else return 0;
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int memoryat() {
    return allocp - allocbuf;
}
