/* Mon Jun 22 04:20:40 PM IDT 2026 */
/* By: vnammour */
/*
 Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
 into visible escape sequences like \n and \t as it copies the string t to s. Use a switch.
 Write a function for the other direction as well, converting escape sequences into the
 real characters.
*/
#include <stdio.h>
#include <stdlib.h>
void escape(char *s, char *t);
int countwhites(char *p, int *len);
int main(int argc, char *argv[])
{
    char *s = "one\ttwo\vthree\nfour\rand";
    int len = 0;
    int nwhite = countwhites(s,&len);
    // printf("nwhite = %d, len = %d\n", nwhite,len);
    len = len+nwhite+1;
    char *t = (char*) malloc(len);
    escape(s,t);
    printf("%s", t);
    free(t);
    return 0;
}
int countwhites(char *p, int *len) {
    char c = '\0';
    int nwhite = 0;
    char *q = p;
    while ((c = *q++) != '\0') {
        if (c == ' ' || c == '\t' || c == '\v' || c == '\n'
                || c == '\r')
            nwhite++;
    }
    *len = --q - p;
    return nwhite;
}

void escape(char *s, char *t) {
    char c;
    char *q = t;
    while ((c = *s++) != '\0') {
        switch (c) {
        case '\t': *t++ = '\\'; *t++ = 't'; break;
        case '\n': *t++ = '\\'; *t++ = 'n'; break;
        case '\v': *t++ = '\\'; *t++ = 'v'; break;
        case '\r': *t++ = '\\'; *t++ = 'r'; break;
        default: *t++ = c; break;
        }
    }
    *t = c;
}
