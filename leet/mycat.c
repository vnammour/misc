/* Sat Sep 26 11:53:30 PM IDT 2026 */
/* By: Tia Nammour */
#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stddef.h>
// #include <stdbool.h>
// #include <ctype.h>

int getLine(char *s, int lim) {
    int c;
    char *p = s;
    while (--lim > 0 && (*s++ = getchar()) != EOF && s[-1] != '\n');
    if (s[-1] == EOF) --s;
    *s = '\0';
    return s - p;
}

int main(int argc, char *argv[])
{
    if (argc > 1) {
        int i = --argc;
        while (*++argv)
            printf("arg %d = \"%s\"\n", i - argc--, *argv);
    }
    int lim = 10;
    char s[lim];
    while (getLine(s,lim) != 0) {
        printf("%s", s);
    }
    return 0;
}
