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
        Type match_list = 0;//pushfront(0,i,0);
        // Type ptr = match_list;
        int comp = sum - arr[i];
        if (get(comp,&match_list)) {
            print_index_list(match_list,&i);
        }

        if (get(arr[i],&match_list)) {
            // free(ptr);
            match_list = pushback(match_list,i,0);
        } else {
            set(arr[i],match_list);
        }
    }
    /*Type dummy = pushback(0,0,0);
    for (int i = 0; i < len; i++) {
        get(arr[i],&dummy);
        freelist(dummy);
        rm(arr[i]);
    }*/
}

int test() {
    int arr[] = {-1,3,15,3,8,4};
    int len = (int) sizeof(arr)/sizeof(*arr);
    int sum = 7;
    init(16);

    for (int i = 0; i < len; i++) {
        Type index_match_list = pushfront(0,i,0);
        Type temp = index_match_list;
        if (get(arr[i],&index_match_list)) {
            // printf("are both lists same memory? %d\n", index_match_list == temp);
            if (index_match_list->key != i) {
                index_match_list = pushfront(index_match_list,i,0);
                printlist(index_match_list);
                // print_index_list(index_match_list,&i);
            }
            free(temp);
            continue;
        }

        set(arr[i],index_match_list);

    }
    destroy();
}
