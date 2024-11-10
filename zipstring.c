/* Fri Nov  8 10:41:17 PM IST 2024 */
/* By: Victor Nammour */
#include <stdio.h>
#include <math.h>   // for log10
#include <string.h> // for strtok, strlen
#include <stdlib.h> // for malloc
char* zipstring(char *str);
int main(int argc, char *argv[])
{
   char *s = "yank thhheeee yank but   leave the blank.";
   //char *s = "YouuungFellllas";
   //char *s = "Thee quuick browwn fox juumps over the laaazy dog";
   //char *s = "Helloo Therre!";
   printf("orig: %d\n%s\n", strlen(s), s);
   char *mod = zipstring(s);
   if (mod == 0) {
   	fprintf(stderr, "zipstring returned null.\n");
   	return EXIT_FAILURE;
   }
   printf("zipped: %d\n%s\n", strlen(mod),mod);
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
   int total_len = 0, len, j;
   for (j = 0, len = 0; ; dupstr = 0, j++, len = 0) {
      token = strtok_r(dupstr,delim,&saveptr);
      if (token == 0) break;
      //printf("--------%s\n", token);
      char *t;
      for (t = token; *t != 0; t++) bytes[*t]++;
      for (t = token; *t != 0; t++) {
         if(bytes[*t] != 0) 
            len +=  (int)log10(bytes[*t]) + 1;
         else ++len; // to account for the duplicate character
         bytes[*t] = 0; // zero entries for next token
      }
      len += t - token + 1; // +1 for string initializer 
      //printf("len = %d\n", len);
      total_len += len;
   }
   if (temp !=0) free(temp); // temp pointing to dupstr
   // I have j blanks for the words, add one for string initializer.
   // below statement is equivalent to total_len = total_len - (j - 1)
   total_len -= j - 1;
   total_len += strlen(str); // to account for a max # of blanks.
   //printf("\nj = %d, total_len = %d\n", j, total_len);
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
   return zippedstring;
}
