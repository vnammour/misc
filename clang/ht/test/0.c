/* Fri Nov 27 08:42:34 PM IST 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#define LL_DATA_TYPE
typedef struct Node* Type;
#define HASHMAP_IMPLEMENTATION
#include "../hashmap.h"
void printnode(Node *list) {
    while (list != 0) {
        printf("%d->",list->key);
        list = list->next;
    }
    printf("//");
}
int main(int argc, char *argv[])
{
    int arr[] = {10,11,12,13,10,10,11};
    int len = sizeof(arr)/sizeof(*arr);
    init(16);
    int sum = 22;
    for (int i = 0; i < len; i++) {
        int comp = sum - arr[i];
        Node *existing = 0;
        if (get(comp,&existing)) {
            existing = pushback(existing,i,0);
        } else {
            Node *list=0;
            list = pushfront(list,i,0);
            set(arr[i],list);
        }
    }
    printhashmap(printnode);
}
