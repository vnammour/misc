/* Sat Jul 11 04:02:46 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdbool.h> // for legacy compiler support
#include <stdlib.h>
#define MAXLINE 128
double a2f(char *s, int *err);
int getLine(char*,int);
int main(int argc, char *argv[])
{
    int err = 0;
    double v = a2f("12.2",&err);
    printf("err: %d, %.3f\n", err, v);
    char *line = (char*) malloc(sizeof(char) * MAXLINE);
    double sum = 0;
    while (getLine(line,MAXLINE) != EOF) {
        sum += a2f(line,&err);
    }
    printf("err: %d, %.3f\n", err, sum);
}

int getLine(char *line, int lim) {
    int c;
    for (--lim; lim > 0 && (c = getchar()) != EOF && c != '\n'; *line++ = c, --lim);
    *line = '\0';
    return c;
}

int isspace(int c) {
    return c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\n';
}
int isdigit(int c) {
    return c >= '0' && c <= '9';
}
double a2f(char *s, int *err) {
    if (s == NULL || *s == 0) { *err = 1; return 0; }
    double val = 0;
    int pow = 1;
    while (isspace(*s)) ++s;
    int sign = *s == '-' ? -1 : 1;
    if (*s == '+' || *s == '-') ++s;
    for (; *s && isdigit(*s); s++)
        val = 10 * val + *s - '0';
    if (*s == '.') ++s;
    for (; *s && isdigit(*s); s++) {
        pow *= 10;
        val = val * pow + *s - '0';
    }
    if (*s != 0) { *err = 1; return 0; }
    return sign * val/pow;
}
/*
 * Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e−6
where a floating-point number may be followed by e or E and an optionally signed exponent.
 */
