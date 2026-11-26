/* Tue Nov 24 01:48:39 AM IST 2026 */
/* By: Tia Nammour */
#ifndef _h_linkedlist
#define _h_linkedlist
#include <stdio.h>
#include <stdlib.h>
// typedef int Type;
#ifndef LL_VALUE_TYPE
typedef int Type;
#endif
typedef struct Node {
    struct Node *next;
    int key;
    Type data;
} Node;
Node *pushfront(Node *head, int key, Type data);
Node *pushback(Node *head, int key, Type data);
void freelist(Node *curr);
bool pluck(Node **node, int key);
void printlist(Node *head);
#endif
#ifdef LINKEDLIST_IMPLEMENTATION
Node *pushfront(Node *head, int key, Type data) {
    Node *n = (Node*) malloc(sizeof(Node));
    n->next = 0, n->data = data, n->key = key;
    if (head == 0) return n;
    n->next = head;
    head = n;
    return head;
}
Node *pushback(Node *head, int key, Type data) {
    Node *n = (Node*) malloc(sizeof(Node));
    n->key = key, n->data = data, n->next = 0;
    if (head == 0) return n;
    Node *prev = head, *next = head->next;
    for (; next != 0; prev = next, next = next->next);
    prev->next = n;
    return head;
}
bool pluck(Node **head, int key) {
    Node **curr = head;
    while (*curr != NULL) {
        if ((*curr)->key == key) {
            Node *target = *curr;
            *curr = (*curr)->next;
            target->next = 0;
            free(target);
            return true;
        }
        curr = &(*curr)->next;
    }
    return false;
}
void freelist(Node *curr) {
    while (curr != 0) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
}
void printlist(Node *head) {
    for (; head != 0; head = head->next)
        printf("%d->",head->key);
    printf("//\n");
}
#endif
