/* Sat Jun 13 06:17:12 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
int f(int n) {
    if (n == 0) return 1;
    if (n < 0) return -1;
    int x = 2;
    while (--n > 0) {
        x *= 2;
    }
    return x;
}
// Writing code that depends on order of evaluation is a bad programming practice in any language.
int main(int argc, char *argv[])
{
    /*int n = 3;
    printf("%d %d\n", ++n, f(n));*/
    int i = 0;
    int a[3];
    while (i < 3){
        a[i] = i++;
        printf("i = %d\n", i);
        // printf("a[%d] = %d\n", i-1,a[i-1]);
        // infinite loop in block
        // {
        //     i = i++;
        //     printf("%d\n", i);
        // }
        // printf("%d\n", i = i++); // infinite loop here
    }
    // for (i = 0; i < 3; i++) printf("a[%d] = %d\n", i,a[i]);
}
