/* Fri Nov 27 01:01:54 AM IST 2026 */
/* By: Tia Nammour */
#ifndef _h_hashmap
#define _h_hashmap
#include <stdlib.h>
#define LINKEDLIST_IMPLEMENTATION
#include "linkedlist.h"
typedef struct {
    int len, cap;
    Node **ptr;
} HashMap;
static HashMap ht;
void init(unsigned int);
void set(int key, Type data);
bool get(int key, Type *out_data);
#endif
#ifdef HASHMAP_IMPLEMENTATION
void init(unsigned int cap) {
    ht.ptr = calloc(cap,sizeof(Node*));
    ht.len = 0, ht.cap = cap;
}
// djb2_hash
#include <stdint.h>
static inline int hash(int data) {
    static const uint32_t GOLDEN_RATIO_PRIME = 2654435761U;
    uint32_t hash_value = (uint32_t)data * GOLDEN_RATIO_PRIME;
    return (int)(hash_value % (uint32_t)ht.cap);
}
void set(int key, Type data) {
    int hashkey = hash(key);
    // printf("hashkey = %d\n", hashkey);
    Node *itr = ht.ptr[hashkey];
    while (itr != 0) {
        if (itr->key == key) {
            itr->data = data;
            return;
        }
        itr = itr->next;
    }
    ht.ptr[hashkey] = pushfront(ht.ptr[hashkey],key,data);
    ++ht.len;
}
bool get(int key, Type *out_data) {
    int hashkey = hash(key);
    Node *itr = ht.ptr[hashkey];
    while(itr != NULL) {
        if (itr->key == key) {
            if (out_data != NULL) *out_data = itr->data;
            return true;
        }
        itr = itr->next;
    }
    return false;
}
#endif
