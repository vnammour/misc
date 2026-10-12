/* Fri Oct  2 12:40:07 PM CDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
void reverse(int *p, int len) {
    int temp, *q = p + len - 1;
    while (p < q) {
        temp = *p;
        *p++ = *q, *q-- = temp;
    }
}
int abs(int n) {
    return n < 0 ? n * -1 : n;
}
int *squares(int *p, int len) {
    int *results = (int*) malloc(sizeof(int) * len);
    int *t = results;
    int *q = p + len - 1;
    while (p <= q)
        if (abs(*p) < abs(*q))
            *t++ = *q * *q--;
        else *t++ = *p * *p++;
    reverse(results,len);
    return results;
}
int main(int argc, char *argv[])
{
    // Squares of array elements
    int arr[] = {-4,-1,0,3,10};
    int len = sizeof(arr)/sizeof(arr[0]);
    int *results = squares(arr,len);
    for (int i = 0; i < len; i++)
        printf("%d%c", results[i], i == len-1 ? '\n' : ',');
}
