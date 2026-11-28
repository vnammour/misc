/* Fri Nov 27 08:42:34 PM IST 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#define LL_DATA_TYPE
typedef struct Node* Type;
#define HASHMAP_IMPLEMENTATION
#include "../hashmap.h"
void output(Node *list, int index) {
    while (list != 0 && list->key != index) {
        printf("(%d,%d)%c", index, list->key, list->next == 0 ? '\n' : ',');
        list = list->next;
    }
}
void printnode(Node *list) {
    while (list != 0) {
        printf("%d->",list->key);
        list = list->next;
    }
    printf("//");
}
int main(int argc, char *argv[])
{
    int arr[] = {0,10,11,12,13,10,10,11,22};
    int len = sizeof(arr)/sizeof(*arr);
    init(16);
    int sum = 22;
    for (int i = 0; i < len; i++) {
        int comp = sum - arr[i];
        Node *list = 0;
        if (get(arr[i],&list)) {
            list = pushback(list,i,0);
        } else {
            list = pushfront(list,i,0);
            set(arr[i],list);
        }
        Node *existing = 0;
        if (get(comp,&existing))
            output(existing,i);
    }
    printf("\n");
    printhashmap(printnode);
}
