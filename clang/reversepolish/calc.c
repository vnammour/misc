/* Thu Jul 16 10:26:45 AM IDT 2026 */
/* By: vnammour */
// K & R, ch4
/*
while (next operator or operand is not end-of-file indicator)
           if (number)
                    push it
           else if (operator)
                    pop operands
                    do operation
                    push result
           else if (newline)
                    pop and print top of stack
           else
                    error
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define MAXOP 100   /* max size of operand or operator */
int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop()+pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop()-op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) push(pop()/op2);
            else printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
