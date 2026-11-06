/* Thu Nov  5 02:35:27 PM IST 2026 */
/* By: vnammour */
// For heapsort, we use a max-heap where:
// A[parent(i)] >= A[i]
/*
height of a node in a heap: the number of edges on the longest simple downward
path from the node to a leaf.
height of heap: the height of its root.
Since a heap of n elements is based on a complete binary tree, its height is
O(lg n).
Basic heap operations run in time at most proportional to the height of the
tree and thus take O(lg n) time.
max-heapify: runs in O(lg n) time, it the key to maintaining the max-heap
property.
build-max-heap: runs in linear time, produces a max-heap from an unordered input
array.
heapsort: runs in O(n lg n) time, sorts an array in place.
max-heap-insert, heap-extract-max, heap-increase-key, and heap-maximum,
run in O(lg n) time, allow the heap data structure to be used as a priority queue.
*/
package main
import (
	"fmt"
)
func main() {
	// arr := []int{3,25,1,20,2}
	// arr := []int{1,5,8,13,17,22,31}
	N := 1000000000
	arr := make([]int,N)
	for i:=0; i < N; i++ {
		arr[i] = i
	}
	count := buildmaxheap(arr)
	// fmt.Println(arr)
	fmt.Printf("count = %d\n", count)
	fmt.Printf("count = %d\n", 2*N-count)
}

func buildmaxheap(arr []int) int {
	i := (len(arr)-1) >> 1
	count := 0
	for i >= 0 {
		count++
		count += heapify(arr,i,len(arr))
		i--
	}
	return count
}

func heapify(arr []int, i, maxlen int) int {
	count := 0
	for i < maxlen {
		count++
		index := i
		left := i<<1+1
		right := left+1
		if left < maxlen && arr[left] > arr[index] {
			index = left
		}
		if right < maxlen && arr[right] > arr[index] {
			index = right
		}
		if index == i {
			return count
		}
		arr[i],arr[index] = arr[index],arr[i]
		i = index
	}
	return count
}
