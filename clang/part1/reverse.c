/* Sat Jul  4 07:38:07 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
void *reverse(char *s);
int main(int argc, char *argv[])
{
    size_t sz = 100;
    char *str = (char*) malloc(sizeof(char)*sz);
    strcpy(str,"ab");
    int i = 0;
    for (; str[i] != '\0'; i++);
    printf("i = %d, strlen = %d\n", i, strlen(str));
    printf(">%s<\n", str);
    reverse(str);
    printf(">%s<\n", str);
}
void *reverse(char *s) {
    int temp;
    for (int i = 0, j = strlen(s)-1; i < j; i++,j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
