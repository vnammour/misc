/* Mon Jun 29 01:43:27 PM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	data := []int{2,3,6,11}
	data2 := []int{3,5,10}
	var p *NodeI
	var q *NodeI
	for i := 0; i < len(data); i++ {
		p = pushback(p,data[i])
	}
	for i := 0; i < len(data2); i++ {
		q = pushback(q,data2[i])
	}
	Print(p)
	Print(q)
	p = SortedListMerge(p,q)
	Print(p)
}

type NodeI struct {
	Next *NodeI
	Data int
}
func pushback(n *NodeI, data int) *NodeI {
	node := &NodeI{nil,data}
	if n == nil {
		return node
	}
	var t,p *NodeI = nil, n
	for ; p != nil; t, p = p, p.Next {
	}
	t.Next = node
	return n
}
// Assumption: both lists are sorted.
func SortedListMerge(n1 *NodeI, n2 *NodeI) *NodeI {
	if n1 == nil {
		return n2
	} else if n2 == nil {
		return n1
	}
	var p,q *NodeI = n1, n2
	// I want p to point to node with minimum data at all times
	if p.Data > q.Data {
		p,q = q,p
	}
	h, t := p, p
	for p != nil && q != nil {
		if p.Data <= q.Data {
			t = p
			p = p.Next
		} else {
			t.Next = q
			if p.Data > q.Data {
				p,q = q,p
			}
		}
	}
	t.Next = q
	return h
}

func Print(p *NodeI) {
	for ;p != nil; p = p.Next {
		fmt.Printf("%v->", p.Data)
	}
	fmt.Printf("%v\n", nil)
}
