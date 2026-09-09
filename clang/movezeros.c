/* Tue Sep  1 04:04:53 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}
void singlepass(int *a, int n) {
    int *p = a, *q = a;
    while (p < a + n && q < a + n) {
        while (p < a + n && *p != 0) ++p;
        q = p + 1;
        while (q < a + n && *q == 0) ++q;
        if (q < a + n) swap(p++,q++);
    }
}
int main(int argc, char *argv[])
{
    int a[] = {1,0,0,0,0,0,12,0,0,0,3,0,0,4};
    int len = sizeof(a)/sizeof(a[0]);
    singlepass(a,len);
    printf("{");
    for (int i = 0; i < len; i++)
        printf("%d%s", a[i], i == len-1 ? "}\n" : ",");
}
