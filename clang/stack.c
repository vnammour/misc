/* Wed Jul 15 01:13:40 AM IDT 2026 */
/* By: Jamil Nammour */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int *buf;
    int *sp;
    int cap;
} Stack;

unsigned short err = 0;

Stack *new(size_t cap) {
    err = 0;
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    if (stack == NULL) {
        err = 3;
        return NULL;
    }
    stack->buf = (int*) malloc(sizeof(int) * cap);
    if (stack->buf == NULL) {
        err = 3;
        return NULL;
    }
    stack->sp = stack->buf;
    stack->cap = cap;
}

void resize(Stack *stack, size_t cap) {
    if (stack == NULL) return;
    if (cap <= 0) {
        free(stack->buf);
        stack->buf = stack->sp = NULL;
        free(stack);
        return;
    }
    ptrdiff_t spd = stack->sp - stack->buf;
    int *temp = (int*) reallocarray(stack->buf, cap, sizeof(int));
    if (temp == NULL) {
        err = 3;
        return;
    }
    stack->buf = temp;
    stack->sp = stack->buf + spd;
    stack->cap = cap;
}

void push(Stack *stack, int data) {
    err = 0;
    if (stack == NULL) {
        err = 3;
        return;
    }
    if (stack->sp >= stack->buf + stack->cap) {
        err = 1; // overflow
        return;
    }
    *stack->sp++ = data;
}

int main(int argc, char *argv[])
{
}
