/* Mon Jun 15 04:12:36 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
unsigned long next = 1;
void sort(int *a, int size);
int binarysearch(int *a, int size, int num);
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
    const int size = 100;
    int *a = (int*) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) a[i] = rand();
    sort(a,size);
    for (int i = 0; i < size; i++) printf("a[%d] = %d\n", i,a[i]);
    printf("%d\n", binarysearch(a,size,a[size-1]));
    free(a);
}

int binarysearch(int *a, int size, int num) {
    int low,mid,high;
    low = 0, high = size-1;
    while (low <= high) {
        mid = (low+high)/2;
        if (num < a[mid]) high = mid - 1;
        else if (num > a[mid]) low = mid + 1;
        else return mid;
    }
    return -1;
}

void sort(int *a, int size) {
    for (int i = 1; i < size; i++)
        for (int j = i-1; j >= 0; j--)
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
}
