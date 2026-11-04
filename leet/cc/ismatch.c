/* Sat Sep 12 02:18:00 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <string.h>
// e.g. : t = "abaaaaaba", p = "aba"
bool isMatch(char *t, char *p) {
    if (t == 0) return false;
    else if (p == 0) return true;
    int tlen = strlen(t), plen = strlen(p);
    if (plen > tlen) return false;
    int i = 0, j = 0;
    bool done = false;
    for (j = 0; !done && i < tlen && tlen - i >= plen - 1; i++) {
        if (j == plen) done = true, i = tlen;
        else if (t[i] != p[j]) {
            j = -1;
            if (tlen - i < plen) i = tlen;
        }
        j++;
    }
    return done;
}
int main(int argc, char *argv[])
{
    char *t = "abaaaaaba";
    char *p = "abaa";
    printf("%d\n", isMatch(t,p));
}
