/* Tue Nov  3 03:58:30 PM IST 2026 */
/* By: vnammour */
package ds
import (
	"fmt"
)
type linknode[T any] struct {
	datalink T
	nextlink *linknode[T]
}

type Queue[T any] struct {
	head *linknode[T]
}

func (q *Queue[T]) Enqueue(data T) {
	if q == nil {
		return
	}
	node := new(linknode[T]{datalink: data, nextlink: nil})
	var prev, next *linknode[T] = nil, q.head
	for ; next != nil; prev, next = next, next.nextlink{}
	if prev == nil {
		q.head = node
	} else {
		prev.nextlink = node
	}
}

func (q *Queue[T]) Dequeue() (T,bool){
	var zero T
	if q == nil || q.head == nil {
		return zero,false 
	}
	var temp *linknode[T]
	temp, q.head = q.head, q.head.nextlink
	data := temp.datalink
	temp, temp.nextlink = nil, nil
	return data, true
}

func (q *Queue[T]) Print() {
	if q != nil {
		for n := q.head; n != nil; n = n.nextlink {
			if n.nextlink == nil {
				fmt.Printf("%v\n", n.datalink)
			} else {
				fmt.Printf("%v, ", n.datalink)
			}
		}
	}
}

func (q *Queue[T]) IsEmpty() bool {
	return q == nil || q.head == nil
}

func testqueue() {
	q := new(Queue[int]{})
	for i := 0; i < 10; i++ {
		q.Enqueue(i)
	}
	q.Print()
	for !q.IsEmpty() {
		if data,ok := q.Dequeue(); ok {
			fmt.Printf("%v\n", data)
		}
	}
	q.Print()
}
