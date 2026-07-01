/* Fri Jun 26 09:55:44 PM IDT 2026 */
/* By: vnammour */
package ds

import (
	"fmt"
	"reflect" // to check equality of two data interface types
)


type List struct {
	Head, Tail *Node
}

type Node struct {
	Data interface{}
	Next *Node
}

func (l *List) Size() int {
	if l == nil {
		return 0
	}
	size := 0
	for p := l.Head; p != nil; p = p.Next {
		size++
	}
	return size
}

func (l *List) SizeR() int {
	if l == nil || l.Head == nil {
		return 0
	}
	return recursiveSize(l.Head)
}

func recursiveSize(n *Node) int {
	if n == nil {
		return 0
	} else {
		return 1 + recursiveSize(n.Next)
	}
}

// selection sort
func (l *List) Sort() {
	if l == nil {
		return
	}
	for x := l.Head; x != nil; x = x.Next {
		p := x
		for y := x.Next; y != nil; y = y.Next {
			if compare(p.Data,y.Data) > 0 {
				p = y
			}
		}
		x.Data, p.Data = p.Data, x.Data
	}
}

func compare(v1, v2 interface{}) int {
	if reflect.TypeOf(v1) != reflect.TypeOf(v2) {
		return 0
	}
	switch v1.(type) {
	case int, byte, int8, int32:
		return v1.(int) - v2.(int)
	case float32,float64:
		if v1.(float64) - v2.(float64) < 0 {
			return -1
		} else if v1.(float64) - v2.(float64) > 0 {
			return 1
		} else {
			return 0
		}
	case string:
		if v1.(string) > v2.(string) {
			return 1
		} else if v1.(string) < v2.(string) {
			return -1
		} else {
			return 0
		}
	case *Circle:
		return v1.(*Circle).compare(v2.(*Circle))
		/*if v1.(*Circle).Radius > v2.(*Circle).Radius {
			return 1
		} else if v1.(*Circle).Radius < v2.(*Circle).Radius {
			return -1
		} else {
			return 0
		}*/
	default: return 0
	}
}

func (l *List) Pushback(data interface{}) {
	if l == nil {
		return
	}
	node := &Node{data, nil}
	if l.Head == nil {
		l.Head = node
	} else {
		var p, n *Node = nil, l.Head
		for ; n != nil; p, n = n, n.Next {
		}
		p.Next = node
	}
	l.Tail = node
}

func (l *List) Pushfront(data interface{}) {
	if l == nil {
		return
	}
	node := &Node{data, nil}
	if l.Head == nil {
		l.Head, l.Tail = node, node
	} else {
		node.Next, l.Head = l.Head, node
	}
}

func (l *List) Print() {
	if l == nil {
		return
	}
	for n := l.Head; n != nil; n = n.Next {
		fmt.Printf("%v->", n.Data)
	}
	fmt.Printf("%v\n", nil)
}

func PrintNodes(h *Node) {
	if h == nil {
		return
	}
	for h != nil {
		fmt.Printf("%v->", h.Data)
		h = h.Next
	}
	fmt.Printf("%v\n", nil)
}

func (l *List) Clear() {
	if l == nil {
		return
	}
	for p,n := l.Head, l.Head; n != nil; n = p {
		p, n.Next = n.Next, nil
	}
	l.Head, l.Tail = nil, nil
}

func (l *List) Reverse() {
	if l == nil || l.Head == nil {
		return
	}
	var x,y,z *Node = l.Head, l.Head.Next, nil
	for y != nil {
		z = y.Next
		y.Next = x
		x,y = y,z
	}
	l.Head.Next = nil
	l.Head, l.Tail = x, l.Head
}

func SortMergeNodes(p,q *Node) *Node {
	if p == nil {
		return q
	} else if q == nil {
		return p
	}
	h := p
	if compare(p.Data,q.Data) > 0 {
		h = q
	}
	t := h
	for p != nil && q != nil {
		comp := compare(p.Data,q.Data)
		if comp <= 0 {
			t,p = p,p.Next
		} else {
			t.Next = q
			if compare(q.Data,p.Data) < 0 {
				p,q = q,p
			}
		}
	}
	t.Next = q
	return h
}

// Assumption: l & l2 are sorted
func (l *List) SortMerge(l2 *List) {
	if l == nil || l2 == nil || l.Head == nil || l2.Head == nil {
		if l != nil && l.Head == nil {
			if l2 != nil {
				l.Head = l2.Head
			}
		}
		return
	}
	var p,q,t *Node = l.Head, l2.Head, nil
	if compare(p.Data,q.Data) > 0 {
		p,q = q,p // p points at minimum data element at all times
	}
	l.Head, t = p, p
	for p != nil && q != nil {
		comp := compare(p.Data,q.Data)
		if comp <= 0 {
			t,p = p, p.Next
		} else {
			t.Next = q
			if compare(q.Data,p.Data) < 0 {
				p,q = q,p
			}
		}
	}
	t.Next, l.Tail = q, q
}

/*func (l *List) SortMerge(l2 *List) {
	if l == nil || l2 == nil {
		return
	}
	l.Sort()
	l2.Sort()
	h, t := l.Head, l.Tail
	if h == nil || l2.Head != nil && compare(h.Data,l2.Head.Data) > 0 {
		h = l2.Head
	}
	if t == nil || l2.Tail != nil && compare(t.Data, l2.Tail.Data) <= 0 {
		t = l2.Tail
	}
	for p,q := l.Head, l2.Head; p != nil && q != nil; {
		comp := compare(p.Data,q.Data)
		if comp <= 0 {
			p.Next, p = q, p.Next
		} else {
			q.Next, q = p, q.Next
		}
	}
	l.Head, l.Tail = h, t
}*/
