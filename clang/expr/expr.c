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
    int quit = 0;
start:
    while (!quit && (len = getLine(line,MAXLINE)) > 0) {
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
               switch(s[0]) {
                case '*': push(pop()*pop()); break;
                case '+': push(pop()+pop()); break;
                case '-':
                    num = pop();
                    push(pop()-num);
                    break;
                case '/':
                    num = pop();
                    if (num == 0) printf("error: division by zero\n");
                    else push(pop()/num); break;
                case '%':
                    num = pop();
                    if (num == 0) printf("error: modulo by zero\n");
                    else push(pop()%num); break;
                case 'q': quit = 1; goto start; break;
                default: printf("illegal\n"); break;
               }
           }
        }
        num = pop();
        if (!isempty()) printf("invalid expression\n");
        else printf("%d\n", num);
    }
}
