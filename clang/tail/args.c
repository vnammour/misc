/* Tue Jul 28 02:00:30 AM IDT 2026 */
/* By: Jamil Nammour */
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char *files[argc-1];
    char *options[argc-1];
    char **f = files;
    char **op = options;
    int opts = 1;
    while (--argc > 0) {
        ++argv;
        if (strcmp(*argv,"--") == 0) opts = 0;
        if (opts && **argv == '-') {
            // parse option(s)
            *op++ = *argv;
        } else *f++ = *argv; // filenames?
    }
    printf("filenames:\n");
    for (char **p = files; p < f; ++p)
        printf("files[%ld] = %s\n", p - files, *p);
    printf("options:\n");
    for (char **p = options; p < op; ++p)
        printf("option[%ld] = %s\n", p-options, *p);
}
