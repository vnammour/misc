/* Thu Jul 23 04:38:21 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

char *alloc(size_t);
void afree(char*);

int main(int argc, char *argv[])
{
    void test();
    test();
}

#define N 1024
static char allocbuf[N];
static char *allocp = allocbuf;

char *alloc(size_t n) {
    char *p = NULL;
    if (allocp + n <= allocbuf + N) {
        p = allocp;
        allocp += n;
    } else printf("cannot allocate %zu bytes\n", n);
    return p;
}

// textbook
// return pointer to n characters
char *alloc_(int n) {
    if (allocbuf + N - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else return 0;
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + N)
        allocp = p;
}

void test() {
    char **pp = (char**) malloc(10 * sizeof(char*));
    int i = 0;
    for (int j = 1; j < N; j*=2) {
        pp[i++] = alloc(j);
        for (char *p = pp[i-1]; p < pp[i-1] + j;++p)
            *p = 'a' + i - 1;
    }
    printf("allocp: %ld\n", allocp - allocbuf);
    for (int k = i-1, j = N/2; k >= 0; k--, j/=2) {
        char *p = pp[k];
        while (p < pp[k] + j) {
            printf("%c", *p);
            p++;
        }
        printf("\n");
        afree(pp[k]);
    }
    printf("allocp: %ld\n", allocp - allocbuf);
    char *p = alloc(N);
    printf("allocp: %ld\n", allocp - allocbuf);
    if (p != NULL) printf("p is valid\n");
}
