/* Sun Nov  8 06:05:14 PM IST 2026 */
/* By: vnammour */
package ds
// not exported
type Node[T any] struct {
	data T
	next *Node[T]
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

func (s *Stack[T]) Pop() T {
	var data T
	var node *Node[T] = s.ptr
	if node != nil {
		s.ptr, s.ptr.next = s.ptr.next, nil
		data = node.data
		node = nil
	}
	return data
}

func (s *Stack[T]) Top() T {
	var zero T
	if s.ptr != nil {
		zero = s.ptr.data
	}
	return zero
}

func (s *Stack[T]) IsEmpty() bool {
	return s.ptr == nil
}

