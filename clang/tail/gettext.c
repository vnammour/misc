/* Mon Jul 27 03:22:43 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h> // for atoi
#include <string.h>
#define MAXLINES 1000
static char *lines[MAXLINES];
#define LEN 10
static char buf[LEN];
static char *bufp = buf;
int getch() {
    return bufp > buf ? *--bufp : getchar();
}
void ungetch(int c) {
    if (bufp < buf + LEN) *bufp++ = c;
}
size_t getLine(char *s, int lim) {
    char *p = s;
    while(--lim > 0 && (*s++ = getch()) != EOF && s[-1] != '\n');
    if (s[-1] == EOF) --s;
    *s = '\0';
    return s - p;
}
char *alloc(int n);
void afree(char *p);
char **readlines(char **lines, int lim) {
    char **tail = lines;
    int len;
    char line[1024];
    while (lim-- > 0 && (len = getLine(line,1024)) > 0) {
        char *ptr = alloc(len+1);
        if (ptr == 0) return 0;
        strcpy(ptr,line);
        *tail++ = ptr;
    }
    return tail;
}
int main(int argc, char *argv[])
{
    int n;
    char nopts = 0;
    while (--argc > 0) {
        ++argv;
        if (strcmp(*argv,"--") == 0) nopts = 1;
        if (!nopts && **argv == '-') { // -n, or -N where n is a number
            if((*argv)[1] == 'n' && --argc > 0) {
                n = atoi(*++argv);
            } else { // it is a number
                n = atoi(++*argv);
            }
        } else { // filename arguments
            printf("%s\n", *argv);
        }
    }
    char **tail;
    n = n > 0 && n <= MAXLINES ? n : 10;
    if ((tail = readlines(lines,MAXLINES)) != 0 && tail > lines) {
        char **p = n <= tail - lines ? tail - n : lines;
        for (; p < tail; ++p)
            printf("%s", *p);
    }
    return 0;
}
