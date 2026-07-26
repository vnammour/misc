/* Sun Jul 26 12:17:09 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <string.h>
void echo(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++)
        printf("%s%s", argv[i], i < argc-1 ? " " : "");
    printf("\n");

    while (--argc > 0)
        printf("%s%s", *++argv, argc > 1 ? " " : "");
    printf("\n");
}

int main(int argc, char *argv[])
{
    echo(argc, argv);
    printf(">...<\n");
    char nl = 1;
    if (argc > 1) {
        if (strcmp(argv[1], "-n") == 0) {
            --argc, ++argv, nl = 0;
        }
    }
    while (--argc > 0) {
        fprintf(stdout, "%s%s%s", *++argv, argc == 1 ? "" : " ",
                nl == 1 && argc == 1 ? "\n" : "");
    }
    return 0;
}
