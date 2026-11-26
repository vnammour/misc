/* Thu Nov 26 12:54:38 AM IST 2026 */
/* By: Tia Nammour */
#include <stdio.h>
#include <stdlib.h>
#define LL_VALUE_TYPE
typedef struct Node* Type;
#define HASHTABLE_IMPLEMENTATION
#include "hashtable.h"
/*
void init(int cap);
void destroy();
void set(int key, Type value);
bool get(int key, Type *out_value);
#define contains(key) get(key,NULL)
bool rm(int key);
#define del(key) rm(key)
void printhashtable();
*/
int main(int argc, char *argv[])
{
    int max = 10000;
    int arr[max];
    init(100);
    for (int i = 0; i < max; i++) {
        Node *h = 0;
        if (get(arr[i],&h)) {
            h = pushfront(h,i,0);
        } else {
            h = pushfront(h,i,0);
            set(arr[i],h);
        }
    }
    printhashtable();
    Node *h = 0;
    for (int i = 0; i < max; i++) {
        if (get(arr[i],&h)) {
            freelist(h);
            rm(arr[i]);
        }
    }
    printhashtable();
    destroy();
}
