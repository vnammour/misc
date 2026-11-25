/* Wed Nov 25 12:27:14 AM IST 2026 */
/* By: Tia Nammour */
#include <stdio.h>
// #define Type Node*
#define LL_VALUE_TYPE
typedef struct Node* Type;
#define HASHTABLE_IMPLEMENTATION
#include "hashtable.h"
int main(int argc, char *argv[])
{
    int arr[] = {1,2,3,4};
    int len = (int) sizeof(arr)/sizeof(*arr);
    init(16);
    Type matches = 0;
    for (int i = 0; i < len; i++) {
        set(i,matches);
    }
    printhashtable();
}
