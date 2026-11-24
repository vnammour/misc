/* Tue Nov 24 02:22:27 AM IST 2026 */
/* By: Tia Nammour */
#include <stdio.h>
#define Type int
#define HASHTABLE_IMPLEMENTATION
#include "hashtable.h"
int main(int argc, char *argv[])
{
    init(10);
    int arr[] = {-1,3,15,4,2};
    int len = sizeof(arr)/sizeof(*arr);
    for (int i = 0; i < len; i++)
        set(arr[i],i);
    int sum = 7;
    printhashtable();
    /*for (int i = 0; i < len; i++) {
        int index = get(sum - arr[i]);
        if (sum - arr[index] == arr[i]) {
            printf("(%d,%d)\n", i, index);
        }
    }*/
}
