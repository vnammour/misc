/* Mon Jul 27 02:47:00 AM IDT 2026 */
/* By: Jamil Nammour */
#include <stdio.h>
#include "expr.h"
#define MAXLINE 1024
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int len;
    int c, ok, num;
    while ((len = getLine(line,MAXLINE)) > 0) {
        if (line[len-1] == '\n')
            line[len-1] = '\0'; // remove newline
        char s[len];
        while ((c = getop_line(line,s,len)) != EOF) {
           if (c == NUMBER) {
               ok = 0;
               num = a2i(s,&ok);
               if (ok) push(num);
               else printf("invalid number format\n");
           } else {
               int a;
               switch(s[0]) {
                case '*': push(pop()*pop()); break;
                case '+': push(pop()+pop()); break;
                case '-':
                    a = pop();
                    int b = pop();
                    printf("pushing %d\n", b - a);
                    push(b-a);
                case '/':
                    a = pop();
                    if (a == 0) printf("error: division by zero\n");
                    else push(pop()/a); break;
                case '%':
                    a = pop();
                    if (a == 0) printf("error: modulo by zero\n");
                    else push(pop()%a); break;
                default: printf("illegal\n"); break;
               }
           }
        }
        num = pop();
        if (!isempty()) printf("invalid expression\n");
        else printf("%d\n", num);
    }
}
