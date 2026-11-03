/* Sat Oct 31 12:30:04 PM IST 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func prefixsum(arr []int) []int {
	sum := make([]int,len(arr))
	sum[0] = arr[0]
	for i := 1; i < len(arr); i++ {
		sum[i] += sum[i-1] + arr[i]
	}
	return sum
}
func main() {
	arr := []int{1,2,3,4,5}
	sum := prefixsum(arr)
	fmt.Printf("%v\n", sum)
}
