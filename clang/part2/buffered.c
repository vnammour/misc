/* Wed Jul 29 02:59:43 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
// #include <stdbool.h>
// #include <ctype.h>
#define ALLOCSIZE 10240
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
static char *alloc(size_t n) {
    if (allocp <= allocbuf + ALLOCSIZE - n) {
       allocp += n;
       return allocp - n;
    } else return 0;
}
static void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
static size_t memat() {
    return allocp - allocbuf;
}
static size_t availablemem() {
    return allocbuf + ALLOCSIZE - allocp;
}
#define LEN 1024
static char buf[LEN];
static char *bufp = buf;
static char getch() {
    return bufp > buf ? *--bufp : getchar();
}
static void ungetch(int c) {
    if (bufp < buf + LEN) *bufp++ = c;
}

static size_t getLine(char *s, int lim) {
    char *p = s;
    while (--lim > 0 && (*s++ = getch()) != EOF && s[-1] != '\n');
    if (s[-1] == EOF) --s;
    *s = 0;
    return s - p;
}

#define MAXLINE 1024
// returns -1 if not enough memory in allocbuf, otherwise returns number of lines read.
static size_t readlines(char **lines, int lim) {
    char **tail = lines;
    int len;
    static char line[MAXLINE];
    while (lim-- > 0 && (len = getLine(line,MAXLINE)) > 0) {
        char *p = alloc(len+1);
        if (p == 0) {
            int mem = availablemem();
            p = alloc(mem);
            // int req = len+1;
            // push back enough chars to get back when enough mem becomes available.
            while (len > (mem-1) && --len >= 0)
            // while (req-- > mem && --len >= 0)
                ungetch(line[len]);
            // for (int i = len-1; i >= 0; i--)
            //     ungetch(line[i]);
            if (len >0) {
                line[len+1] = 0;
                strcpy(p,line);
                *tail++ = p;
            }
            return -1;
        }
        strcpy(p,line);
        *tail++ = p;
    }
    return tail - lines;
}

int main(int argc, char *argv[])
{
    char *lines[MAXLINE];
    int nl = 0;
    // try to 
    do {
        nl = readlines(lines,MAXLINE);
        for (char **p = lines; p < lines + nl; p++)
            printf("%s", *p);
        afree(lines[0]);
    } while (nl != 0);
    // printf("memat: %ld\n", memat());
}
