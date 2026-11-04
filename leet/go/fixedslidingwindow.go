/* Sat Oct 31 02:15:02 PM IST 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func maxsubarray(arr []int, k int) int {
	if k <= 0 || k > len(arr) {
		return 0
	}
	cursum := 0
	for i := 0; i < k; i++ {
		cursum += arr[i]
	}
	maxsum := cursum
	for i := 1; i + k - 1< len(arr); i++ {
		cursum += -arr[i-1] + arr[i+k-1]
		if cursum > maxsum {
			maxsum = cursum
		}
	}
	return maxsum
}
func maxsubarray2(arr []int, k int) int {
	if k <= 0 || k > len(arr) {
		return 0
	}
	cursum := 0
	for i := 0; i < k; i++ {
		cursum += arr[i]
	}
	maxsum := cursum
	left, right := 0, k
	for right < len(arr) {
		cursum += -arr[left] + arr[right]
		maxsum = max(maxsum,cursum)
		left, right = left + 1, right + 1
	}
	return maxsum
}
// {1, 5, 4, 2, 9}
func main() {
	arr := []int{1,5,4,2,9}
	m := maxsubarray(arr,3)
	fmt.Printf("%d\n", m)
	m = maxsubarray2(arr,3)
	fmt.Printf("%d\n", m)
}
