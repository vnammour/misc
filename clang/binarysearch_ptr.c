/* Sun Jun 21 12:50:18 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
int binarysearch(int x, int *p, int len);
void sort(int *arr, int len);
int main(int argc, char *argv[])
{
    int arr[] = {10,-1,5,-8,2,0,-12};
    int sz = sizeof(arr)/sizeof(int);
    printf("%d\n", sz);
    sort(arr,sz);
    for (int i = 0; i < sz; i++) printf("%d, ", arr[i]);
    int index = binarysearch(-12,arr,sz);
    printf("\nindex = %d\n", index);
}
int binarysearch(int x, int *arr, int len) {
    if (arr == 0) return -1;
    int *p,*q, *mid;
    p = arr, q = arr + len;
    while (p <= q) {
        mid = p + (q - p)/2;
        if (x == *mid) return mid-arr;
        if (x > *mid) p = mid + 1;
        else q = mid - 1;
    }
    return -1;
}
void sort(int *arr, int len) {
    if (arr == 0) return;
    for (int i = 1; i < len; i++) {
        for (int j = i-1; j >=0; j--) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
