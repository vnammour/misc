/* Sun Jun  7 08:27:11 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stddef.h> // for ptrdiff_t
void squeeze(char *s, char c);
int getLine(char*,ptrdiff_t);
void strCat(char*,char*);
int main(int argc, char *argv[])
{
    char s[50] = "abcdaaabbba";
    squeeze(s,'a');
    printf("%s\n", s);
    int c;
    while (c != EOF) {
        c = getLine(s,50);
        printf(">%s<\n", s);
    }
    {
        char s[10] = "one";
        char t[10] = " two";
        strCat(s,t);
        printf("%s\n", s);
    }
}
void squeeze(char *s, char c) {
    if (s == 0) return;
    int j = 0;
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] != c) s[j++] = s[i];
    }
    s[j] = '\0';
}

int getLine(char *s, ptrdiff_t size) {
    int c = 0;
    char *p = s;
    for (; p - s < size -1 && (c = getchar()) != EOF && c != '\n'; p++)
        *p = c;
    *p = '\0';
    return c;
}

// concatenates the string t to the end of the string s.
// assumes that there is enough space in s to hold the combination.
void strCat(char *s, char *t) {
    while (*s++);
    --s;
    while (*s++ = *t++);
}
