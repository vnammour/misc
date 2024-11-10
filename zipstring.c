/* Fri Nov  8 10:41:17 PM IST 2024 */
/* By: Victor Nammour */
#include <stdio.h>
#include <math.h>   // for log10
#include <string.h> // for strtok, strlen
#include <stdlib.h> // for malloc
char* zipstring(char *str);
int main(int argc, char *argv[])
{
   //char *s = "yank thhheeee yank but   leave the blank.";
   //char *s = "YouuungFellllas";
   char *s = "Thee quuick browwn fox juumps over the laaazy dog";
   //char *s = "Helloo Therre!";
   printf("original string: strlen: %d\n%s\n", strlen(s),s);
   char *mod = zipstring(s);
   if (mod == 0) {
   	fprintf(stderr, "zipstring returned null.\n");
   	return EXIT_FAILURE;
   }
   printf("zipped: strlen: %d\n%s\n", strlen(mod),mod);
   free(mod);
   return EXIT_SUCCESS;
}

/* strdup would crash if argument string is null. */
char* zipstring(char *str)
{
   if (str == 0) return 0;
   int bytes[128] = {0};
   char *dupstr = strdup(str), *temp = dupstr;
   if (dupstr == 0) {
      fprintf(stderr, "strdup returned NULL.\n");
      return 0;
   }
   char *delim = " ";
   char *token, *saveptr;
   // total_len: stores the final length of zipped string.
   // len: stores intermediate length of tokens (space delimited words).
   // j: accumulates tokens parsed.
   int total_len = 0, len, j;
   // The idea here is to calculate the approximate size of the final zipped str.
   for (j = 0, len = 0; ; dupstr = 0, j++, len = 0) {
      token = strtok_r(dupstr,delim,&saveptr);
      if (token == 0) break;
      //printf("token: >%s<\n", token);
      char *t;
      for (t = token; *t != 0; t++) bytes[*t]++; // count frequency of chars
      // note that I zero frequency value of character after each iteration.
      for (t = token; *t != 0; bytes[*t++] = 0) {
         if(bytes[*t] != 0) // cannot take log of zero
            len +=  (int)log10(bytes[*t]) + 1;
      }
      // len now has the number of digits to be added to string
      // next I add the actual number of chars. E.g. "here" has 4 chars,
      // plus 4 digits, so length of final string will be 8: "1h1e1r1e"
      len += t - token;
      total_len += len;
   }
   if (temp !=0) free(temp); // temp pointing to dupstr
   // I'll remove j amount from total length since I'll add the length
   // of the original string to account for unaccounted number of blanks.
   // Alternate to adding length of original string, I can loop over it
   // and count number of blanks.
   total_len -= j - 1;
   total_len += strlen(str);
   // zip string
   char *zippedstring = (char*) malloc(total_len);
   char *z = zippedstring, *t = str;
   /* c to hold current character in string, and sp to count number
      of its occurrence.
   */
   int c, sp = 0;
   while (*t != 0 && z < zippedstring + total_len) {
      c = *t++, ++sp;
      while (c == *t) ++sp, ++t;
      if  (sp > 0) {
         z += sprintf(z,"%d%c",sp,c);
         sp = 0;
      }
   }
   *z = '\0';
   return zippedstring;
}
