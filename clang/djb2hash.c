/* Thu Oct  8 12:18:53 PM PDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
// #include <stddef.h>
// #include <ctype.h>
typedef struct Node {
    int value;
    struct Node *next;
} Node;

/*int djb2_hash(char *p, int len, int hash_size) {
    // choose a large prime number
    int hash_value = 5381;
    // Iterate through each character of the string
    char *q = p + len;
    while (p < q) {
        hash_value = ((hash_value << 5) + hash_value) + *p;
        hash_value &= 0xffffffff;
        p++;
    }
    return hash_value % hash_size;
}*/
int djb2_hash(int key, int hash_size) {
    // 1. Use a large prime/constant fraction based on the Golden Ratio
    // (2^32 * (sqrt(5)-1)/2)
    // This constant maximizes bit dispersion across a 32-bit unsigned
    // integer space.
    long GOLDEN_RATIO_PRIME = 2654435761;
    // 2. Multiply the key by the constant
    // This overflows the integer space intentionally, shuffling the bits
    // thoroughly.
    long hash_value = key * GOLDEN_RATIO_PRIME;
    // 3. Mask to simulate standard 32-bit unsigned integer behavior.
    hash_value &= 0xffffffff;
    return hash_value % hash_size;
}
void printlist(Node *head) {
    while (head != 0) {
        printf("%d->", head->value);
        head = head->next;
    }
    printf("%p\n", head);
}
void printtable(Node **table, int len) {
    if (table == 0) return;
    for (int i = 0; i < len; i++) {
        printf("HashTable Key %d:\n", i);
        printlist(table[i]);
    }
}

void releasemem_list(Node *node) {
    Node *head = node;
    while (node != 0) {
        Node *temp = node->next;
        free(node);
        node = temp;
    }
    head = 0;
}

void releasemem(Node **table, int len) {
    Node **p = table;
    while (p < table + len) {
        Node *t = *p++;
        while (t != 0) {
            Node *q = t->next;
            free(t);
            t = q;
        }
        t = 0;
    }
    free(table);
    table = 0;
}

Node **buildtable(int *p, int len) {
    Node **ht = (Node**) malloc(sizeof(Node*)*len);
    for (int i = 0; i < len; i++) {
        // key is the index in the hash table (associative array)
        // based on the value p[i]
        int key = djb2_hash(p[i],len);
        // printf("arr[%d] = %d has key %d\n", i, p[i], key);
        Node *node = (Node*) malloc(sizeof(Node));
        node->value = i, node->next = 0;
        if (ht[key] == 0)
            ht[key] = node;
        else {
            Node *prev, *nxt;
            for (prev = 0, nxt = ht[key]; nxt != 0; prev = nxt, nxt = nxt->next);
            prev->next = node;
        }
    }
    return ht;
}

Node *getindices(Node **ht, int *arr, int len, int sum) {
    Node *head = (Node*) malloc(sizeof(Node));
    head->value = -1, head->next = 0;
    Node *res = head;
    for (int i = 0; i < len; i++) {
        int key = djb2_hash(sum - arr[i], len);
        for (Node *n = ht[key]; n != 0; n = n->next) {
            if (sum - arr[n->value] == arr[i]) {
                res->next = (Node*) malloc(sizeof(Node));
                res->next->value = i, res->next->next = 0;
                res = res->next;
            }
        }
    }
    Node *temp = head->next;
    free(head);
    if (temp != 0) head = temp;
    return head;
}

int main(int argc, char *argv[])
{
    int arr[] = {2, 3, 7, 6, 11, 15};
    int len = sizeof(arr)/sizeof(arr[0]);
    Node **ht = buildtable(arr,len);
    // printtable(ht,len);
    int sum = 9;
    Node *indices = getindices(ht,arr,len,sum);
    printlist(indices);
    releasemem(ht,len);
    releasemem_list(indices);
}
