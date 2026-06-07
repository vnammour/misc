/* Fri Jun  5 05:16:52 PM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	fmt.Println(collatz(12))
}

func collatz(n int) int {
	if n <= 0 {
		return -1
	}
	count := 0
	for n != 1 {
		count++
		if n % 2 == 0 {
			n/=2
		} else {
			n = 3*n + 1
		}
	}
	return count
}
