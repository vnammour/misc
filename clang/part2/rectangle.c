/* Sat Aug  8 01:37:47 AM IDT 2026 */
/* By: Jamil Nammour */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} Point;
typedef struct {
    Point p1, p2;
} Rectangle;

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

Rectangle canonical(Rectangle rect) {
    Rectangle temp;
    temp.p1.x = min(rect.p1.x, rect.p2.x);
    temp.p1.y = min(rect.p1.y, rect.p2.y);
    temp.p2.x = max(rect.p1.x, rect.p2.x);
    temp.p2.y = max(rect.p1.y, rect.p2.y);
    return temp;
}

int main(int argc, char *argv[])
{
    struct {
        int len;
        char *str;
    } q, *p;
    p = &q; 
    p->str = (char*) malloc(sizeof(char) * 10);
    strcpy(p->str,"victor");
    printf("%c\n", *p->str++);
    ++p->str;
    printf("%c\n", *p->str);
}
