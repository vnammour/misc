/* Wed Jul 15 01:49:19 PM IDT 2026 */
/* By: vnammour */
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stddef.h>

typedef struct {
  int *buf, *h, *t;
  size_t cap;
} Queue;

int geterr();
Queue init(size_t cap);
Queue *new(size_t cap);
void resize(Queue *q, size_t cap);
char *errstring(int err);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
int length(Queue *q);
size_t capacity(Queue *q);
int main(int argc, char *argv[]);
#endif
