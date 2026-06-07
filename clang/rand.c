/* Wed Jun  3 06:57:53 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <time.h>

unsigned long next = 1;
// rand: return pseudo-random integer on 0..32767
int rand() {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

// srand: set seed for rand()
void srand(unsigned int seed) {
    next = seed;
}

int main(int argc, char *argv[])
{
    srand(time(0));
    printf("%d\n", rand());
}
