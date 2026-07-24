/* Tue Jun  2 11:37:01 AM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
int getl(int,char*);
int ex2_2(int,char*);
long unsigned int strlen(char*);
int main(int argc, char *argv[])
{
    int c;
    char t[10];
    // while (getl(10,t) > 0) {
    int len = 0;
    while ((len = ex2_2(10,t)) != EOF) { // && len > 0) {
        printf("len = %d, >%s<\n", len, t);
    }
    printf("len = %d, >%s<\n", len, t);
    return 0;

    char *s = "0123";
    printf("\nlen = %lu\n", strlen(s));
    printf("%s\n", s);
}

long unsigned int strlen(char *s) {
    char *t = s;
    while (*t++);
    return t - s - 1;
}

// input: lim. At most lim - 1 characters are read
// input: s: char array to store read characters
// test: "hello world how is everyone"
// output: "hello wor", "ld how is", " everyone"
// final input in this example is the '\n', which causes the function to return 0
int getl(int lim, char *s) {
    char *t = s;
    int c = 0;
    for (; t - s < lim - 1 && (c = getchar()) != EOF && c != '\n'; t++) {
        *t = c;
    }
    *t = '\0';
    if (c == EOF && t == s) {
        return c;
    }
    return t - s;
}

int ex2_2(int lim, char *s) {
    char *t = s;
    int c = 0;

    for (; ; t++) {
        if (t - s >= lim - 1) {
            break;
        }

        c = getchar();

        if (c == EOF) {
            break;
        }

        if (c == '\n') {
            break;
        }

        *t = c;
    }

    *t = '\0';

    // If we hit EOF AND we didn't read any characters on this turn, return EOF
    if (c == EOF) {
        if (t == s) {
            return c; 
        }
    }

    return t - s;
}
