/* Sat Oct 31 01:11:54 PM IST 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)

func ispalindrome(s string) bool {
	for i,j := 0, len(s)-1; i < j; i,j = i+1, j-1 {
		if s[i] != s[j] {
			return false
		}
	}
	return true
}
func main() {
	fmt.Printf("%v\n", ispalindrome("racecar"))
}
