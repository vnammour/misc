/* Fri Jun  5 12:40:57 PM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	// a := []int{1,2,3,1,2,3,4,4,0,0}
	a := []int{1,2,3,1,1,2,3,3}
	fmt.Printf("%d\n", unmatch(a))
}

func unmatch(a []int) int {
	unique_xor := 0
	zero_count := 0
	for _,v := range a {
		if v == 0 {
			zero_count++
		}
		unique_xor ^= v
	}
	if unique_xor == 0 && zero_count % 2 == 0 {
		return -1
	}
	return unique_xor
}
