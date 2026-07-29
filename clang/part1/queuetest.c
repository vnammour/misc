/* Tue Jul 14 12:57:24 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include  "./ds/queue.h"

int main(int argc, char *argv[]) {
    printf("main: err= %d\n", geterr());
    // Queue q = init(3); // & use (&q)
    Queue *q = new(5);
    for (int i = 0; i < capacity(q)-1; i++) {
        enqueue(q,i);
        if (geterr() != 0) printf("enqueue: %s - err= %d\n", errstring(geterr()), geterr());
    }
    printf("cap = %ld, length = %d, remaining space = %ld\n",
            capacity(q), length(q), capacity(q) - length(q));
    int temp;
    resize(q,q->cap * 2);
    for (int i = 0; i < capacity(q); i++) {
        temp = dequeue(q);
        if (geterr() != 0) printf("dequeue: %s - err= %d\n", errstring(geterr()), geterr());
        else printf("%d\n", temp);
    }
}
