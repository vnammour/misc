/* Tue Jul 14 11:39:49 AM IDT 2026 */
/* By: vnammour */
package main

import (
	"fmt"
)
var queue Queue[int]
const N = 32
func init() {
	queue = make(Queue[int], 0, N)
}
func main() {
	for i:= 0; i < N; i++ {
		queue.enqueue(i)
	}
	for !queue.isEmpty() {
		data,ok := queue.dequeue()
		if ok {
			fmt.Printf("%v\n", data)
		}
	}
}

type Queue[T any] []T
func (q *Queue[T]) enqueue(data T) {
	*q = append(*q, data)
}
func (q *Queue[T]) dequeue() (T,bool) {
	var zero T
	if len(*q) == 0 {
		return zero,false
	}
	data := (*q)[0]
	(*q)[0] = zero
	*q = (*q)[1:]
	return data,true
}
func (q *Queue[T]) isEmpty() bool {
	return len(*q) == 0
}
