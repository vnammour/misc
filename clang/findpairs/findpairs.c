/* Sun Nov 10 02:50:17 AM IST 2024 */
/* By: Victor Nammour */
#include <stdio.h>
#include <stdlib.h> // for malloc/calloc
typedef struct node {
	int index, value;
	int first,second;
	struct node *next;
} node;
node *findpairs(int *arr, int n, int sum);
int parseargs(int,char**,int**,int*);
int main(int argc, char *argv[])
{
   //int numarr[] = {-1,2,10,100,1000,222,3,5,7}; int sum = 15;
   //int numarr[] = {1,2,3,4,5}; int sum = 10;
   //int numarr[] = {-1,2,-3,4,-5}; int sum = 1;
   //int numarr[] = {-1,-2,-3,-4,-5}; int sum = -5;
   //int numarr[] = {1,2,3,4,5,3}; int sum = 6;
   //int numarr[] = {1,1,1,2,2}; int sum = 3;
   //int numarr[] = {2,2,2,2,2}; int sum = 4;
   //int n = sizeof numarr/sizeof numarr[0];
   int sum, *numarr;
   int n = parseargs(argc,argv,&numarr,&sum);
   if (n < 0) return EXIT_FAILURE;
   //printf("n = %d, sum = %d\n", n, sum);
   node *ans = findpairs(numarr,n,sum);
   if (ans == 0)
      printf("No pairs found.\n");
   else {
      printf("[");
      for (node *h = ans; h != 0; h = h->next)
         printf("[%d,%d]%s", h->first,h->second, h->next != 0 ? " ":"]\n");
   }
}
static node *add(node *p, int i, int j)
{
   if (p == 0) return p;
   p = (p->next = malloc(sizeof *p));
   if (p == 0) { fprintf(stderr,"Not enough memory!"); return p; }
   p->next = 0;
   p->first = i, p->second = j;
   return p;
}
static int hash(int value, int mod)
{
   if (value < 0) value *= -1;
   return value % mod;
}
node *findpairs(int *arr, int n, int sum) {
   // initialize a head pointer to form linked list of potential pairs.
   node *h = (node*) malloc(sizeof *h);
   h->index = h->value = h->first = h->second = -1, h->next = 0;
   node *link = h;
   node **hs = (node**) calloc(n,sizeof *hs);
   // reverse loop so collision indicies would be last
   // in sub-linkedlist at given key.
   for (int i = n-1, key; i >= 0; i--) {
      key = hash(arr[i],n);
      if (hs[key] == 0) {
         hs[key] = (node*) malloc(sizeof *hs[key]);
         hs[key]->index = i, hs[key]->value = arr[i]; 
         hs[key]->next = 0;
      } else {
         node *link = (node*) malloc(sizeof *link);
         link->index = i, link->value = arr[i];
         link->next = hs[key];
         hs[key] = link;
      }
   }
   for (int i = 0, key; i < n; i++) {
      node *ptr = hs[key = hash(sum-arr[i], n)]; 
      /* Check that indices are different, because in a hashset, 
         collisions can occur, and I don't want to pair an element
         with itself.
         Every i that gets processed has it's corresponding node's index
         entry in the hashset set to -1, which is not a valid array index.
         This is to ensure that no element gets processed more than once.
      */
      while (ptr != NULL) {
         if (ptr->index != i && ptr->index != -1) {
            if(arr[ptr->index] + arr[i] == sum) {
               link = add(link,i,ptr->index);
            }
         }
         ptr = ptr->next;
      }
      // Now, for arr[i], find it's corresponding node in hashset,
      // and set that node's index to -1 so it won't be processed again.
      for (ptr = hs[key = hash(arr[i],n)]; ptr != 0; ptr = ptr->next)
         if (ptr->index == i) {
            ptr->index = -1;
            break;
         }
   }
   // free memory in hashset
   for (node **hptr = hs; hptr < hs + n && hptr != 0; hptr++)   
      for (node *ptr = *hptr, *nxt = 0; ptr != 0; ptr = nxt) {
         nxt = ptr->next;
         free(ptr);
      }
   link = h->next;
   h->next = 0;
   free(h);
   return link;
}
