/* Sat Jul 25 11:44:02 AM IDT 2026 */
/* By: vnammour */
/*
 read all lines of input
 sort them
 print them in order
 */
// #include <fcntl.h> // open, creat
// #include <unistd.h> // close
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "process.h"
#define MAXLINE 100
#define NLINES 100

int numcmp(const char *s1, const char *s2) {
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) return -1;
    else if (v1 > v2) return 1;
    else return 0;
}
void quicksort(void *v[], int left, int right, int (*comp)(void*,void*)) {
    void swap(void**, int, int);
    // do nothing if array contains fewer than two elements
    if (left >= right) return;
    swap(v,left,(left+right)/2);
    int last = left;
    for (int i = left+1; i <= right; i++)
        if ((*comp)(v[i],v[left])<0) swap(v,++last,i);
    swap(v,left,last);
    quicksort(v,left,last-1,comp);
    quicksort(v,last+1,right,comp);
}

int readlines(char **lineptr, int nlines, bool *ok) {
    char line[MAXLINE];
    int n = 0;
    int len;
    *ok = true;
    while ((len = getLine(line,MAXLINE)) > 0) {
        if (++n > nlines || (*lineptr++ = alloc(len)) == 0) {
            *ok = false;
            return n-1;
        }
        line[len-1] = '\0';
        strcpy(lineptr[-1],line);
    }
    return n;
}

void writelines(char **lineptr, int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

int main(int argc, char *argv[])
{
    // allocate data structure
    char **lineptr = (char**) malloc(sizeof(char*) * NLINES);
    int nlines;
    int numeric;
    if (argc > 1 && strcmp(argv[1],"-n") == 0) numeric = 1;
    // read, process, & write lines
    bool ok = true;
    if ((nlines = readlines(lineptr, NLINES, &ok)) >= 0) {
        quicksort((void**)lineptr,0,nlines-1,
            (int (*)(void*,void*))(numeric ? numcmp : strcmp));
        writelines(lineptr,nlines);
        afree(*lineptr);
    }
    printf("nlines = %d\n", nlines);
    printf("were all lines processed? %s\n", ok == 1 ? "true" : "false");

    // free memory
    printf("memory at = %d\n", memoryat());
    for (int i = nlines-1; i >=0; i--) {
        afree(lineptr[i]);
        lineptr[i] = NULL;
    }
    printf("now, memory at = %d\n", memoryat()); // at location of line from readlines
    free(lineptr);
}

void swap(void **v, int i, int j) {
    void *temp = v[i];
    v[i] = v[j], v[j] = temp;
}
