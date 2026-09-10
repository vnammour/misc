/* Thu Sep 10 02:11:47 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#define intsize 32
int maxint = (int)((1U << (intsize-1)) - 1);
bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x >= 0 && x <= 9) return true;
    int y = x;
    int n = 0;
    int temp = 0;
    while (y != 0) {
        if (n > maxint/10) return false;
        n *= 10;
        temp = y % 10;
        if (n > maxint - temp) return false;
        n += temp;
        y /= 10;
    }
    return n == x;
}
int main(int argc, char *argv[])
{
    int arr[] = {3,11,140, -12, 12221, 334454433};
    int len = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < len; i++)
        printf("ispalindrome(arr[%d] = %d) = %d\n", i, arr[i], isPalindrome(arr[i]));
    int x = 998765432;
    printf("%d\n", isPalindrome(x));
    unsigned m = maxint + 100;
    printf("%d\n", isPalindrome(m));
    x = 1111111111;
    printf("%d\n%d\n", maxint, x);
    printf("%d\n", isPalindrome(m));
    printf("%d\n", isPalindrome(x));
}
