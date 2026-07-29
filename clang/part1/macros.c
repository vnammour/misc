/* Wed Jul 22 05:12:27 PM IDT 2026 */
/* By: vnammour */
#define forever for(;;)
// #define max(a,b) (a > b ? a : b) // wrong
#define max(a,b) ((a) > (b) ? (a) : (b))
#define dprint(expr) printf(#expr " = %g\n", expr)
#define dmsg(expr) printf(#expr " = %s\n", expr)
#define paste(front,back) front##back
#define swap(t,x,y) { t temp = x; x = y, y = temp; }
#include <stdio.h>
int main(int argc, char *argv[])
{
    int a = -1, b = 2;
    int m = max(a++,b++);
    printf("m = %d\n", m);
    int i = 0;
    forever {
        if (i == 100) break;
        ++i;
    }
    float x = 5, y = 3;
    dprint(x/y);
    char *vic = "victor";
    dmsg(vic);
    dmsg("nammour");
    char *paste(name,1) = "name1";
    printf("%s = \"%s\"\n", paste(name,1),name1);
    int paste(var,0) = 3;
    printf("%d\n", var0);
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(int,a,b);
    printf("After swap: a = %d, b = %d\n", a, b);
}
