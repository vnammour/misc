/* Thu Nov 26 10:50:28 AM IST 2026 */
/* By: vnammour */
#ifndef _h_linkedlist
#define _h_linkedlist
#ifndef LL_DATA_TYPE
typedef int Type;
#endif
typedef struct Node {
    int key;
    Type data;
    struct Node *next;
} Node;
Node *pushfront(Node *head, int key, Type data);
Node *pushback(Node *head, int key, Type data);
bool pluck(Node **head, int key, Type *out_data);
void freelist(Node **head, void (*freetype)(Type data));
void printlist(Node *head, void (*printdata)(Type data));
#endif
#ifdef LINKEDLIST_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
Node *pushfront(Node *head, int key, Type data) {
    Node *n = (Node*) malloc(sizeof(Node));
    n->key = key, n->data = data, n->next = head;
    return n;
}
Node *pushback(Node *head, int key, Type data) {
    Node *n = (Node*) malloc(sizeof(Node));
    n->key = key, n->data = data, n->next = NULL;
    Node *prev = NULL, *next = head;
    for (; next != NULL; prev = next, next = next->next);
    if (prev == NULL) return n;
    prev->next = n;
    return head;
}
bool pluck(Node **head, int key, Type *out_data) {
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
void freelist(Node **head, void (*freetype)(Type data)) {
    while (*head != NULL) {
        Node *next = (*head)->next;
        if (freetype != NULL) freetype((*head)->data);
        free(*head);
        *head = next;
    }
}
void printlist(Node *head, void (*printdata)(Type data)) {
    while (head != NULL) {
        printf("[%d: ", head->key);
        if (printdata != NULL) printdata(head->data);
        else printf("%d->", head->data);
        printf("]->");
        head = head->next;
    }
    printf("//\n");
}
#endif
/*
 * if data is composite, I will need operators ==, <, >, <=, >= defined for data type.
 * Hence I choose to include "int key" as a member of the Node struct to ease such
 * search operations.
 */
