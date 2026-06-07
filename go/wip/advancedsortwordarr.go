/* Wed May 20 07:01:01 PM IDT 2026 */
/* By: vnammour */
package piscine
import (
	// "fmt"
)
/*func main() {
	words := []string{"a","A","1","b","B","2","c","C","3"}
	AdvancedSortWordArr(words,compare)
	fmt.Println(words)
}*/

func AdvancedSortWordArr(a []string, f func(a,b string) int) {
	for i := 1; i < len(a); i++ {
		for j := i; j > 0; j-- {
			if compare(a[j-1],a[j]) > 0 {
				a[j-1],a[j] = a[j], a[j-1]
			}
		}
	}
}

func compare(a,b string) int {
	if a == b {
		return 0
	} else if a < b {
		return -1
	} else {
		return 1
	}
}
