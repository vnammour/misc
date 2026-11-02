/* Sun Nov  1 02:58:40 PM IST 2026 */
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

type Stack[T any] struct {
	Link *Node[T]
}

func (s *Stack[T]) Push(data T) {
	s.Link = s.Link.PushFront(data)
}

func (s *Stack[T]) Pop() (T,bool) {
	var zero T
	if s.Link == nil {
		return zero, false
	}
	var temp *Node[T]
	temp, s.Link, s.Link.Next = s.Link, s.Link.Next, nil
	value := temp.Data
	temp = nil
	return value, true
}

func (s *Stack[T]) Top() (T, bool) {
	if s.Link != nil {
		return s.Link.Data, true
	}
	var zero T
	return zero, false
}

func (s *Stack[T]) IsEmpty() bool {
	return s.Link == nil
}

func testlinkedlist() {
	var head *Node[int]
	for i := 0; i < 10; i++ {
		head = head.PushBack(i)
	}
	head.PrintList()
}

func isBalanced(s string) bool {
	m := map[rune]rune {
		'{':'}', '(':')', '[':']',
	}

	stack := new(Stack[rune]{nil})

	for _, r := range s {
		switch r {
		case '{', '(', '[': stack.Push(r)
		case '}', ')', ']':
			c, ok := stack.Top()
			if !ok {
				return false
			}
			if value,ok := m[c]; ok && value == r {
				stack.Pop()
			} else {
				return false
			}
		}
	}
	return stack.IsEmpty()
}

func main() {
	s := "((([[]])))"
	fmt.Printf("%v\n", isBalanced(s))
}
