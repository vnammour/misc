/* Wed Nov 25 12:27:14 AM IST 2026 */
/* By: Tia Nammour */
#include <stdio.h>
#define LL_VALUE_TYPE
typedef struct Node* Type;
#define HASHTABLE_IMPLEMENTATION
#include "hashtable.h"

static void print_index_list(Node *list, void *ctx) {
    int index = *(int*)ctx;
    while (list != NULL) {
        printf("(%d,%d)\n", list->key, index);
        list = list->next;
    }
}

int main(int argc, char *argv[]) {
    int arr[] = {-1,3,15,3,8,4};
    int len = (int) sizeof(arr)/sizeof(*arr);
    int sum = 7;
    init(len);
    for (int i = 0; i < len; i++) {
        Node* match_list = 0;
        int comp = sum - arr[i];
        if (get(comp,&match_list)) {
            print_index_list(match_list,&i);
        }

        if (get(arr[i],&match_list)) {
            match_list = pushback(match_list,i,0);
        } else {
            Node* match_list = pushfront(0,i,0);
            set(arr[i],match_list);
        }
    }
    printhashtable();
    for (int i = 0; i < len; i++) {
        Node *head = 0;
        if (get(arr[i],&head)) {
            // printf("vjn: main: removing key %d\n", arr[i]);
            freelist(head);
            rm(arr[i]);
        }
    }
    printhashtable();
    destroy();
}
