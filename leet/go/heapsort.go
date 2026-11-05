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
)
func main() {
}
