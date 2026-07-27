/* Sun Jul 26 01:51:38 PM IDT 2026 */
/* By: vnammour */
#define LEN 512
static int buf[LEN];
static int *bufp = buf;

int pop() {
    if (bufp > buf) return *--bufp;
    else return 0;
}

void push(int x) {
    if (bufp < buf + LEN) *bufp++ = x;
}

int isempty() {
    return bufp == buf;
}

/*#include <stdio.h>
void printstack() {
    for (int *p = buf; p < bufp; p++)
        printf("buf[%d] = %d\n", p-buf,*p);
}*/
