/* Fri Jun  5 06:05:30 PM IDT 2026 */
/* By: vnammour */
package main

import (
	"fmt"
)

func main() {
	fmt.Printf("%v", stringtointslice("A quick brown fox jumps over the lazy dog"))
}

func stringtointslice(s string) []int {
	buf := make([]int,len(s))
	i := 0
	for _,r := range s {
		buf[i] = int(r)
		i++
	}
	return buf[:i]
}
