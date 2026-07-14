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

Queue *new(size_t cap) {
    err = 0;
    Queue *q = (Queue*) malloc(sizeof(Queue));
    if (q == NULL) {
        err = 3;
        return q;
    }
    q->buf = (int*) malloc(sizeof(int) * cap);
    if (q->buf == NULL) {
        err = 3;
        return NULL;
    }
    q->cap = cap;
    q->h = q->t = q->buf;
    return q;
}

char * errstring(int err) {
    if (err < 0) {
        return "Unknown error.";
    }
    switch (err) {
    case 0: return "none";
    case 1: return "overflow";
    case 2: return "underflow";
    case 3: return "no memory";
    default: return "other";
    }
}

void enqueue(Queue *q, int data) {
  err = 0;
  if (q == NULL) {
      err = 4;
      return;
  }
  int *h = q->h, *t = q->t, *buf = q->buf;
  int cap = q->cap;
  int index = (t - buf + 1) % cap;
  if (h - buf == index) { // queue is full, i.e. overflow
    err = 1;
    return;
  }
  *q->t++ = data;
  if (index == 0) q->t = buf;
}

int dequeue(Queue *q) {
  if (q == NULL) {
      err = 4;
      return 0;
  }
    err = 0;
    if (q->h == q->t) {
        err = 2;
        return 0;
    }
    return *q->h++;
}

int length(Queue *q) {
  return q->t > q->h ? q->t - q->h : q->buf + q->cap - q->h + q->t - q->buf;
}

size_t capacity(Queue *q) {
    return q->cap - 1;
}

int main(int argc, char *argv[]) {
    // err = 0;
    printf("main: err = %d\n", err);
    // Queue q = init(3); // & use (&q)
    Queue *q = new(5);
    for (int i = 0; i < capacity(q); i++) {
        enqueue(q,i);
        if (err != 0) printf("enqueue: %s - err = %d\n", errstring(err), err);
    }
    printf("length = %d\n", length(q));
    int temp;
    for (int i = 0; i < capacity(q); i++) {
        temp = dequeue(q);
        if (err != 0) printf("dequeue: %s - err = %d\n", errstring(err), err);
        else printf("%d\n", temp);
    }
}
