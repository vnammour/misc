/* Tue Nov  3 03:59:21 PM IST 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
/*typedef struct point {
    int x, y;
}point;*/
typedef enum {none = 0, underflow = 1, overflow = 2} errcode;
typedef int Type;
typedef struct Node {
    Type data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
} Queue;

errcode err = none;

void enqueue(Queue *q, Type data) {
    if (q == 0) return;
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    Node *prev = 0;
    for (Node *nxt = q->head; nxt != 0; prev = nxt, nxt = nxt->next);
    if (prev != 0) prev->next = node;
    else q->head = node;
}

Type dequeue(Queue *q) {
    Type zero = 0;
    if (q == 0 || q->head == 0) {
        err = underflow;
        return zero;
    }
    Type data = q->head->data;
    Node *temp = q->head;
    q->head = q->head->next;
    temp->next = 0;
    free(temp);
    return data;
}

bool isempty(Queue *q) {
    return (q == 0 || q->head == 0);
}

/*void testqueue() {
    Queue *q;
    q = (Queue*) malloc(sizeof(Queue));
    q->head = 0;
    for (int i = 0; i < 10; i++) enqueue(q,i);
    while (!isempty(q)) {
        Type value = dequeue(q);
        printf("%d\n", value);
    }
    printf("isempty = %d\n", isempty(q));
}*/

int main(int argc, char *argv[])
{
}
