/* Fri Oct 30 06:31:02 PM IST 2026 */
/* By: vnammour */
package ds
import (
	"fmt"
)
const initialcapacity = 32
type QueueArray[T any] struct {
	arr []T
}

func (q *QueueArray[T]) Enqueue(data T) {
	if q == nil {
		return
	}
	if q.arr == nil {
		q.arr = make([]T,0,initialcapacity)
	}
	q.arr = append(q.arr,data)
}

func (q *QueueArray[T]) Dequeue() (T,bool) {
	var zero T
	if q == nil || q.arr == nil || len(q.arr) == 0 {
		return zero, false
	}
	data := q.arr[0]
	q.arr[0] = zero
	q.arr = q.arr[1:]
	return data,true
}

func (q *QueueArray[T]) Print() {
	if !q.IsEmpty() {
		for i := 0; i < len(q.arr); i++ {
			if i == len(q.arr)-1 {
				fmt.Printf("%v\n", q.arr[i])
			} else {
				fmt.Printf("%v, ", q.arr[i])
			}
		}
	}
}

func (q *QueueArray[T]) IsEmpty() bool {
	return q == nil || q.arr == nil || len(q.arr) == 0
}
