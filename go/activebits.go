/* Tue Jun 16 10:52:30 AM IDT 2026 */
/* By: vnammour */
package piscine

import (
	// "fmt"
)

/*func main() {
	n := minint + 1
	// fmt.Printf("%#b\n", n)
	count := ActiveBits(n)
	fmt.Printf("%d\n", count)
}*/

/*const (
	intsize = 32 << (^uint(0) >> 63)
	maxint = 1 << (intsize-1) -1
	minint = -1 <<(intsize -1)
)*/

func ActiveBits(n int) int {
	un := uint(n)
	// fmt.Printf("%#b\n", un)
	count := 0
	for un != 0 {
		un &= (un-1)
		count++
	}
	return count
}
