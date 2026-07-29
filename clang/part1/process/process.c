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
#define MAXLINE 512
#define NLINES 1024

void quicksort(char *v[], int left, int right) {
    void swap(char**, int, int);
    // do nothing if array contains fewer than two elements
    if (left >= right) return;
    swap(v,left,(left+right)/2);
    int last = left;
    for (int i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0) swap(v,++last,i);
    swap(v,left,last);
    quicksort(v,left,last-1);
    quicksort(v,last+1,right);
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
    // read, process, & write lines
    bool ok = true;
    if ((nlines = readlines(lineptr, NLINES, &ok)) >= 0) {
        quicksort(lineptr,0,nlines-1);
        writelines(lineptr,nlines);
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

void swap(char **v, int i, int j) {
    char *temp = v[i];
    v[i] = v[j], v[j] = temp;
}

int readlines1(char **lineptr, int nlines) {
    int i = 0;
    int size;
    for (; i < nlines; i++) {
        char *line;
        if ((line = alloc(MAXLINE)) == 0 || (size = getLine(line,MAXLINE)) == 0) {
            if (size == 0) afree(line);
            return i;
        }
        *lineptr++ = line;
    }
    return i;
}

int readlines2(char **lineptr, int nlines) {
    static char *line = NULL;
    if (line == 0) line = alloc(MAXLINE);
    if (line == 0) {
        fprintf(stderr, "Not enough memory\n");
        return 0;
    }
    int size = 0;
    int i = 0;
    for (; i < nlines; i++) {
        size = getLine(line,MAXLINE);
        if (size == 0 || (*lineptr = alloc(size+1)) == 0) {
            return i;
        }
        strcpy(*lineptr++,line);
    }
    return i;
}
