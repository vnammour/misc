/* Mon Oct 12 02:27:44 PM EDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
void bubblesort(int *p, int len) {
}
void selectionsort(int *p, int len) {
}
void insertionsort(int *p, int len) {
    for (int i = 1; i < len; i++)
        for (int j = 0; j < i; j++)
            if (p[j] > p[i]) {
                int temp = p[j];
                p[j] = p[i], p[i] = temp;
            }
}
int abs(int n) {
    return n >= 0 ? n : n * -1;
}
void reverse(int *arr, int len) {
    int *p = arr, *q = arr + len - 1;
    while (p <= q) {
        int temp = *q;
        *q-- = *p, *p++ = temp;
    }
}
/*
 * Given an integer array sorted in non-decreasing order, return an
 * array of the squares of each number sorted in non-decreasing order.
 */
int *squares_sorted_array(int *arr, int len) {
    int *p = arr, *q = arr + len - 1;
    int *t = (int*) malloc(sizeof(int)*len);
    t += len;
    while (p <= q) {
        if (abs(*p) < abs(*q))
            *--t = *q * *q--;
        else *--t = *p * *p++;
    }
    return t;
}
int *squares_sorted_array2(int *arr, int len) {
    int *p = arr, *q = arr + len - 1;
    int *t = (int*) malloc(sizeof(int)*len);
    while (p <= q) {
        if (abs(*p) > abs(*q))
            *t++ = *p * *p++;
        else *t++ = *q * *q--;
    }
    t -= len;
    reverse(t,len);
    return t;
}
int main(int argc, char *argv[])
{
    // int arr[] = {9,0,2,-3,-1,-2,1};
    int arr[] = {10,0,3,-1,-4};
    int len = sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr,len);
    int *squares = squares_sorted_array2(arr,len);
    for (int i = 0; i < len; i++)
        printf("%d%c", arr[i], i == len-1 ? '\n' : ',');
    for (int i = 0; i < len; i++)
        printf("%d%c", squares[i], i == len-1 ? '\n' : ',');
    free(squares);
}
