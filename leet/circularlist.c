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
void *circularlist(Node *zero, int start, int size) {
    Node *temp = zero;
    for (int i = start; i < size; i++) {
        temp->next = newNode(i);
        temp = temp->next;
    }
    temp->next = zero;
}
void printlist(Node *head) {
    while (head != 0) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("%p\n", head);
}
int main(int argc, char *argv[])
{
    // middle of a linked list
    {
        Node *head = newNode(0);
        Node *t = head;
        for (int i = 1; i < 7; i++) {
            t->next = newNode(i);
            t = t->next;
        }
        printlist(head);
        if (head != 0) {
            Node *slow, *fast;
            for (slow = head, fast = head; fast != 0 && fast->next != 0;
                    slow = slow->next, fast = fast->next->next);
            printf("%d\n", slow->data);
        }
    }
    // circular list
    {
	    Node *zero = newNode(0);
	    circularlist(zero,1,3);
	    Node *node = newNode(-4);
	    Node *h = node;
	    for (int i = -3; i <0; i++) {
	        node->next = newNode(i);
	        node = node->next;
	    }
	    node->next = zero;
	    Node *t;
	    for (t = h; t != zero->next; t = t->next)
	        printf("%d->", t->data);
	    for (t = zero->next; t != zero; t = t->next)
	        printf("%d->", t->data);
        printf("%d\n", t->data);
    }
}
