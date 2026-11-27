/* Thu Nov 26 10:59:47 AM IST 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#define LINKEDLIST_IMPLEMENTATION
#define LL_DATA_TYPE
typedef struct Point {
    int x,y;
} Point;
typedef Point *Type;
#include "linkedlist.h"
void printpoint(Point *p) {
    if (p != NULL)
        printf("(%d,%d)", p->x,p->y);
}
void freepoint(Point *p) {
    free(p);
}
void test1() {
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr)/sizeof(*arr);
    Node *list = 0;
    for (int i = 0; i < len; i++) {
        Point *p = (Point*) malloc(sizeof(Point));
        p->x = i, p->y = arr[i];
        list = pushback(list,i,p);
    }
    // printlist(list, printpoint);
    // freelist(&list,freepoint);
    // printlist(list,printpoint);
    printf("\n\n");
    Node *head = list, *rnd = 0, *tail = 0;
    int i = 0;
    while (head != NULL) {
        if (i == len/2) rnd = head;
        tail = head;
        head = head->next;
        ++i;
    }
    // printlist(rnd,printpoint);
    printf("rnd->key = %d\n", rnd->key);
    printf("list addr = %p\n", list);
    Point *p = 0;
    bool isremoved = pluck(&list,rnd->key, &p);
    printf("isremoved = %d\n", isremoved);
    if (isremoved) printpoint(p);
    printf("list addr = %p\n", list);
    printlist(list,printpoint);
    // printlist(tail,printpoint);
    // freelist(list,NULL);
}
int main(int argc, char *argv[])
{
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr)/sizeof(*arr);
    Node *list = 0;
    for (int i = 0; i < len; i++) {
        Point *p = (Point*) malloc(sizeof(Point));
        p->x = i, p->y = arr[i];
        list = pushback(list,i,p);
    }
    printlist(list,printpoint);
    Point *p = 0;
    int i = 0;
    while (list != 0) pluck(&list,i++,&p);
    pluck(&list,4,&p);
    printlist(list,printpoint);
    freelist(&list,freepoint);
    printlist(list,printpoint);
    printf("is list null? %d\n", list == NULL);
    printf("address = %p\n", list);
    freelist(&list,freepoint);
}
