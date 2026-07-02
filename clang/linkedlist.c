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
size_t size(Node *head);
Node *reverse(Node*);
Node *merge(Node *l1, Node *l2);
int main(int argc, char *argv[])
{
    int data[] = {1,2,3,4,5,6,7};
    int length = sizeof(data)/sizeof(data[0]);
    Node *head = null;
    for (int i = length-1; i >= 0; i--) {
        head = pushback(head,data[i]);
    }
    print(head);
    head = sort(head);
    print(head);
    printf("# of nodes = %d\n", size(head));
    head = reverse(head);
    print(head);
    Node *l1 = head;
    {
        Node *l2 = null;
        for (int i = 0; i <7; i++)
            l2 = pushback(l2,i+8);
        l2 = merge(l1,l2);
        print(l2);
    }
    // free memory
    while (head != null) {
        Node *temp = head->next;
        head->next = null;
        free(head);
        head = temp;
    }
    print(head);
    head = reverse(head);
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

size_t size(Node *head) {
    size_t count = 0;
    for (; head != null; count++, head = head->next);
    return count;
}

Node *reverse(Node *head) {
    if (head == null) return head;
    Node *x,*y;
    x = head;
    y = head->next;
    while (y != null) {
        Node *z = y->next;
        y->next = x;
        x = y, y = z;
    }
    head->next = null;
    return x;
}

Node *merge(Node *l1, Node *l2) {
    if (l1 == null) return l2;
    else if (l2 == null) return l1;
    Node *p = l1, *q = l2;
    if (p->data > q->data) p = q, q = p;
    Node *t = p, *h = p;
    // p = p->next;
    while (p != null && q != null) {
        if (p->data <= q->data) {
            t = p;
            p = p->next;
        } else {
            t->next = q;
            if (p->data > q->data) {
                p = q;
                q = p;
            }
        }
    }
    t->next = q;
    return h;
}

Node *pushback(Node *head, int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->next = null, node->data = data;
    Node *p = null,*q;
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

Node *pushfront(Node *head, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->next = null, node->data = data;
    if (head == null) return node;
    node->next = head->next;
    head->next = node;
    return head;
}

Node *pushfrontnode(Node *head, Node *node) {
    if (head == null) return node;
    else if (node == null) return head;
    node->next = head->next;
    head->next = node;
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
