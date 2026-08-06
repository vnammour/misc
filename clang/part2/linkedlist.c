/* Wed Aug  5 02:34:51 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
// Forward declaration
typedef struct Node Node;
// Define the struct body
struct Node {
    int data;
    Node *next;
};

Node *previous(Node *head, Node *n) {
    if (n == 0 || n == head) return 0;
    Node *prev = NULL, *next;
    for (next = head; next != NULL && next != n; prev = next, next = next->next);
    return prev;
}

Node *pushback(Node *head, int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->next = NULL, node->data = data;
    Node *prev, *next;
    for (next = head; next != NULL; prev = next, next = next->next);
    if (prev != NULL) prev->next = node;
    else head = node;
    return head;
}
Node *pushfront(Node *head, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data, node->next = NULL;
    if (head == NULL) return node;
    node->next = head, head = node;
}
Node *reverse(Node *head) {
    if (head == NULL) return 0;
    Node *x = head, *y;
    y = x->next;
    while (y != NULL) {
        Node *z = y->next;
        y->next = x;
        x = y, y = z;
    }
    head->next = NULL, head = x;
}
Node *find(Node *head, int srch) {
    for (; head != NULL && head->data != srch; head = head->next);
    return head;
}
void printlist(Node *head) {
    for (;head != NULL; head = head->next)
        printf("%d->", head->data);
    printf("/-\n");
}
int main(int argc, char *argv[])
{
    printf("sizeof(Node) = %d, sizeof(Node*) = %d\n", sizeof(Node), sizeof(Node*));
    Node *head = pushback(NULL,0);
    for (int i = 1; i < 10; i++)
        head = pushfront(head,i);
    printlist(head);
    head = reverse(head);
    printlist(head);
    Node *five;
    printlist(five = find(head,5));
    Node *pf = previous(head, five);
    printlist(pf);
}
