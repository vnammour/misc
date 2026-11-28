/* Sat Nov 28 02:48:32 AM IST 2026 */
/* By: Tia Nammour */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int x,y;
} Pair;
#define LL_DATA_TYPE
typedef Pair Type;
#define HASHMAP_IMPLEMENTATION
#include "../hashmap.h"
void printpair(Pair p) {
    printf("(%d,%d)", p.x,p.y);
}
int main(int argc, char *argv[])
{
    int N = 30;
    Pair arr[N];
    init(N);
    for (int i = 0; i < N; i++) {
        Pair p = {rand()%N,rand()%N};
        arr[i] = p;
        set(i,p);
    }
    printhashmap(printpair);
    for (int i = 0; i < N; i++)
        rm(i);
    printhashmap(printpair);

}
