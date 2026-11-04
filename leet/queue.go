/* Tue Nov  3 05:21:58 PM IST 2026 */
/* By: vnammour */
package main
import (
	"ds"
	"fmt"
)

func main() {
	fmt.Println("QueueList")
	q := new(ds.Queue[int]{})
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
	fmt.Println()
	fmt.Println("QueueArray")
	qq := new(ds.QueueArray[int]{})
	for i := 0; i < 10; i++ {
		qq.Enqueue(i)
	}
	qq.Print()
	for !qq.IsEmpty() {
		if data,ok := qq.Dequeue(); ok {
			fmt.Printf("%v\n", data)
		}
	}
	qq.Print()
}
