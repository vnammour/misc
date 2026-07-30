/* Wed Jul 29 02:59:43 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <string.h>
#include <stddef.h>
/*
 * Maintain the following inequality to avoid running out of memory:
 * allocbufsize >= size_of_line * size_of_char**array
 */
#define ALLOCSIZE 10000
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
#define LEN 100
static char buf[LEN];
static char *bufp = buf;
static char getch() {
    return bufp > buf ? *--bufp : getchar_unlocked();//getchar();
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

#define MAXLINE 100
// returns -1 if not enough memory in allocbuf, otherwise returns number of lines read.
static int readlines(char **lines, int lim) {
    char **tail = lines;
    int len;
    static char line[MAXLINE];
    while (lim-- > 0 && (len = getLine(line,MAXLINE)) > 0) {
        char *p = alloc(len+1);
        // memory exhausted: just return what we have so far
        if (p == 0) {
            fprintf(stderr, "Fatal: Out of memory in allocator.\n");
            return tail - lines;
        }
        // this block is unreachable if allocbufsize >= sizeofline*sizeofchar**array
        /*if (p == 0) { 
            int mem = availablemem();
            p = alloc(mem);
            if (p == 0) return -1; // should not happen.
            // push back enough chars to get back when enough mem becomes available.
            while (len >= (mem-1) && --len >= 0)
                ungetch(line[len]);
            if (len >0) {
                line[len+1] = 0;
                strcpy(p,line);
                *tail++ = p;
            }
            return -1;
        }*/
        strcpy(p,line);
        *tail++ = p;
    }
    return tail - lines;
}

int main(int argc, char *argv[])
{
    char *lines[MAXLINE];
    int nl;
    while((nl = readlines(lines,MAXLINE)) > 0) {
        char *t = lines[0];
        for (char **p = lines; p < lines + nl; p++) {
            // printf("%s", *p);
            fputs(*p, stdout);
            *p = NULL;
        }
        afree(t);
    }
    // printf("memat: %ld\n", memat());
}
