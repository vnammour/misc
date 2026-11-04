/* Sat Oct 31 01:15:55 PM IST 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
const intsize = 32 << (^uint(0) >> 63) // 32 or 64
const maxint = 1 << (intsize - 1) - 1
const minint = -1 << (intsize - 1)

// {-3,-2,-1,0,4,5,7}
// {9,4,1,0,16,25,49} wrong
// {0,1,4,9,16,25,49} correct
func abs(num int) (int,bool) { // return false if overflow
	if num < 0 {
		if num == minint {
			return num,false
		}
		return num * -1, true
	}
	return num, true
}

func sortedsquares(arr []int) []int {
	squares := make([]int,len(arr))
	for i,j, k := 0, len(arr)-1, len(arr)-1; i <= j; k-- {
		abs_i, ok := abs(arr[i])
		if !ok {
			return nil
		}
		abs_j, ok := abs(arr[j])
		if !ok {
			return nil
		}
		if abs_i != 0 && abs_i > maxint/abs_i {
			return nil
		}
		if abs_j != 0 && abs_j > maxint/abs_j {
			return nil
		}
		if abs_j >= abs_i {
			squares[k] = abs_j * abs_j
			j--
		} else {
			squares[k] = abs_i * abs_i
			i++
		}
	}
	return squares
}

func main() {
	arr := []int{-3,-2,-1,0,4,5,7}
	squares := sortedsquares(arr)
	fmt.Printf("%v\n", squares)
}
