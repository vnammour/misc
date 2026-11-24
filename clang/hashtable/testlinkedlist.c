/* Tue Nov 24 01:59:18 PM IST 2026 */
/* By: vnammour */
#include <stdio.h>
#define LINKEDLIST_IMPLEMENTATION
#include "linkedlist.h"

void printht(Node **ht, int len) {
    if (ht == 0) return;
    for (Node **p = ht; p < ht + len; p++)
        printlist(*p);
}

int main(int argc, char *argv[])
{
    int arr[] = {-1,5,4,15,3};
    int len = sizeof(arr)/sizeof(*arr);
    Node *head = 0;
    for (int i = 0; i < len; i++)
        head = pushfront(head,arr[i],i);
    printlist(head);
    Node **ht = (Node**) malloc(sizeof(Node*)*10);
    for (Node **p = ht; p < ht + 10; p++)
        *p = 0;
    int i = 0;
    for (Node **p = ht; p < ht + 10 && i < len; p++) {
        *p = pushfront(*p,arr[i],i);
        i += 2;
    }
    printlist(head);
    printht(ht,10);
}
