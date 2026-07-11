/* Sat Jul 11 11:34:55 AM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line lenght */
int getLine(char *s, int size);
int strindex(char *s, char *pattern);
void findall(int argc, char *line, char **argv);
int main(int argc, char *argv[])
{
    if (--argc == 0) return 0;
    ++argv;
    char *s = (char*) malloc(sizeof(char)*MAXLINE);
    int index = -1;
    while (getLine(s,MAXLINE) != EOF) {
        findall(argc,s,argv);
    }
    /*while (getLine(s,MAXLINE) != EOF) {
        // printf(">%s<, strlen(s) = %d\n", s, strlen(s));
        if ((index = strindex(s,searchfor)) != -1) {
            printf("%d: %s\n", index, s + index);
        }
    }*/
}

void findall(int argc, char *line, char **argv) {
    int index = -1;
    while (argc--)
        if ((index = strindex(line,*argv++)) != -1)
            printf("%d: %s\n", index, line + index);
}

int getLine(char *s, int size) {
    int c;
    char *p = s;
    for (; p - s < size - 1 && (c = getchar()) != EOF && c != '\n'; *p++ = c);
    *p = '\0';
    return c;
}

int strindex(char *s, char *pattern) {
    if (s == NULL || pattern == NULL) return -1;
    char *p = 0,*q = 0,*t = 0;
    int done = 0;
    for (p = s; *p && !done; p++) {
        for (q = pattern, t = p; *q && *q == *t; ++q, ++t);
        if (t > p && *q == '\0') done = 1, --p;
    }
    return done == 1 ? p - s : -1;
}
