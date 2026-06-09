/* Sun Jun  7 09:23:16 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
void squeeze(char *s, char *t);
int any(char *s1, char *s2);
int main(int argc, char *argv[])
{
    char s[] = "aonebtwocthree";
    char t[] = "abc";
    squeeze(s,t);
    printf("%s\n", s);
    char *s2 = "xxx";
    printf("%d\n", any(s,s2));
}

// Ex2-4: Write an alternate version of squeeze(s1,s2) that deletes each character in s1 that
// matches any character in the string s2
void squeeze(char *s, char *t) {
    for (int i = 0; t[i] != '\0'; i++) {
	    int j = 0;
        int c = t[i];
	    for (int i = 0; s[i] != '\0'; i++)
	        if (s[i] != c) s[j++] = s[i];
	    s[j] = '\0';
    }
}

// Ex2-5: Write the function any(s1,s2), which returns the first location in the string s1
// where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
// (The standard library function strpbrk does the same job but returns a pointer to the location.)
int any(char *s1, char *s2) {
    for (int i = 0; s2[i] != '\0'; i++)
        for (int j = 0; s1[j] != '\0'; j++)
            if (s1[j] == s2[i]) {
                return j;
            }
    return -1;
}
