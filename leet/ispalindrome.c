/* Mon Oct 12 01:56:10 PM EDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <string.h>
bool ispalindrome(char *str, int len) {
    char *p = str, *q = str + len - 1;
    while (p < q && *p++ == *q--);
    return p >= q;
}
int main(int argc, char *argv[])
{
    char *s = "abcdedcba";
    printf("ispalindrome = %d\n", ispalindrome(s,strlen(s)));
    s = "racecar";
    printf("ispalindrome = %d\n", ispalindrome(s,strlen(s)));
}
