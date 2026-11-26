/* Tue Nov 24 12:12:04 AM IST 2026 */
/* By: Tia Nammour */
#ifndef _h_hashtable
#define _h_hashtable
#include <stdlib.h>
#include <stdbool.h>
#define LINKEDLIST_IMPLEMENTATION
#include "linkedlist.h"
typedef struct {
    Node **ptr;
    int cap, len;
} HashTable;
static HashTable *ht;
void init(int cap);
void destroy();
void set(int key, Type value);
bool get(int key, Type *out_value);
#define contains(key) get(key,NULL)
bool rm(int key);
#define del(key) rm(key)
void printhashtable();
#endif
#ifdef HASHTABLE_IMPLEMENTATION
void init(int cap) {
    if (ht != 0) return;
    ht = (HashTable*) malloc(sizeof(HashTable));
    ht->cap = cap;
    ht->ptr = (Node**) calloc(cap,sizeof(Node*));
}
static inline void clear() {
    if (ht == 0) return;
    Node* zero = 0;//{};
    for (int i = 0; i < ht->cap; i++)
        ht->ptr[i] = zero;
    ht->len = 0;
}
void destroy() {
    if (ht == 0) return;
    for (int i = 0; i < ht->cap; i++) {
        freelist(ht->ptr[i]);
        ht->ptr[i] = 0;
    }
    free(ht->ptr);
    ht->ptr = 0, ht->cap = 0, ht->len = 0;
    free(ht);
    ht = 0;
}
// djb2_hash
#include <stdint.h>
static inline int hash(int data) {
    static const uint32_t GOLDEN_RATIO_PRIME = 2654435761U;
    uint32_t hash_value = (uint32_t)data * GOLDEN_RATIO_PRIME;
    return (int)(hash_value % (uint32_t)ht->cap);
}
void set(int key, Type data) {
    int hashkey = hash(key);
    Node *p = ht->ptr[hashkey];
    while (p != NULL) {
        if (p->key == key) {
            p->data = data;
            return;
        }
        p = p->next;
    }
    ht->ptr[hashkey] = pushfront(ht->ptr[hashkey],key,data);
    ++ht->len;
    // printf("vjn:set(%d): len = %d\n", hashkey,ht->len);
}
/*
 * Checking if (out_value != NULL) also lets callers use get(key, NULL)
 * as a free contains(key) check if they only care whether the key exists!
 */
bool get(int key, Type *out_value) {
    int hashkey = hash(key);
    for (Node *p = ht->ptr[hashkey]; p != 0; p = p->next) {
        if (p->key == key) {
            if (out_value != NULL) *out_value = p->data;
            return true;
        }
    }
    return false;
}
bool rm(int key) {
    int hashkey = hash(key);
    bool isremoved = pluck(&ht->ptr[hashkey],key);
    // Line below is false since for each key removed
    // length has to be decremented.
    // if (isremoved && ht->ptr[hashkey] == NULL) --ht->len;
    if (isremoved) --ht->len;
    // printf("vjn: rm(%d): len = %d\n", hashkey,ht->len);
    return isremoved;
}
void printhashtable() {
    if (ht == NULL) return;
    printf("cap = %d, len = %d\n", ht->cap, ht->len);
    int i = 0;
    for (Node **p = ht->ptr; p < ht->ptr + ht->cap; p++) {
        printf("p[%d]: %p: ", i, *p);
        printlist(*p);
        ++i;
    }
}
#endif
