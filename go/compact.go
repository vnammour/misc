/* Tue Jun  9 04:47:43 PM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	slice := []string{"zero","","two","three","","five",""}
	count := compact(&slice)
	fmt.Printf("%q\n", slice)
	fmt.Printf("%d\n", count)
}

func compact(ptr *[]string) int {
     k := 0
     for _, elem := range *ptr {
         if len(elem) != 0 {
             (*ptr)[k] = elem
             k++
         }
     }
     *ptr = (*ptr)[:k]
     return len(*ptr)
 }
