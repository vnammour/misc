/* Mon Jun  8 11:02:46 PM IDT 2026 */
/* By: Jamil Nammour */
package main
import (
	"fmt"
)
func main() {
	x := uint(0xaf)
	fmt.Printf("%#08b\n", x)
	// y := getbit(x,5,3)
	// fmt.Printf("%#08b\n", y)
	y := rotate(x,3,4)
	fmt.Printf("%#b\n", y)
	y = 0
	fmt.Println()
	fmt.Printf("%#08b\n", x)
	for x != 0 {
		y  = (y << 1) | (x % 2)
		x /= 2

	}
	fmt.Printf("%#b\n", y)
}

func getbit(x uint, p, n int) uint {
	return (x>>(p-n+1)) & ^(^uint(0)<<(p-n+1))
}

// rotate: rotate x n bits starting from position p
func rotate(x uint, p,n int) uint {
	a := (x & ^(^uint(0)<<n)) <<n
	b := x >> n
	fmt.Printf("%#08b\n", a)
	fmt.Printf("%#08b\n", b)
	return a | b
}
