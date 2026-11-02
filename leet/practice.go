/* Sat Oct 31 05:25:11 AM IST 2026 */
/* By: Tia Nammour */
package main
import (
	"fmt"
)
// {1,2,3,4,5,6}, k = 2
// {3, 4, 5, 6, 1, 2}
/*
reverse(arr): {6,5,4,3,2,1}
reverse(arr[:4]): {3,4,5,6,2,1}, 4 = len - k
reverse(arr[4:]): {3,4,5,6,1,2}, 4 = len - k 
*/
func rotate(arr []int, k int) {
	if len(arr) <= k || k <= 0 {
		return
	}
	/*reverse(arr)
	reverse(arr[:len(arr)-k])
	reverse(arr[len(arr)-k:])*/
	reverse(arr[k:])
	// reverse(arr[len(arr)-k:])
}
func reverse(arr []int) {
	for i,j := 0, len(arr)-1; i < j; i,j = i+1, j-1 {
		arr[i],arr[j] = arr[j],arr[i]
	}
}
func main() {
	arr := []int{1,2,3,4,5,6}
	rotate(arr,2)
	fmt.Println(arr)
}
