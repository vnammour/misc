/* Wed Jul 22 01:05:39 PM IDT 2026 */
/* By: vnammour */
/* Exercise 4-13 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *s, int i, int j) {
    char temp = s[i];
    s[i] = s[j], s[j] = temp;
}

char* reverse(char *s) {
    char *rev = strdup(s);
    for (int i = 0, j = strlen(rev) - 1; i < j; i++, j--)
        swap(rev,i,j);
    return rev;
}

void recreverse(char *s, int i, int j) {
    if (i < j) {
        char temp = s[i];
        s[i] = s[j], s[j] = temp;
        recreverse(s,++i,--j);
    }
}

int main(int argc, char *argv[])
{
    char *s = "victor";
    char *rev = reverse(s);
    printf(">%s<\n", rev);
    recreverse(rev,0,strlen(rev)-1);
    printf(">%s<\n", rev);
    free(rev);
}
