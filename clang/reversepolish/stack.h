/* Thu Jul 16 10:36:04 AM IDT 2026 */
/* By: vnammour */
#ifndef _STACK_H
#define _STACK_H
#define NUMBER 0    /* signal that a number was found */
int getop(char[]);
void push(double);
double pop();
int getch();
void ungetch(int c);
#endif
