/* Thu Jun 11 07:35:40 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strdup
typedef struct {
    char *data;
    size_t count;
} String_View;
int main(int argc, char *argv[])
{
    // char *s = "Hello, World");
    char *s = strdup("Hello, World");
    int n = strlen(s);
    printf("%s\n", s);
    printf("sizeof(s) = %zu\n", sizeof(s));
    free(s);
    return 0;
}
