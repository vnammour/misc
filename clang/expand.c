/* Sun Jul  5 08:32:05 AM IDT 2026 */
/* By: vnammour */
/*
 Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
 the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of
 either case and digits, and be prepared to handle cases like a-b-c and a-z0−9 and -a-z.
 Arrange that a leading or trailing - is taken literally.
 */
#include <stdio.h>
#include <stddef.h> // for size_t
#include <string.h>
#include <stdlib.h>
#include <err.h>
char *expand(char *s);
void test();
int main(int argc, char *argv[])
{
    char *s = "-a-za-za-z0-9d-a(-.-";
    char *t = expand(s);
    if (t != NULL) printf("%s\n", t);
}

char *expand(char *s) {
    if (s == NULL) return s;
    int len = strlen(s);
    int cap = len + 1;
    char *p = s;
    char *t = (char*) malloc(sizeof(char) * cap);
    char *q = t;
    while (p < s + len) {
        // printf("*p = %c\n", *p);
        if (*p == '-') {
            if (p-s == 0) *q++ = *p++;
            else if (p-s == len-1) *q++ = *p++;
            else {
                int a,z;
                a = p[-1];
                if (p[1] == 0) break;
                z = *++p;
                if (z<a) continue;
                ++p;
                // printf("initial capacity = %d, q-t = %td\n", cap, q-t);
                // printf("z-a = %d, cap - (q-t)-1 = %d\n", z-a, cap - (q-t) - 1);
                if (z - a > cap - (q - t) - 1) {
                    int dist = q-t;
                    cap = 2 * cap + z-a;
                    printf("realloating with cap = %d\n", cap);
                    char *temp = (char*) realloc(t,sizeof(char) * cap);
                    if (temp == NULL) {
                        err(EXIT_FAILURE,"REALLOC");
                        break;
                    }
                    t = temp, q = t + dist;
                }
                for (int c = a+1; c <= z; c++) {
                    *q++ = c;
                }
            }
        } else *q++ = *p++;
    }
    *q = '\0';
    return t;
}

void test() {
    size_t cap = 101;
    size_t len = 11;
    int k = 0;
    char *s = NULL, *p = NULL;
    int c = 'a';
    ptrdiff_t dist;
    while ((dist = p - s) < cap-1) {
        if (dist == 0 || dist % len == len-1) {
            char *temp = realloc(s, k < (cap/len) ? len + k * len : cap);
            if (temp == NULL) {
                err(EXIT_FAILURE,"REALLOC");
                return;
            }
            s = temp, p = s + dist;
            if (k != 0) *p++ = '\n';
            k++;
        }
        *p++ = 'a';
    }
    // s[cap-1] = '\0';
    *--p = '\0';
    printf("%sstrlen = %d, %td\n", s, strlen(s), p - s);
    free(s);
}
