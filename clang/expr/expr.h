/* Sun Jul 26 01:57:49 PM IDT 2026 */
/* By: vnammour */
#if !defined(_EXPR_H)
#define _EXPR_H
#include <stddef.h>
#define NUMBER 0 /* signal that a number was found */
int pop();
void push(int);
int isempty();
// void printstack();
int a2i(char *s, int *ok);
int getch();
void ungetch(int c);
ptrdiff_t getLine(char *s, int lim);
int getop(char *s);
int getop_line(char *line, char *s, int len);
#endif
