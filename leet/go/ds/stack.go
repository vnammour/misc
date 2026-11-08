/* Sun Nov  8 06:05:14 PM IST 2026 */
/* By: vnammour */
package ds

type Node[T any] struct {
	Data T
	next *Node[T] // not exported
}
type Stack[T any] struct {
	ptr *Node[T]
}

func (s *Stack[T]) Push(data T) {
	node := new(Node[T]{data,nil})
	if s.ptr != nil {
		node.next = s.ptr
	}
	s.ptr = node
}

func (s *Stack[T]) Pop() *Node[T] {
	var node *Node[T] = s.ptr
	if node != nil {
		s.ptr, s.ptr.next = s.ptr.next, nil
	}
	return node
}

func (s *Stack[T]) Top() *Node[T] {
	return s.ptr
}

func (s *Stack[T]) IsEmpty() bool {
	return s.ptr == nil
}

