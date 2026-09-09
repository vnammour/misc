/* Wed Sep  2 02:02:54 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node {
    int data;
    Node *next;
};
Node *addtofront(Node *head, int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data, node->next = head;
    head = node;
    return head;
}
Node *addtoback(Node *head, int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data, node->next = 0;
    if (head == 0) return node;
    Node *prev = head, *next = head->next;
    for (; next != 0; prev = next, next = next->next);
    prev->next = node;
    return head;
}
void printlist(Node *head) {
    for (; head != 0; head = head->next)
        printf("%d->", head->data);
    printf("nil\n");
}
int main(int argc, char *argv[])
{
    Node *head = 0;
    for (int i = 0; i < 10; i++)
        head = addtofront(head, i);
    printlist(head);
    for (int i = 10; i < 20; i++)
        head = addtoback(head, i);
    printlist(head);
}
