/* Wed Jul 22 01:37:12 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#define swap(type, s, i, j) { type temp = s[i]; s[i] = s[j], s[j] = temp; }
#define pswap(type, a, b) { type *temp = a; a = b, b = temp; }

void exchange(int *a, int *b) {
    int temp = *a;
    *a = *b, *b = temp;
}
int main(int argc, char *argv[])
{
    int data[] = {1, 2, 3};
    swap(int,data,0,2);
    int *p = data;
    int *q = data + 2;
    exchange(data,data+2);
    int len = sizeof(data)/sizeof(data[0]);
    for (int i = 0; i < len; i++) printf("%d%c", data[i], i == len-1 ? '\n' : ',');
    printf("%d, %d\n", *p, *q);
    pswap(int,p,q);
    printf("%d, %d\n", *p, *q);
    char *s = malloc(len);
    for (int i = 0; i < len; i++) s[i] = 'a' + i;
    printf("%s\n", s);
    swap(char,s,0,1);
    printf("%s\n", s);
    free(s);
}
