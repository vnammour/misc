/* Fri Nov 27 01:35:28 AM IST 2026 */
/* By: Tia Nammour */
#include <stdio.h>
#define HASHMAP_IMPLEMENTATION
#define LL_DATA_TYPE
typedef struct Node* Type;
#include "../hashmap.h"
void printnode(Node *node) {
    while (node != 0) {
        printf("%d->", node->key);
        node = node->next;
    }
    printf("//");
}
int main(int argc, char *argv[])
{
    int arr[] = {10,11,12,13,14,10};
    int len = sizeof(arr)/sizeof(*arr);
    init(10);
    for (int i = 0; i < len; i++) {
        Node *node = 0;
        if (get(arr[i],&node))
            node = pushback(node,i,0);
        else {
            node = pushfront(node,i,0);
            set(arr[i],node);
        }
    }
    printhashmap(printnode);
    for (int i = 0; i < len; i++) {
        Node *node = 0;
        if(get(arr[i],&node)) {
            printf("key %d: ", arr[i]);
            printlist(node, 0);
            freelist(&node,0);
            printlist(node,0);
            rm(arr[i]);
        }
    }
    printhashmap(printnode);
    for (int i = 0; i < len; i++) {
        Node *node = 0;
        if (get(arr[i],&node))
            printlist(node,0);
    }
}
