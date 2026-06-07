/* Fri May 22 10:34:51 AM IDT 2026 */
/* By: vnammour */
package piscine

import (
// "fmt"
)

/*func main() {
	arr := []int{0,0,0,0,8,10,9,8,7,5,6,0}
	fmt.Println(IsSorted(compare,arr))
}*/

func IsSorted(f func(a, b int) int, a []int) bool {
	if len(a) == 0 || len(a) == 1 {
		return true
	}
	var cmp, i int
	for i = 1; i < len(a); i++ {
		if cmp = compare(a[i-1], a[i]); cmp != 0 {
			break
		}
	}

	for ; i < len(a); i++ {
		switch {
		case cmp > 0: // descending
			if compare(a[i-1], a[i]) < 0 {
				return false
			}
		case cmp < 0: // ascending
			if compare(a[i-1], a[i]) > 0 {
				// fmt.Println("a[i-1] =",a[i-1],", a[i] =",a[i])
				return false
			}
		}
	}
	return true
}

func compare(a, b int) int {
	return a - b
}
