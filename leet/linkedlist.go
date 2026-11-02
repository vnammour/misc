/* Mon Nov  2 06:32:44 AM IST 2026 */
/* By: Tia Nammour */
package main

import (
	"fmt"
)

type Node[T any] struct {
	Data T
	Next *Node[T]
}

func (n *Node[T]) PushBack(data T) *Node[T] {
	node := new(Node[T]{data,nil})
	var prev,next *Node[T] = nil, n
	for ; next != nil; prev,next = next, next.Next {}
	if prev == nil {
		return node
	}
	prev.Next = node
	return n
}

func (n *Node[T]) PushFront(data T) *Node[T] {
	node := new(Node[T]{data,nil})
	if n == nil {
		return node
	}
	node.Next = n
	return node
}

func (n *Node[T]) PrintList() {
	for ; n != nil; n = n.Next {
		fmt.Printf("%v->", n.Data)
	}
	fmt.Printf("%v\n", n)
}

func (n *Node[T]) FindMidNode() *Node[T] {
	var slow, fast *Node[T] = n, n
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}
	return fast
}

func main() {
	var node *Node[int]
	node = node.PushBack(2)
	node = node.PushBack(1)
	node = node.PushBack(0)
	node.PrintList()
	node = node.FindMidNode()
	fmt.Printf("%v\n", node)
}
