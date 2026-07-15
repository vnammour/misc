/* Wed Jul 15 01:13:40 AM IDT 2026 */
/* By: Jamil Nammour */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./ds/stack.h"

void teststack() {
    Stack *s = new(10);
    for (int i = 0; i < capacity(s); i++) {
        if (geterr() != 0) {
            printf("%s\n", errstring(geterr()));
            break;
        }
        push(s,i);
    }
    while (length(s) > 0) {
        printf("pop: %d\n", pop(s));
        if (geterr() != 0) {
            printf("%s\n", errstring(geterr()));
            break;
        }
    }
    resize(s,0);
    printf("%s\n", errstring(geterr()));
    push(s,10);
    printf("%s\n", errstring(geterr()));
    pop(s);
    printf("%s\n", errstring(geterr()));
    printf("length = %d, capacity = %d\n", length(s), capacity(s));
    free(s);
}

bool validate_expression(Stack *s, char *exp) {
    bool ok = true;
    for (int i = 0; ok && i < strlen(exp); i++) {
        switch (exp[i]) {
        case '(': case '[': case '{':
            push(s,exp[i]);
            if (geterr() != 0) {
                ok = false;
            }
            break;
        case ')': case ']': case '}':
            int t = top(s);
            if (geterr() != 0) {
                ok = false;
                break;
            }
            if (exp[i] == ')' && t == '(' || exp[i] == ']' && t == '[' ||
                    exp[i] == '}' && t == '{')
                pop(s);
            else ok = false;
            break;
        default: break;
        }
    }
    if (geterr() != 0) printf("%s\n", errstring(geterr()));
    return ok && length(s) == 0;
}

int main(int argc, char *argv[])
{
    // teststack();
    // char *exp = "(this is [a parenthesized{expression}to check] if balanced).";
    // char *exp = "(([[]])){}";
    char *exp = "aaa)";
    int cap = strlen(exp);
    Stack *s = new(cap);
    printf("%s\n", validate_expression(s,exp) ? "true": "false");
    char *text = (char*) malloc(sizeof(char) * 100);
    while(fgets(text,100, stdin) != NULL) {
        printf("text = >%s<\n", text);
        reset(s);
        info(s);
        if (strlen(text) > capacity(s)) {
            printf("resizing stack to %d\n", strlen(text));
            resize(s,strlen(text));
        }
        printf("%s\n", validate_expression(s,text) ? "true": "false");
    }
    resize(s,0);
    free(s);
    s = NULL;
}
