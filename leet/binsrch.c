/* Mon Oct 19 01:37:56 PM PDT 2026 */
/* By: vnammour */
#include <stdio.h>
void sort(int *arr, int len) {
    for (int i = 1; i < len; i++)
        for (int j = 0; j < len; j++)
            if (arr[j] > arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i], arr[i] = temp;
            }
}
int binsrch(int *arr, int len, int target) {
    int *low = arr, *high = arr + len;
    while (low < high) {
        int *mid = low + (high -low)/2;
        if (*mid > target) high = mid;
        else if (*mid < target) low = mid;
        else return mid - arr;
    }
    return -1;
}
int main(int argc, char *argv[])
{
    int arr[] = {10,8,3,0,-2,-10};
    int len = sizeof(arr)/sizeof(arr[0]);
    sort(arr,len);
    for (int i = 0; i < len; i++)
        printf("%d%c", arr[i], i == len-1 ? '\n' : ',');
    int srch = binsrch(arr,len,-10);
    printf("index = %d\n", srch);
}
