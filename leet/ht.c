/* Fri Oct 16 10:27:50 AM PDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
typedef enum {
    None,
} ErrCode;
typedef struct Node {
    int data;
    struct Node *next;
} Node;
#define HT_SIZE 100
#define SIZE 1024
Node **init(unsigned size) {
    Node **ht = (Node**) malloc(sizeof(Node*) * size);
    return ht;
}
int hash(int key, int hash_size) {
    long golden_ratio_prime = 2654435761;
    long hash_value = key * golden_ratio_prime;
    hash_value &= 0xffffffff;
    return hash_value % hash_size;
}
int hash4str(char *s, int len, int hash_size) {
    const int lim = 4;
    int key = 0;
    for (int i = 0; i < len && i < lim; i++)
        key += s[i];
    return hash(key,hash_size); 
}
int getLine(char *s, int lim) {
    char *p = s;
    while (--lim > 0 && (*s++ = getchar()) != EOF && s[-1] != '\n');
    if (s[-1] == EOF) --s;
    *s = '\0';
    return s - p;
}
void readin(Node **ht, int ht_size, int *arr, int len) {
    // for each entry in arr:
    // (key,data) = (arr[i],i)
    for (int i = 0; i < len; i++) {
        int key = hash(arr[i],ht_size);
        Node *node = (Node*) malloc(sizeof(Node));
        node->data = i, node->next = 0;
        Node *prev = 0, *nxt = ht[key];
        for (; nxt != 0; prev = nxt, nxt = nxt->next);
        if (prev == 0) ht[key] = node;
        else prev->next = node;
    }
}
void printlist(Node *n) {
    while (n != 0) {
        printf("%d->", n->data);
        n = n->next;
    }
    printf("%p\n", n);
}
void printtable(Node **ht, int ht_size) {
    for (int i = 0; i < ht_size; i++) {
        printlist(ht[i]);
    }
}
// If I want to mark a node as processed, I can set it's data
// index value to -1, since no valid array index is less than zero.
// Let's process each pair only once
int main(int argc, char *argv[])
{
    /*char *s = (char*) malloc(256);
    int len = 0;
    while ((len = getLine(s,256)) != 0)
        printf("hash = %d\n", hash4str(s,len,HT_SIZE));*/
    int arr[] = {7,0,1,3,-2,4,5};
    int len = sizeof(arr)/sizeof(*arr);
    Node **ht = init(HT_SIZE);
    readin(ht,HT_SIZE,arr,len);
    // printtable(ht,HT_SIZE);

    // Getting index pairs. Will use one node to store each index,
    // but final output has to have an even number of nodes.
    int target_sum = 5;
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->next = 0;
    Node *head = temp;
    for (int i = 0; i < len; i++) {
        int key = hash(target_sum - arr[i],HT_SIZE);
        Node *node;
        for (node = ht[key]; node != 0; node = node->next) {
            if (node->data >= 0 && target_sum == arr[i] + arr[node->data]) {
                Node *n1 = (Node*) malloc(sizeof(Node));
                Node *n2 = (Node*) malloc(sizeof(Node));
                n1->data = i, n1->next = n2;
                n2->data = node->data, n2->next = 0;
                temp->next = n1;
                temp = n2;
                // mark as processed.
                for (Node *n = ht[hash(arr[i],HT_SIZE)]; n != 0; n = n->next)
                    if (n->data == i) n->data = -1;
            }
        }
    }
    temp = head;
    head = head->next;
    free(temp);
    printlist(head);
}
