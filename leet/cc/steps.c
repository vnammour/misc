/* Fri Nov 13 10:22:30 PM IST 2026 */
/* By: Tia Nammour */
#include <stdio.h>
int main(int argc, char *argv[])
{
    const int N = 16;
    char seta[N];
    char setb[N];
    char k = 2;
    for (int i = 0; i < N; i++) {
        seta[i] = (2<<3) + i;
        setb[i] = k;
        k += 4;
        printf("i = %3d: %.8b\t%.8b\n", i, seta[i], setb[i]);
    }
}
