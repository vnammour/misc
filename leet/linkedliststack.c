/* Tue Oct 13 05:28:04 PM EDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
typedef enum { underflow = 1, overflow} ErrorCode;
ErrorCode err = 0;
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} Stack;

Stack *init() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->head = 0;
    return stack;
}
void release(Stack *stack) {
    while (stack->head != 0) {
        Node *temp = stack->head->next;
        free(stack->head);
        stack->head = temp;
    }
    free(stack);
}
void push(Stack *stack, int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    if (node == 0) {
        err = overflow; // out of memory!
        return;
    }
    node->data = data, node->next = 0;
    if (stack->head == 0) stack->head = node;
    else {
        Node *prev = 0, *h = stack->head;
        for (; h != 0; prev = h, h = h->next);
        prev->next = node;
    }
}
int pop(Stack *stack) {
    Node *x = stack->head;
    if (x == 0) {
        err = underflow;
        return err;
    }
    int data;
    Node *y = x->next;
    if (y == 0) {
        data = x->data;
        free(x);
        stack->head = 0;
        return data;
    }
    Node *z = y->next;
    while (z != 0) {
        x = y, y = z;
        z = z->next;
    }
    data = y->data;
    free(y);
    x->next = 0;
    return data;
}
void show(Stack *stack) {
    Node *h;
    for (h = stack->head; h != 0; h = h->next)
        printf("%d->", h->data);
    printf("%p\n", h);
}
int getLine(char *s, int lim) {
    char *p = s;
    while (--lim > 0 && (*s++ = getchar()) != EOF && s[-1] != '\n');
    if (s[-1] == EOF) --s;
    *s = '\0';
    return s - p;
}
Node* top(Stack *stack) {
    Node *prev = 0;
    for (Node *h = stack->head; h != 0; prev = h, h = h->next);
    return prev;
}
bool validateparen(Stack *stack, char *s, int len) {
    for (char *p = s; p < s + len; ++p) {
        if (*p == '{' || *p == '[' || *p == '(') {
            push(stack,*p);
        } else if (*p == '}' || *p == ']' || *p == ')') {
            int c = pop(stack);
            if (*p == '}' && c != '{' || *p == ']' && c != '[' ||
                    *p == ')' && c != '(')
                return false;
            /*Node *p = top(stack);
            if (p == 0) return false;
            int c = p->data;
            if (*p == '}' && c != '{' || *p == ']' && c != ']' ||
                    *p == ')' && c != '(')
                return false;
            else pop(stack);*/
        }
    }
    return stack->head == 0;
}
int main(int argc, char *argv[])
{
    Stack *stack = init();
    /*for (int i = 0; i < 10; i++)
        push(stack,i);
    show(stack);
    while (stack->head != 0)
        printf("%d\n", pop(stack));*/
    char *s = (char*) malloc(256);
    int len = getLine(s,256);
    int isvalid = validateparen(stack,s,len);
    printf("isvalid = %s\n", isvalid == 1 ? "true" : "false");
}
