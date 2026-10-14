/* Mon Oct 12 07:37:11 PM EDT 2026 */
/* By: vnammour */
#include <stdio.h>
int maxprofit(int *arr, int len) {
    int *p = arr, *q = arr;
    int maxdiff = 0;
    int currentdiff = 0;
    while (q < arr + len) {
        if (*p >= *q) p = q;
        else if (*p < *q) {
            currentdiff = *q - *p;
            if (currentdiff > maxdiff) maxdiff = currentdiff;
        }
        ++q;
    }
    return maxdiff;
}
int main(int argc, char *argv[])
{
    int arr[] = {7,1,5,3,6};
    int len = sizeof(arr)/sizeof(*arr);
    int maxp = maxprofit(arr,len);
    printf("max profit = %d\n", maxp);
}
