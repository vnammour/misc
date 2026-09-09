/* Wed Sep  2 01:35:41 PM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
type Node struct {
	data int
	next *Node
}
func addfront(head *Node, data int) *Node {
	head = new(Node{data,head})
	return head
}
func addback(head *Node, data int) *Node {
	node := new(Node{data,nil})
	var prev,next *Node = nil, head
	for ; next != nil; prev, next = next, next.next {}
	if prev == nil {
		return node
	}
	prev.next = node
	return head
}
func printlist(head *Node) {
	for head != nil {
		fmt.Printf("%d->", head.data)
		head = head.next
	}
	fmt.Printf("%v\n", head)
}
func reverselist(head *Node) *Node {
	if head == nil {
		return head
	}
	var x,y *Node = head, head.next
	for y != nil {
		z := y.next
		y.next = x
		x,y = y, z
	}
	head.next = nil
	return x
}
func main() {
	var head *Node
	for i := 0; i < 10; i++ {
		head = addfront(head, i)
	}
	printlist(head)
	head = reverselist(head)
	printlist(head)
	head = addback(head,10)
	printlist(head)
}
