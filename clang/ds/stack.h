/* Wed Jul 15 01:19:20 PM IDT 2026 */
/* By: vnammour */
#ifndef _STACK_H_
#define _STACK_H_
typedef struct {
    int *buf;
    int *sp;
    int cap;
} Stack;

int geterr();
Stack *new(size_t cap);
void resize(Stack *stack, size_t cap);
void push(Stack *stack, int data);
int pop(Stack *stack);
int top(Stack *stack);
int capacity(Stack *stack);
int length(Stack *stack);
void reset(Stack *stack);
void show(Stack *stack);
char *errstring(int err);
void info(Stack *stack);
#endif
