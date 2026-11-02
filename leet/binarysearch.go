/* Sun Nov  1 07:05:01 PM IST 2026 */
/* By: Tia Nammour */
package main
import (
	"fmt"
)
func sort(arr []int) {
	for i := 0; i < len(arr); i++ {
		for j := 1; j < len(arr); j++ {
			if arr[j-1] > arr[j] {
				arr[j], arr[j-1] = arr[j-1], arr[j]
			}
		}
	}
}
func binsrch(arr []int, value int) int {
	low, high := 0, len(arr)-1
	for low <= high {
		mid := low + (high - low)/2
		if value < arr[mid] {
			high = mid - 1
		} else if value > arr[mid] {
			low = mid + 1
		} else {
			return mid
		}
	}
	return -1
}
func main() {
	arr := []int{5,2,1,-3,-4, 10}
	sort(arr)
	fmt.Printf("%v\n", arr)
	index := binsrch(arr,2)
	fmt.Printf("%d\n", index)
}
