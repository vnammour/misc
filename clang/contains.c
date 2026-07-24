/* Fri Jul 24 01:54:47 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 func hasprefix(s,t string) bool {
    return len(s) >= len(t) && s[:len(t)] == t
 }
 func haspostfix(s, t string) bool {
    return len(s) >= len(t) && s[len(s)-len(t):] == t
 }
 func contains(s, t string) bool {
    for i := 0; i < len(s); i++ {
        if hasprefix(s[i:], t) {
            return true
        }
    }
    return false
 }
 */

int hasprefix(const char *s, const char *t) {
    int slen = strlen(s), tlen = strlen(t);
    if (slen < tlen) return 0;
    const char *p = t;
    while (p < t+tlen && *p == *s) p++,s++;
    return p == t + tlen;
}

// aka strend
int haspostfix(const char *s, const char *t) {
    // return hasprefix(s+strlen(s)-strlen(t),t);
    int slen = strlen(s), tlen = strlen(t);
    if (slen < tlen) return 0;
    const char *p = s + strlen(s) - strlen(t);
    const char *q = t;
    while (q < t + tlen && *p == *q) p++, q++; 
    return q == t + tlen;
}

// returns number of occurrences of t in s and stores beginning index of each occurrence
// of t in s in array pointed to by indices.
// todo: is an empty substr contained in argument string?
size_t contains(const char *s, const char *t, int *indices) {
    int slen = strlen(s), tlen = strlen(t);
    if (slen < tlen) return 0;
    const char *p = s;
    const char *q, *v;
    int *beg = indices;
    while (p < s + slen) {
        for (v = p, q = t; q < t + tlen && *v == *q; q++, v++);
        if (q == t + tlen) {
            *indices++ = p - s;
            if (p < s + slen - tlen) p += tlen;
            else break;
        } else ++p;
    }
    return indices - beg;
}

bool gocontains(const char *s, const char *t) {
    return contains(s,t,(int*)malloc((strlen(s)/(strlen(t)+1) + 1) * sizeof(int))) > 0;
}

void test_contains() {
    char *s = "abc defg hidej";
    char *t = "de";
    int *indices = (int*) malloc((strlen(s)/(strlen(t)+1) + 1) * sizeof(int));
    int x = contains(s,t,indices);
    printf("x = %d\n", x);
    for (int *p = indices; p < indices + x; p++)
        printf("index %d\n", *p);
    free(indices);
    printf("gocontains = %d\n", gocontains(s,t));
}

int main(int argc, char *argv[])
{
    char *s = "acdefg";
    char *t = "ac";
    int x = hasprefix(s,t);
    printf("x = %d\n", x);
    t = "fg";
    x = haspostfix(s,t);
    printf("x = %d\n", x);
    s = t = "";
    x = haspostfix(s,t);
    printf("x = %d\n", x);
    x = hasprefix(s,t);
    printf("x = %d\n", x);
    test_contains();
}

/*int contains(char *s, char *t) {
    // 1st condition is a safe-guard
    if (t == 0 || *t == 0) return 1; // null/empty is contained in any s, regardless
    else if (s == 0 || *s == 0) return 0;
    char *p = s, *q = t;
    while (*p++);
    while (*q++);
    if (p-s < q-t) return 0;
    --p, --q;
    int slen = p-s, tlen = q-t;
    char *w;
    for (p = s + slen - 1; p > s; --p) {
        for (w = p, q = t + tlen - 1; q > t && w > s && *w == *q; --q, --w);
        if (q == t && *q == *w) return 1;
    }
    printf("%c, %c\n", *q, *w);
    return 0;
}*/

