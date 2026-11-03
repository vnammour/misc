/* Fri Oct 30 03:55:18 PM IST 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
typedef struct Queue {
    int *arr;
    int *h, *t;
    int size;
} Queue;
typedef enum error {none, overflow, underflow} error;
error err = none;
const int SIZE = 32;
void enqueue(Queue *queue, int data) {
    int offset = queue->t - queue->arr + 1;
    if (offset%queue->size == queue->h - queue->arr) err = overflow;
    else {
        *queue->t++ = data;
        if (queue->t >= queue->arr + queue->size) queue->t = queue->arr;
    }
}
int dequeue(Queue *queue) {
    if (queue->h == queue->t) {
        err = underflow;
        return err;
    }
    int data = *queue->h++;
    if (queue->h >= queue->arr + queue->size) queue->h = queue->arr;
    return data;
}
Queue *init(int size) {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->arr = queue->h = queue->t = (int*) malloc(sizeof(int)*SIZE);
    queue->size = SIZE;
    return queue;
}
void errmsg(error err) {
    switch(err) {
    case none: printf("None\n"); break;
    case overflow: printf("Overflow\n"); break;
    case underflow: printf("Underflow\n"); break;
    }
}
int main(int argc, char *argv[])
{
    Queue *q = init(SIZE);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    printf("data = %d\n", dequeue(q));
    printf("data = %d\n", dequeue(q));
    printf("data = %d\n", dequeue(q));
    errmsg(err);
    printf("data = %d\n", dequeue(q));
    errmsg(err);
}
