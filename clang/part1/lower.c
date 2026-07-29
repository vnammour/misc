/* Fri Jun 12 11:41:06 AM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
int lower(int c);
int main(int argc, char *argv[])
{
    for (int c = 'A'; c <= 'Z'; c++)
        printf("%c\n", lower(c));
}
// Ex 2-10
int lower(int c) {
    return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}
