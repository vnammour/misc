/* Mon Nov  9 10:39:44 PM IST 2026 */
/* By: Tia Nammour */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *encode(char *s, int len) {
    char *t = (char*) malloc(len);
    char *q = t;
    char *p = s;
    while (p < s + len) {
        if (*p == 'a' && p+1 < s + len && p[1] == 'c')
            *q++ = 'z', p += 2;
        else *q++ = *p++;
    }
    *q = '\0';
    char *final = (char*) malloc(q - t + 1);
    final[q-t] = '\0';
    strcpy(final,t);
    free(t); return final;
}
char *decode(char *s, int len) {
    char *t = s;
    int count = 0;
    while (t < s + len)
        if (*t++ == 'z') ++count;
    len += count;
    char *p = (char*) malloc(len + 1), *q = p;
    t = s;
    while (t < s + len)
        if (*t++ == 'z')
            *q++ = 'a', *q++ = 'c';
        else *q++ = t[-1];
    *q = '\0';
    return p;
}
int main(int argc, char *argv[])
{
    char *s = "ace ac for cooling is ace";
    char *t = encode(s,strlen(s));
    t = decode(t,strlen(t));
    printf("%s\n", t);
    printf("strlen(s) = %ld\n", strlen(t));
}
