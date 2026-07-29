/* Wed Jul 22 11:26:38 AM IDT 2026 */
/* By: vnammour */
/* Exercise 4-12 */
#include <stdio.h>
#include <stdlib.h>

const unsigned intsize = (unsigned)32 << (~((unsigned)0) >> 63);
const int maxint = (((unsigned)1 << (intsize -1)) - 1);
const int minint = -1 << (intsize - 1);

int compute_numdigits(int n) {
    int count = 1;
    while (n/=10) count++;
    return count;
}

char *itoa(int n) {
    int sign = n < 0 ? -1 : 1;
    int base = 10;
    int i = compute_numdigits(n) + 1;
    if (sign < 0) ++i;
    char *s = (char*) malloc(sizeof(char)*i);
    s[--i] = '\0';
    while (n) {
        s[--i] = n%base * sign + '0';
        n/= base;
    }
    if (sign < 0) s[--i] = '-';
    return s;
}

void *recursive_itoa(int n, char *s, int size) {
    int sign = n < 0 ? -1 : 1;
    int base = 10;
    int rem;
    if (n) {
        rem = n % base * sign;
        n /= base;
        recursive_itoa(n * sign, s, --size);
        s[size] = rem + '0';
    }
    if (sign < 0) s[0] = '-';
}

char *itoa2(int n) {
    int size = compute_numdigits(n) + 1;
    if (n < 0) ++size;
    char *s = (char*) malloc(size);
    s[--size] = '\0';
    recursive_itoa(n, s, size);
    // if (n < 0) s[0] = '-';
    return s;
}

void printd(int n) {
    int sign = n < 0 ? -1 : 1;
    if (sign < 0) putchar('-');
    int base = 10, rem = 0;
    if (n != 0) {
        rem = n % base * sign;
        n /= base;
        printd(n * sign);
        putchar(rem + '0');
    }
}

int main(int argc, char *argv[])
{
    char *s = itoa2(maxint);
    printf(">%s<\n", s);
    free(s);
    /*printf("%u, %d, %d\n", intsize, maxint, minint);
    char *s = itoa(minint);
    printf("%s\n", s);
    free(s);
    s = itoa(maxint);
    printf("%s\n", s);
    free(s);
    printd(minint);
    printf("\n");
    printd(maxint);
    printf("\n");*/
}
