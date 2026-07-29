/* Mon May 18 11:34:16 AM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
void integer();
void unsignedinteger();
void longinteger();

int main(int argc, char *argv[])
{
    integer();
    unsignedinteger();
}

void integer() {
    // intsize = 32 << (~uint(0) >> 63)
    unsigned zero = 0u;
    printf("zero = %d\n", zero);
    unsigned shift = ~zero >> 63;
    printf("shift = %u\n", shift);
    int intsize = 32 << shift;
    printf("intsize = %d\n", intsize);
    int maxint = (1 << (intsize - 1)) - 1;
    printf("maxint = %*d\n", 11, maxint);
    int minint = -1 << (intsize - 1);
    printf("minint = %*d\n", 11,minint);
    printf("~zero = %u\n", ~zero);
}

void unsignedinteger() {
    // intsize = 32 << (~uint(0) >> 63)
    unsigned zero = 0u;
    printf("zero = %u\n", zero);
    unsigned shift = ~zero >> 63;
    printf("shift = %u\n", shift);
    int intsize = 32 << shift;
    printf("intsize = %d\n", intsize);
    unsigned int maxint = (1<<intsize) - 1;
    printf("maxint = %*u\n", 11, maxint);
}
