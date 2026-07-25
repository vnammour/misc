/* Sat Jul 25 12:57:30 PM IDT 2026 */
/* By: vnammour */
#if !defined(_PROCESS_H)
#define _PROCESS_H
#include <stddef.h>
int getch();
void ungetch(int);
char *alloc(int);
void afree(char*);
size_t getLine(char*,size_t);
size_t memoryat();
#endif
