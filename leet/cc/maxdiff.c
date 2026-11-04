/* Mon Oct  5 02:26:52 PM CDT 2026 */
/* By: vnammour */
#include <stdio.h>
struct {
    int a,b;
} pair;
int maxprofit(int *p, int len) {
    int *q = p + len;
    int maxdiff = 0, diff = 0;
    int *l, *r;
    l = r = p;
    // e.g.:  7, 1, 5, 3, 6
    while (r < q) {
        // if (*r-*l > diff) { // Wrong: e.g. 3-1=2 < 4,
        // but I don't want the else part to execute
        if (*l < *r) {
            diff = *r - *l;
            maxdiff = diff > maxdiff ? diff : maxdiff;
        }
        else l = r;
        r++;
    }
    return maxdiff;
}
int main(int argc, char *argv[])
{
    int arr[] = {7,1,5,3,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    int mdiff = maxprofit(arr,len);
    printf("maxdiff = %d\n", mdiff);
}
