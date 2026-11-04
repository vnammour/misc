/* Mon Oct 12 07:19:24 PM EDT 2026 */
/* By: vnammour */
#include <stdio.h>
int maxsubarraysum(int *arr, int len, int k) {
    int *p = arr;
    int current;
    for (int i = 0; i < k; i++)
        current += *p++;
    int max = current;
    while (p < arr + len) {
        current += -p[-1] + p[1];
        if (current > max) max = current;
        ++p;
    }
    return max;
}
int main(int argc, char *argv[])
{
    int arr[] = {1,5,4,2,9};
    int len = sizeof(arr)/sizeof(*arr);
    int maxsum = maxsubarraysum(arr,len,3);
    printf("maxsum = %d\n", maxsum);
}
