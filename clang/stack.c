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
    stack->cap = cap;
    stack->buf = (int*) malloc(sizeof(int) * cap);
    if (stack->buf == NULL) {
        err = 3;
        return NULL;
    }
    stack->sp = stack->buf;
}

void resize(Stack *stack, size_t cap) {
    if (stack == NULL || cap == stack->cap) return;
    if (cap <= 0) {
        free(stack->buf);
        stack->buf = stack->sp = NULL;
        stack->cap = 0;
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

int pop(Stack *stack) {
    err = 0;
    if (stack == NULL) {
        err = 3;
        return 0;
    }
    if (stack->sp == stack->buf) {
        err = 2; // underflow
        return 0;
    }
    return *--stack->sp;
}

int top(Stack *stack) {
    err = 0;
    if (stack == NULL) {
        err = 3;
        return 0;
    }
    if (stack->sp == stack->buf) {
        err = 2; // underflow
        return 0;
    }
    return stack->sp[-1];
}

int capacity(Stack *stack) {
    if (stack == NULL) return 0;
    return stack->cap;
}

int length(Stack *stack) {
    if (stack == NULL) return 0;
    return stack->sp - stack->buf;
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

int main(int argc, char *argv[])
{
    Stack *s = new(10);
    for (int i = 0; i < capacity(s); i++) {
        if (err != 0) {
            printf("%s\n", errstring(err));
            break;
        }
        push(s,i);
    }
    while (length(s) > 0) {
        printf("pop: %d\n", pop(s));
        if (err != 0) {
            printf("%s\n", errstring(err));
            break;
        }
    }
    resize(s,0);
    printf("length = %d, capacity = %d\n", length(s), capacity(s));
    free(s);
}
