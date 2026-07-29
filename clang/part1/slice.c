/* Thu Jun 11 07:35:40 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strdup

typedef struct {
    const char *data;
    size_t count;
} String_View;

String_View sv(const char* cstr) {
    // String_View view = {.data=cstr, .count=strlen(cstr),};
    // return view;
    return (String_View) {
        .data = cstr,
        .count = strlen(cstr),
    };
}

void sv_chop_right(String_View *sv) {
    if (sv->count > 0) sv->count -= 1;
}

void sv_chop_left(String_View *sv) {
    if (sv->count > 0) {
        sv->count -= 1;
        sv->data += 1;
    }
}

void intro() {
    char *t = "Hello, World";
    printf("sizeof(t) = %zu\n", sizeof(t));
    printf("%s\n", t);
    int n = strlen(t);
    printf("n = %d\n", n);
    printf("%p\n", t);
    {
	    char *s = strdup("Hello, World");
	    int n = strlen(s);
	    printf("%s\n", s);
        s[n-1] = 0;
	    printf("%s\n", s);
	    printf("sizeof(s) = %zu\n", sizeof(s));
	    free(s);
    }
}

void try_sv() {
    String_View s = sv("Hello World");
    printf("%s\n", s.data);
    sv_chop_right(&s);
    sv_chop_left(&s);
    printf("%s\n", s.data);
    printf("%.*s\n", (int)s.count,s.data);
}

int main(int argc, char *argv[])
{
    // intro();
    try_sv();
    return 0;
}
