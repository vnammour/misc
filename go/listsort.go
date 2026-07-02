/* Mon Jun 29 02:42:03 PM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	data := []int{6,4,2,5,3}
	var p *NodeI
	for i := 0; i < len(data); i++ {
		p = datapushback(p,data[i])
	}
	Print(p)
	p = ListSort(p)
	Print(p)
}

type NodeI struct {
	Next *NodeI
	Data int
}

// selection sort
func ListSort(l *NodeI) *NodeI {
	if l == nil {
		return l
	}
	var head *NodeI = &NodeI{l,0}
	var h *NodeI = &NodeI{}
	var px,x,p *NodeI
	for {
		if head.Next == nil {
			break
		}
		var t *NodeI
		for px,x,p = head,head.Next,head.Next; x != nil; px,x = x,x.Next {
			if x.Data <= p.Data {
				p = x
				t = px
			}
		}
		t.Next, p.Next = p.Next, nil
		h = pushback(h,p)
	}
	head,head.Next = nil,nil
	h,h.Next = h.Next,nil
	return h
}

func datapushback(h *NodeI, data int) *NodeI {
	node := new(NodeI{nil,data})
	if h == nil {
		return node
	}
	var p *NodeI
	for q := h; q != nil; p,q = q,q.Next {
	}
	p.Next = node
	return h
}

func pushback(h, n *NodeI) *NodeI {
	if n == nil {
		return h
	}
	var p *NodeI
	for q := h; q != nil; p,q = q,q.Next {
	}
	p.Next = n
	return h
}

func Print(p *NodeI) {
	for ;p != nil; p = p.Next {
		fmt.Printf("%v->", p.Data)
	}
	fmt.Printf("%v\n", nil)
}
