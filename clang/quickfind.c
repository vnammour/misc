/* Sun Jul 12 07:32:14 PM IDT 2026 */
/* By: vnammour */
/*
 * Rule of Thumb: Never put a \n at the end of a scanf format string unless you have
 * a highly specific reason to force the user to type trailing non-whitespace characters.
 */
#include <stdio.h>
#include <stdlib.h>
#define N 10
void quickfind(int p, int q, int *id, int len);
int main(int argc, char *argv[])
{
    int *id = (int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) id[i] = i;
    int p = -1, q = -1;
    int c = 0;
    while ((c = scanf("%d %d", &p, &q)) == 2) quickfind(p,q,id,N);
}

void quickfind(int p, int q, int *id, int len) {
    if (p >= len || q >= len) return;
    printf(" %d %d\n", p, q);
    if (id[p] == id[q]) return;
    for (int t = id[p], i = 0; i < len; i++)
        if (id[i] == t) id[i] = id[q];
}
