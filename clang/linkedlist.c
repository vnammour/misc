/* Tue Jun 30 08:01:25 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
} Node;
#define null NULL
Node *pushback(Node *head, int data);
Node *pushbacknode(Node *head, Node *node);
void print(Node *node);
Node *sort(Node *node);
int main(int argc, char *argv[])
{
    int data[] = {1,2,3,4,5,6,7};
    int length = sizeof(data)/sizeof(data[0]);
    Node *head;
    for (int i = length-1; i >= 0; i--) {
        head = pushback(head,data[i]);
    }
    print(head);
    head = sort(head);
    print(head);
    // testing pushbacknode
    /*Node *h = (Node*) malloc(sizeof(Node));
    h->next = null;
    while (head != null) {
        printf("pushing back %d\n", head->data);
        Node *temp = head->next;
        head->next = null;
        h = pushbacknode(h,head);
        head = temp;
    }
    Node *temp = h->next;
    h->next = null;
    free(h);
    h = temp;
    print(h);*/
    // end test
}

Node *pushback(Node *head, int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->next = null, node->data = data;
    Node *p = null,*q = null;
    for (q = head; q != null; p = q, q = q->next);
    if (p == null) return node;
    p->next = node;
    return head;
}

Node *pushbacknode(Node *head, Node *node) {
    Node *q, *p = null;
    for (q = head; q != null; p = q, q = q->next);
    if (p == null) return node;
    p->next = node;
    return head;
}

Node *sort(Node *node) {
    if (node == null) return node;
    Node *head = (Node*) malloc(sizeof(Node));
    head->next = node;
    Node *h = (Node*) malloc(sizeof(Node));
    // selection sort
    while(true) {
        if (head->next == null) break;
        Node *t = head, *p = head->next;
        for (Node *px = head, *x = head->next; x != null; px = x, x = x->next) {
            if (p->data >= x->data) {
                p = x;
                t = px;
            }
        }
        t->next = p->next;
        p->next = null;
        h = pushbacknode(h,p);
    }
    head->next = null;
    free(head);
    Node *temp = h;
    h = h->next;
    free(temp);
    return h;
}

void print(Node *node) {
    while (node != null) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("nil\n");
}
