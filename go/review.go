/* Tue Jul 28 02:37:50 PM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
type Node struct {
	Data interface{}
	Next *Node
}

type List struct {
	Head *Node
}

func (l *List) pushback(data interface{}) {
	if l == nil {
		return
	}
	node := &Node{data,nil}
	var prev, next *Node
	for prev, next = l.Head, l.Head; next != nil; prev,next = next, next.Next {}
	if prev == nil {
		l.Head = node
	} else {
		prev.Next = node
	}
}

func (l *List) pushfront(data interface{}) {
	if l == nil {
		return
	}
	node := &Node{data, nil}
	l.Head,node.Next = node,l.Head
}

func (l *List) find(data interface{}) *Node {
	for p := l.Head; p != nil; p = p.Next {
		if compare(p.Data,data) == 0 {
			return p
		}
	}
	return nil
}

func (l *List) rm(node *Node) {
	var p,n *Node
	for n = l.Head; n != node; p,n = n,n.Next {}
	if p == nil { // node is the head
		l.Head,l.Head.Next = l.Head.Next, nil
	} else if n != nil {
		p.Next, n.Next = n.Next, nil
	}
}

func compare(a,b interface{}) int {
	switch a.(type) {
	case string:
		sa, sb := a.(string), b.(string)
		if sa > sb {
			return 1
		} else if sa < sb {
			return -1
		} else {
			return 0
		}
	case int: return a.(int) - b.(int)
	default: return 0
	}
}

func (l *List) reverse() {
	if l == nil || l.Head == nil {
		return
	}
	var x,y,z *Node
	for x,y = l.Head, l.Head.Next; y != nil; {
		z, y.Next = y.Next, x
		x,y = y,z
	}
	l.Head.Next, l.Head = nil, x
}

func (l *List) printlist() {
	if l == nil {
		return
	}
	for p := l.Head; p != nil; p = p.Next {
		fmt.Printf("%v->",p.Data)
	}
	fmt.Printf("%v\n", nil)
}

func main() {
	s := []byte{'a','b','c'};
	reverse(s)
	fmt.Printf("%s\n", s);
	var l *List = &List{nil}//new(List{})
	l.pushback("a")
	l.pushback("b")
	l.pushback("c")
	l.printlist()
	n := l.find("a")
	fmt.Printf("%v\n", n)
	for l.Head != nil {
		l.rm(l.Head)
	}
	l.printlist()
	l.pushfront("a")
	l.pushfront("b")
	l.pushfront("c")
	l.printlist()
	l.reverse()
	l.printlist()
}
func reverse(buf []byte) {
	for i,j := 0, len(buf)-1; i < j; i,j = i+1, j-1 {
		buf[i],buf[j] = buf[j],buf[i]
	}
}
