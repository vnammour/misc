/* Tue Nov 17 03:46:15 PM IST 2026 */
/* By: vnammour */
package main
import (
	"fmt"
	"math"
)
func main() {
	// testarraysums()
	rows := 14
	var curr []int = make([]int,0,rows+3)
	curr = curr[:2]
	curr[0], curr[1] = 1,1
	for i := 0; i < rows; i++ {
		fmt.Printf("%*.*s", rows-i-1,rows-i-1," ")
		printints(curr,int(math.Log(float64(curr[len(curr)/2]) + 1)))
		curr = arraysums(curr)
		fmt.Println()
	}
}

func printints(arr []int, width int) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%*d ", width,arr[i])
	}
}

func arraysums(arr []int) []int {
	if cap(arr) < len(arr) + 1 || len(arr) <= 1 {
		return arr
	}
	arr = arr[:len(arr)+1]
	p,q := arr[0],arr[1]
	for i := 1; i < len(arr)-1; i++ {
		arr[i] = p + q
		p,q = q,arr[i+1]
	}
	arr[len(arr)-1] = arr[0]
	return arr
}
func testarraysums() {
	arr := make([]int,0,6)
	arr = append(arr,[]int{1,4,6,4,1}...)
	arr = arraysums(arr)
	printints(arr, 2)
}
/*
	// print format trials...
	// fmt.Printf("%.*s\n", 0, "0")
	/*for rows := 4; rows > 0; rows-- {
		// fmt.Printf("%*.*s\n", rows-1,rows-1,"1")
		fmt.Printf("%*.*s ",rows-1,rows-1," ")
	}
	for i := 0; i < rows; i++ {
		fmt.Printf("%*.*s", rows-i-1,rows-i-1," ")
		for j := i+1; j >= i; j-- {
			fmt.Printf("%d ",1)
		}
		fmt.Println()
	}
*/
