/* Fri Jul 10 12:01:55 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
int main(int argc, char *argv[])
{
    int n = 10;
    while (n-- > 0);
    if (n == 0) goto zero;
    else goto negative;
zero:
    printf("n is zero\n");
negative:
    printf("n is negative\n");
}
