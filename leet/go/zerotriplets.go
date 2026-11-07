/* Sat Nov  7 05:19:44 PM IST 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
type Node[T any] struct {
	Data T
	Next *Node[T]
}
// var m map[any]any
func main() {
	arr := []int{1,0,2,-1,3,-5}
	ht := make(map[int]*Node[int],len(arr))
	for i:=0; i < len(arr); i++ {
		node := new(Node[int]{i,nil})
		if n,ok := ht[arr[i]]; !ok {
			ht[arr[i]] = node
		} else {
			n.Next = node
		}
	}

	for i := 0; i < len(arr); i++ {
		for j := i + 1; j < len(arr); j++ {
			sum := 0 - arr[j] - arr[i]
			if _,ok := ht[sum]; ok {

			}
		}
	}
}

func compare(a,b any) int {
	switch va := a.(type) {
	case int:
		vb := b.(int)
		if va < vb {
			return -1
		}
		return map[bool]int{true: 1, false: 0} [ va > vb ]
	default:
		panic(fmt.Sprintf("unsupported type for comparison: %T", va))
	}
}

func plucknode(m map[any]*Node[any], key any) *Node[any] {
	return nil
}

// func plucknode(m map[any]any, key any) { }
