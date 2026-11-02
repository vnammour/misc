/* Sat Oct 31 06:08:52 PM IST 2026 */
/* By: Tia Nammour */
package main
import (
	"fmt"
)
type Stock struct {
	low, high int // indices in stock price array
	diff int
}
func maxprofit(arr []int) Stock {
	stock := Stock{0,0,0}
	left, right := 0, 0
	maxdiff := 0
	for right < len(arr) {
		if arr[left] < arr[right] {
			diff := arr[right]-arr[left]
			if diff > maxdiff {
				maxdiff = diff
				stock.low, stock.high = left, right
			}
		} else {
			left = right
		}
		right++
	}
	stock.diff = maxdiff
	return stock
}
// {7,1,5,3,6}
func main() {
	arr := []int{7,1,5,3,6}
	stock := maxprofit(arr)
	fmt.Printf("%v\n", stock)
	fmt.Printf("price at low = %d\n", arr[stock.low])
	fmt.Printf("price at high = %d\n", arr[stock.high])
	fmt.Printf("diff = %d\n", stock.diff)
}
