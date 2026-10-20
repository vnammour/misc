/* Mon Oct 19 04:52:55 PM PDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *newNode(int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->next = 0, node->data = data;
    return node;
}
int main(int argc, char *argv[])
{
    Node *head = newNode(0);
    Node *temp = head;
    int i = 0;
    while (++i < 10) {
        head->next = newNode(i);
        head = head->next;
    }
    head->next = temp;
    head = temp;
    Node *h;
    printf("%d->", head->data);
    for (h = head->next; h != head; h = h->next)
        printf("%d->", h->data);
    printf("%d\n", h->data);
}
