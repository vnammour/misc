/* Wed May 20 03:18:51 PM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	fmt.Println(Any(isnumeric,[]string{"hello", "123", "world"}))
	fmt.Println(Any(isnumeric,[]string{"hello", "12 3", "world"}))
}

func Any(f func(string) bool, a []string) bool {
	/*i := 0
	for ; i < len(a) && f(a[i]); i++ {
	}
	return i == len(a)*/
	for _,s := range a {
		if f(s) {
			return true
		}
	}
	return false
}

func isnumeric(s string) bool {
	for _,r := range s {
		if r < '0' || r > '9' {
			return false
		}
	}
	return true
}
