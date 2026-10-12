/* Fri Oct  2 01:54:05 PM CDT 2026 */
/* By: vnammour */
#include <stdio.h>
// const unsigned intsize = 32 << ((~(unsigned)0) >> 63);
// const int minint = -1 << (intsize-1);
int maxsubarray(int *p, int len, int k) {
    if (p == 0 || len < k) return 0;
    int *q = p + len;
    int maxsum = 0;
    // get the first window sum
    for (int *t = p; t < p + k; t++)
        maxsum += *t;
    int currentsum = maxsum;
    while ( ++p + k <= q) {
        currentsum += -p[-1] + p[k-1];
        maxsum = currentsum > maxsum ? currentsum : maxsum;
    }
    return maxsum;
}
/*int maxsubarray2(int *p, int len, int k) {
    if (p == 0 || len < k) return 0;
    int *q = p + len;
    int maxsum, currentsum;
    currentsum = maxsum = minint;
    while (p + k <= q) {
        if (currentsum != minint)
            currentsum += -p[-1] + p[k-1];
        else {
            currentsum = 0;
            for (int *t = p; t < p + k; t++)
                currentsum += *t;
        }
        if (currentsum > maxsum) maxsum = currentsum;
        ++p;
    }
    return maxsum;
}*/
int main(int argc, char *argv[])
{
    int arr[] = {1,5,4,2,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int maxsum = maxsubarray(arr,len,k);
    printf("maxsum for k=%d = %d\n", k, maxsum);
}
