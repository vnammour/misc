/* Sat Nov  9 11:35:13 AM IST 2024 */
/* By: Victor Nammour */
#include <stdio.h>
#include <stdlib.h> // for strtol, malloc
#include <string.h> // for strlen
#include <ctype.h>  // for isspace
#include <errno.h>  // for errno
/* returns -1 for invalid input; otherwise returns length of array.
   sum's value is stored in sum, and number array in *numarr.
   numarr in form (e.g.): "[1,2,3,4]".
   But I allow spaces before and after the '[', ']', and the commas and digits.
*/
int parseargs(int argc, char **argv, int **numarr, int *sum)
{
  *numarr = 0; // initialize to null
  static char *usage = "Usage: findpairs \"[number,number...]\" \"sum\"\n";
  static char *invalidInput = "Invalid input";
  static char *invalidTargetSum = "Invalid target sum";
  static char *invalidNumber = "Invalid number";	
  if (argc != 3) {
     fprintf(stderr,"%s\n", invalidInput);
     fprintf(stderr,"%s\n", usage);
     return -1;
  }
  // get the target sum
  errno = 0;	
  char *endptr;
  if (strlen(argv[--argc]) == 0) { // now argc = 2
     fprintf(stderr,"%s\n", invalidTargetSum);
     return -1;
  }
  *sum = strtol(argv[argc], &endptr, 10);
  if (*endptr != 0) {
     fprintf(stderr,"%s: %s\n", invalidTargetSum,argv[argc]);
     return -1;
  }
  // get the number array
  int len = strlen(argv[--argc]); // now argc = 1
  // truncate string at terminating ']'
  char *p = argv[argc] + len;
  while (isspace(*--p));
  if (*p != ']') {
     fprintf(stderr,"%s: %s\n", invalidInput, argv[argc]);
     return -1;
  }
  *p = '\0';
  // Right before ']' should be a digit, or spaces then digit
  while (isspace(*--p));
  //printf("vjn: *p = >%c<\n", *p);
  if (!isdigit(*p)) { 
     fprintf(stderr,"%s\n", invalidInput);
     return -1;
  }
  // skip blanks at beginning if any.
  argv +=argc; // to make argv point at array
  while (isspace(*argv[0])) ++*argv;
  // check for opening bracket
  if (**argv != '[') {
     fprintf(stderr,"%s\n", invalidInput);
     return -1;
  }
  ++*argv; // skip opening bracket
  while (isspace(*argv[0])) ++*argv;
  if (!isdigit(**argv)) {
     fprintf(stderr,"%s\n", invalidInput);
     return -1;
  }
  // update potential length of numarr
  if (p > *argv) len = p - *argv;
  else { // it means that the input array was like "[]"
     fprintf(stderr,"%s\n", invalidInput);
     return -1;
  }
  //printf("vjn: parseargs: len = %d: %s\n", len, argv[0]);
  *numarr = (int*) malloc(sizeof(int) * len);
  if (*numarr == 0) { 
     fprintf(stderr, "Not enough memory!\n");
     return -1;
  }
  int j; // this will keep track of tokens read
  endptr = 0; errno = 0;
  char *saveptr, *token;
  for (j = 0; j<len; j++, argv[0] = 0) {
     token = strtok_r(argv[0],",",&saveptr);
     if (token == 0) {
         if (j==0) {	// array is empty
            fprintf(stderr,"%s\n", invalidInput);
            free(*numarr); return -1;
	 }
	 break;
     }
     //printf("vjn: saveptr = >%s<\n", saveptr);
     char *t = saveptr;
     while (isspace(*t)) ++t;
     if (*t != '\0' && !isdigit(*t)) {
        fprintf(stderr,"%s\n", invalidInput);
        free(*numarr); return -1;
     } 
     errno = 0;
     (*numarr)[j] = strtol(token,&endptr,10);
     //printf("vjn: endptr = >%s<\n", endptr);
     t = endptr;
     while (isspace(*t)) ++t;
     if (*t != 0) {
	 fprintf(stderr,"%s: %s\n",invalidNumber, endptr);
         free(*numarr);
         return -1;
      }
   }
   // at this point all is well. I'll resize numarr according to tokens
   len = j, errno = 0;
   //printf("vjn: parseargs: at this point, j = %d\n", j);
   *numarr = (int*) reallocarray(*numarr,len,sizeof(int));
   if (*numarr == 0) {
      len = -1;
      fprintf(stderr, "Errno %d: Not enough memory!\n", errno);
   }
   return len;
}
