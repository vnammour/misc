/* Tue Jul 14 12:57:24 PM IDT 2026 */
/* By: vnammour */
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *buf, *h, *t;
  size_t cap;
} Queue;

unsigned short err = 0; // 1 - overflow, 2 - underflow, 3 - no memory, 4 - other

Queue init(size_t cap) {
  err = 0;
  int *p = (int *)malloc(sizeof(int) * cap);
  if (p == NULL) {
    err = 3;
    return (Queue){};
  }
  return (Queue){
      .buf = p,
      .h = p,
      .t = p,
      .cap = cap,
  };
}

void enqueue(Queue *q, int data) {
  err = 0;
  if (q == NULL) err = 4;
  int *h = q->h, *t = q->t, *buf = q->buf;
  int cap = q->cap;
  int index = (t - buf + 1) % cap;
  if (h - buf == index) { // queue is full, i.e. overflow
    err = 1;
    return
  }
  if (index == 0) t = buf;
  *t++ = data;
}

int dequeue(Queue *q) {}

int length(Queue *q) {
  return q->h == q->t ? 0 : q->buf + q->cap - q->h + q->t - q->buf;
}

/*void enqueue(Queue *q, int buf) {
  if (q->length == q->cap) {
    int cap = q->length;
    if (q->length < 2 * q->cap) {
      cap = 2 * q->cap;
    }
    ptrdiff_t dh = q->h - q->buf;
    ptrdiff_t dt = q->t - q->buf;
    int *temp = realloc(q->buf, cap);
    if (temp == NULL) {
    }
    q->buf = temp;
    q->h = q->buf + dh;
    q->t = q->buf + dt;
    q->cap = cap;
  }
  int index = ++q->length % q->cap;
  q->t[index] = buf;
  if (index == 0)
    q->t = q->buf;
  else
    ++q->t;
}*/
int main(int argc, char *argv[]) {}
