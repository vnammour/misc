/* Tue Oct 13 11:30:17 AM PDT 2026 */
/* By: vnammour */
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
int getLine(char *s, int lim) {
    char *p = s;
    while (--lim > 0 && (*s++ = getchar()) != EOF && s[-1] != '\n');
    if (s[-1] == EOF) --s;
    *s = '\0';
    return s - p;
}
bool isvalidparenth(Stack *stack, char *s, int len) {
    char *p = s;
    int lastseen;
    while (p < s + len) {
        lastseen = *p++;
        if (lastseen == '{' || lastseen == '[' || lastseen == '(') {
            push(stack,lastseen);
	        if (err != 0) {
	            printerror();
	            return false;
	        }
        } else if (lastseen == '}' || lastseen == ']' || lastseen == ')') {
	        char c = pop(stack);
	        if (err != 0) {
	            printerror();
	            return false;
	        }
	        switch (lastseen) {
                case ']': if (c != '[') return false; break;
                case '}': if (c != '{') return false; break;
                case ')': if (c != '(') return false; break;
                default: break;
	        }
        }
    }
    return stack->len == 0;
}
#define SIZE 10
int main(int argc, char *argv[])
{
    char *s = (char*) malloc(SIZE);
    Stack *stack = init(SIZE);
    int len;
    while ((len = getLine(s,SIZE)) > 0) {
        if (s[len-1] == '\n') --len;
        // printf("-->%s\n", s);
        bool isvalid = isvalidparenth(stack,s,len);
        printf("isvalid = %d\n", isvalid);
        reset(stack);
    }
    release(stack);
    free(s);
}
