/* Sat Aug  8 05:13:46 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
static char buf[10];
static char *bufp = buf;
int getch() {
    return bufp > buf ? *--bufp : getchar();
}
void ungetch(int c) {
    if (bufp < buf + 10) *bufp++ = c;
}
typedef struct key key;
struct key {
    char *word;
    int count;
};
#define MAXWORD 100
key keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    /* ... */
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};
// #define NKEYS (sizeof keytab / sizeof(key))
#define NKEYS (sizeof keytab / sizeof(keytab[0]))
int binsearch(char *word, key *keytab, int n) {
    int cond;
    int low, high, mid;
    low = 0, high = n - 1;
    while (low <= high) {
        mid = (low + high)/2;
        if ((cond = strcmp(word,keytab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0) low = mid + 1;
        else return mid;
    }
    return -1;
}
int getword(char *word, int lim) {
    int c;
    char *w = word;
    while (isspace(c = getch()));
    if (c != EOF) *w++ = c, --lim;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if(!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
int main(int argc, char *argv[])
{
    // int nkeys = sizeof(keytab)/sizeof(keytab[0]);
    // printf("sizeof(keytab) = %d\n", sizeof(keytab)/sizeof(keytab[0]));
    int n;
    char word[MAXWORD];
    while (getword(word,MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word,keytab,NKEYS)) >= 0)
                keytab[n].count++;
    for (int n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    return 0;
}
