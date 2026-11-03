/* Fri Oct 30 06:31:02 PM IST 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	q := qinit(3);
	q.arr = append(q.arr,[]int{1,3}...)
	fmt.Printf("%p\n", &q)
	q = noth(q)
	q.sth()
	fmt.Println(q.arr)
}
type Queue struct {
	arr []int
	h *int
	t *int
}

func noth(q Queue) Queue {
	q.arr = append(q.arr, 13);
	fmt.Printf("%p\n", &q)
	return q
}

func qinit(size int) Queue {
	var q Queue;
	q.arr = make([]int, 0, size);
	// q.h = &(q.arr)[0]
	// q.t = &(q.arr)[0]
	return q;
}
