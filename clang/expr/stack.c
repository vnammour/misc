/* Sun Jul 26 01:51:38 PM IDT 2026 */
/* By: vnammour */
#define LEN 512
static int buf[LEN];
static int *p = buf;

int pop() {
    if (p > buf) return *--p;
    else return 0;
}

void push(int x) {
    if (p < buf + LEN) *p++ = x;
}

int isempty() {
    return p == buf;
}
