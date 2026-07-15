/* Tue Jul 14 12:57:24 PM IDT 2026 */
/* By: vnammour */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

unsigned short err = 0; // 1 - overflow, 2 - underflow, 3 - no memory, 4 - other

int geterr() {
    return err;
}

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

void resize(Queue *q, size_t cap) {
    if (q == NULL || cap == q->cap) {
        return;
    }
    if (cap <= 0) {
        free(q->buf);
        q->buf = q->h = q->t = NULL;
        q->cap = 0;
        return;
    }
    ptrdiff_t hd = q->h - q->buf;
    ptrdiff_t ht = q->t - q->buf;
    int *temp = (int*) reallocarray(q->buf,cap,sizeof(int));
    if (temp == NULL) {
        err = 3;
        return;
    }
    q->buf = temp;
    q->h = q->buf + hd;
    q->t = q->buf + ht;
}

char *errstring(int err) {
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
