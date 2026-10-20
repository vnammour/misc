/* Wed Oct 14 10:06:50 PM PDT 2026 */
/* By: vnammour */
#include <stdio.h>
void sort(int *arr, int len) {
    for (int i = 0; i < len; i++)
        for (int j = i+1; j < len; j++)
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j], arr[j] = temp;
            }
}
int sum3(int *arr, int len, int targetsum) {
    sort(arr,len);
    for (int i = 0; i < len; i++) {
        int *p = arr+i+1, *q = arr+len-1;
        while (p < q) {
            if (targetsum < arr[i] + *p + *q) --q;
            else if (targetsum > arr[i] + *p + *q) ++p;
            else {
                printf("@ %d, %d, %d\n", i,p-arr,q-arr);
                break;
            }
        }
    }
}
int main(int argc, char *argv[])
{
    int arr[] = {3,2,1,0,-3,-2,-1,1,1,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    sort(arr,len);
    for (int i = 0; i < len; i++)
        printf("%d%c", arr[i], i == len-1 ? '\n' : ',');
    sum3(arr,len,0);
}
