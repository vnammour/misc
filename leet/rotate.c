/* Sat Oct 31 07:34:11 AM IST 2026 */
/* By: Tia Nammour */
#include <stdio.h>

void reverse(int *arr, int len) {
    int temp;
    for (int i = 0, j = len-1; i < j; i++,j--)
        temp = arr[i], arr[i] = arr[j], arr[j] = temp;
}

void rotate(int *arr, int len, int k) {
    if (k <= 0 || k >= len) return;
    reverse(arr+k,len-k);
    reverse(arr,len);
    reverse(arr + len - k, k);
}
int main(int argc, char *argv[])
{
    int arr[] = {1,2,3,4,5,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    // reverse(arr,len);
    rotate(arr,len,2);
    for (int i = 0; i < len; i++)
        printf("%d%c", arr[i], i == len-1 ? '\n' : ',');
}
