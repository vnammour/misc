/* Sat Oct 31 06:31:19 PM IST 2026 */
/* By: Tia Nammour */
package main
import (
	"fmt"
)

type Stack[T any] struct {
	arr []T
	index int
}

func (s *Stack[T]) enlarge(by int) {
	// s.arr = append(s.arr, make([]T,by)...)
	size := len(s.arr) + by
	if size < 0 {
		size = 0
	}
	arr := make([]T, 0, size)
	arr = arr[:cap(arr)]
	s.index = min(s.index,size)
	copy(arr, s.arr[:s.index])
	s.arr = arr
}

func (s *Stack[T]) push(data T) bool {
	if s.index >= len(s.arr) {
		return false
	}
	s.arr[s.index] = data
	s.index++
	return true
}

func (s *Stack[T]) pop() (T,bool) {
	var zero T
	if s.index > 0 {
		s.index--
		temp := s.arr[s.index]
		s.arr[s.index] = zero
		return temp, true
	}
	return zero,false
}

func (s *Stack[T]) top() (T, bool) {
	var zero T
	if s.index > 0 {
		return s.arr[s.index-1], true
	}
	return zero, false
}

func (s *Stack[T]) isempty() bool {
	return s.index == 0
}

func (s *Stack[T]) printf() {
	index := s.index
	for index > 0 {
		index--
		if index > 0 {
			fmt.Printf("%v, ", s.arr[index])
		} else {
			fmt.Printf("%v\n", s.arr[index]) 
		}
	}
}

func teststack() {
	stack := new(Stack[int]{nil,0})
	stack.arr = make([]int,10)
	for i := 0; i < 50; i++ {
		stack.push(i)
	}
	stack.enlarge(-3)
	stack.printf()
	fmt.Printf("%v\n", stack)
	for !stack.isempty() {
		data, ok := stack.pop()
		fmt.Printf("%d, %t\n", data, ok)
	}
	stack.printf()
	fmt.Printf("%v\n", stack)
	stack.enlarge(-70)
	stack.printf()
	fmt.Printf("%v\n", stack)
}

func isbalanced(s string) bool {
	keys := map[rune]rune {
		'{':'}', '(':')', '[': ']',
	}
	stack := new(Stack[rune]{make([]rune,len(s)),0})
	for _, r := range s {
		switch r {
		case '{', '(', '[':
			ok := stack.push(r)
			if !ok {
				return false
			}
		case '}', ')', ']':
			c,ok := stack.top()
			if !ok {
				return false
			}
			if value,ok := keys[c]; ok && value == r {
				stack.pop()
			} else {
				return false
			}
		}
	}
	return stack.isempty()
}

func main() {
	// teststack()
	fmt.Printf("%v\n", isbalanced("([[]]{})"))
}
