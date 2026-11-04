/* Mon Oct 12 08:02:56 PM EDT 2026 */
/* By: vnammour */
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
ErrorCode err = 0;
Stack *init(int size) {
    err = 0;
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->sp = (int*) malloc(sizeof(int)*size);
    stack->len = 0;
    stack->size = size;
    return stack;
}
void push(Stack *stack, int value) {
    if (stack->len >= stack->size) err = overflow;
    else stack->sp[stack->len++] = value;
}
int pop(Stack *stack) {
    if (stack->len > 0)
        return stack->sp[--stack->len];
    else err = underflow;
    return err;
}
void reset(Stack *stack) {
    err = 0;
    stack->len = 0;
}
void printstack(Stack *stack) {
    int *p = stack->sp;
    while (p < stack->sp + stack->len)
        printf("%c\n", *p++);
}
void printerror() {
    switch (err) {
    case underflow: printf("Error: underflow\n");break;
    case overflow:  printf("Error: overflow\n");break;
    }
}
void release(Stack *stack) {
    stack->len = stack->size = 0;
    free(stack->sp); stack->sp = 0;
    free(stack);
}
/*int main(int argc, char *argv[])
{
    Stack *stack = init(3);
    while (!err) push(stack,11);
    printstack(stack);
    err = 0;
    int value;
    while ((value = pop(stack)) && !err)
        printf("%d\n", value);
}*/
