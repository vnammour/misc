/* Mon Oct 12 01:39:20 PM EDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
int* prefixsum(int *arr, int len) {
    if (arr == 0) return arr;
    int *p = (int*) malloc(sizeof(int)*len);
    *p++ = arr[0];
    for (int i = 1; i < len; i++)
        *p++ = p[-1] + arr[i];
    return p - len;
}
int main(int argc, char *argv[])
{
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    int *ps = prefixsum(arr,len);
    for (int i = 0; i < len; i++)
        printf("%d%c", ps[i], i == len-1 ? '\n' : ',');
    free(ps);
}
