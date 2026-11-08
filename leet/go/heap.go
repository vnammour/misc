/* Sun Nov  8 02:21:37 PM IST 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	arr := []int{16,4,10,14,7,9,3,2,8,1}
	buildmaxheap(arr)
	fmt.Println(arr)
}

func heapify(arr []int, i int) {
	for i < len(arr) {
		index := i
		left := i<<1 + 1
		right := left + 1
		if left < len(arr) && arr[index] < arr[left] {
			index = left
		}
		if right < len(arr) && arr[index] < arr[right] {
			index = right
		}
		if index == i {
			break
		}
		arr[i],arr[index] = arr[index],arr[i]
		i = index
	}
}

func rheapify(arr []int, i int) {
	index := i
	left := i<<1+1
	right:= left+1
	if left < len(arr) && arr[index] < arr[left] {
		index = left
	}
	if right < len(arr) && arr[index] < arr[right] {
		index = right
	}
	if index != i {
		arr[i],arr[index] = arr[index],arr[i]
		rheapify(arr,index)
	}
}

/*
The elements in the subarray arr[len(arr)/2:len(arr)]
are all leaves of the tree, and so each is a 1-element
heap to begin with.
*/
func buildmaxheap(arr []int) {
	for i := (len(arr)-1)/2; i >= 0; i-- {
		rheapify(arr,i)
	}
}
