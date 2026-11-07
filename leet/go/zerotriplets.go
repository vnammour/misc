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
// time: O(n^2)
// Space: O(n)
func main() {
	arr := []int{4,4,2,-1,3,-5}
	ht := make(map[int]*Node[int],len(arr))
	for i:=0; i < len(arr); i++ {
		node := new(Node[int]{i,nil})
		if n,ok := ht[arr[i]]; !ok {
			ht[arr[i]] = node
		} else {
			n.Next = node
		}
	}

	var a *Node[int]
	done := false
	for i := 0; i < len(arr) && !done; i++ {
		for j := i + 1; j < len(arr) && !done; j++ {
			sum :=  -arr[i] - arr[j]
			if node,ok := ht[sum]; ok && node.Data != j {
				a = plucknode(ht,arr[i],i)
				b := plucknode(ht,arr[j],j)
				c := plucknode(ht,sum,node.Data)
				a.Next = b
				b.Next = c
				done = true
			}
		}
	}
	printlist(a)
}

func printlist(node *Node[int]) {
	for node != nil {
		fmt.Printf("%v->", node.Data)
		node = node.Next
	}
	fmt.Printf("%v\n",node)
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

// func plucknode(m map[any]any, key any) { }
// (-)->a->b->c-/
func plucknode(m map[int]*Node[int], key, data int) *Node[int] {
	var prev,nxt *Node[int]
	for prev,nxt = nil, m[key]; nxt != nil && nxt.Data != data;
		prev,nxt = nxt, nxt.Next {}
	if prev != nil {
		prev.Next, nxt.Next = nxt.Next, nil
	}
	return nxt
}
