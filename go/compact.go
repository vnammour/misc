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

func compact(s *[]string) int {
	count := 0
	j := 0
	for i := 0; i < len(*s); i++ {
		if len((*s)[i]) != 0 {
			(*s)[j] = (*s)[i]
			j++
		} else {
			count++
		}
	}
	*s = (*s)[:j]
	return count
}
