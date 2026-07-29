/* Tue Jul 21 02:40:09 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
void printd(int num) {
    int sign = num < 0 ? -1 : 1;
    if (sign < 0) putchar('-');
    int rem, base = 10;
    if (num != 0) {
        rem = num % base * sign;
        num /= base * sign;
        printd(num);
        putchar(rem + '0');
    }
}

int main(int argc, char *argv[])
{
    printd(-123);
    printf("\n");
    /*printf("%d %d\n", -123/10, -123%10);
    printf("%d %d\n", 123/-10, 123%-10);
    printf("%d %d\n", -123/-10, -123%-10);*/
}
