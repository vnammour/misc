#ifndef _STACK_H
#define _STACK_H
typedef enum {underflow = 1, overflow} ErrorCode;
extern ErrorCode err;
typedef struct {
    int size, len;
    int *sp;
} Stack;
Stack *init(int size);
void push(Stack *stack, int value);
int pop(Stack *stack);
void reset(Stack *stack);
void release(Stack *stack);
void printstack(Stack *stack);
void printerror();
#endif
