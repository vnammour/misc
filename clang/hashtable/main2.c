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

int main(int argc, char *argv[])
{
    int arr[] = {-1,3,15,3,8,4};
    int len = (int) sizeof(arr)/sizeof(*arr);
    int sum = 7;
    init(16);

    for (int i = 0; i < len; i++) {
        Type index_match_list = pushfront(index_match_list, i, NULL);
        int complement = sum - arr[i];
        if (get(complement,&index_match_list))
            print_index_list(index_match_list,&i);

        set(arr[i],index_match_list);
    }

    for (int i = 0; i < len; i++) {
        if (get(arr[i],&match_list)
    }
    destroy()
}
