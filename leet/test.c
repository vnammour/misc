/* Wed Sep 30 11:29:59 AM CDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool ispalindrome(char *s) {
    int len = strlen(s);
    char *p = s, *q = s+len-1;
    while (p < q)
        if (*p++ != *q--) return false;
    return true;
}
int abs(int n) {
    return n < 0 ? n * -1 : n;
}
int *squares(int *nums, int len) {
    int *sq = (int*) malloc(sizeof(int) * len);
    int *p = nums, *q = nums + len - 1;
    while (p <= q) {
        if (abs(*p) > abs(*q))
            *sq++ = *q * *q;
        else *sq++ = *p * *p;
        p++,q--;
    }
    return sq;
}
int main(int argc, char *argv[])
{
    int arr[] = {4,6,32};
    int len = sizeof(arr)/sizeof(arr[0]);
    int sum[len];
    sum[0] = arr[0];
    for (int i = 1; i < len; i++)
        sum[i] += sum[i-1] + arr[i];
    for (int i = 0; i < len; i++)
        printf("sum[%d] = %d\n", i, sum[i]);
    for (int i = 1; i < len; i++)
        arr[i] = arr[i-1] + arr[i];
    for (int i = 0; i < len; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
    char *s = "word";
    printf("ispalindrome(s) = %d\n", ispalindrome(s));
    int nums[] = {-4,-1,0,3,10};
    int *sq = squares(nums,sizeof(nums)/sizeof(nums[0]));
    for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++)
        printf("sq[%d] = %d\n", i,sq[i]);
}
