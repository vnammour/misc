/* Tue Nov 24 02:22:27 AM IST 2026 */
/* By: Tia Nammour */
#include <stdio.h>
// #define Type int
#define HASHTABLE_IMPLEMENTATION
#include "hashtable.h"
#define min(i,j) ( (i) < (j) ? (i) : (j))
#define max(i,j) ((i) > (j) ? (i) : (j))
int main(int argc, char *argv[])
{
    init(10);
    int arr[] = {-1,3,15,3,8,4,2,5};
    int len = sizeof(arr)/sizeof(*arr);
    int sum = 7;
    int index = -1;
    for (int i = 0; i < len; i++) {
        /*if (get(sum - arr[i],&index)) {
            printf("(%d,%d)\n", min(i,index),max(i,index));
        } else set(arr[i],i);*/
        if (!get(sum-arr[i],&index)) set(arr[i],i);
        else printf("(%d,%d)\n", min(i,index),max(i,index));
    }
    // printhashtable();
}
