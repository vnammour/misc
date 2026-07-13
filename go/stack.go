/* Mon Jul 13 09:34:04 PM IDT 2026 */
/* By: vnammour */
package main

import (
	"fmt"
)

func main() {
	exp := "this( [i]s a [test] {to check} expressin)"
	valid := validate_expression(exp)
	fmt.Println(valid)
	exp = `this "is a test'to check'quotes". end`
	valid = validate_quotes(exp)
	fmt.Println(valid)
}

func validate_quotes(exp string) bool {
	stack := make(Stack[rune],0,32)
	for _,r := range exp {
		if r == '"' || r == '\'' {
			val, ok := stack.top()
			if ok {
				if val == r {
					stack.pop()
					continue
				}
			}
			stack.push(r)
		}
	}
	return len(stack) == 0
}

func validate_expression(exp string) bool {
	stack := make(Stack[rune],0,32)
	for _,r := range exp {
		if r == '(' || r == '[' || r == '{' {
			stack.push(r)
		}
		if r == ')' || r == ']' || r == '}' {
			c,ok := stack.top()
			if !ok {
				return false
			}
			switch r {
			case ')':
				if c == '(' {
					stack.pop()
				}
			case ']':
				if c == '[' {
					stack.pop()
				}
			case '}':
				if c == '{' {
					stack.pop()
				}
			}
		}
	}
	return len(stack) == 0
}

// Define a generic stack for any type T
type Stack[T any] []T

func (s *Stack[T]) push(v T) {
	*s = append(*s, v)
}

func (s *Stack[T]) pop() (T,bool) {
	var zero T
	if len(*s) == 0 {
		return zero, false
	}
	topIdx := len(*s) - 1
	data := (*s)[topIdx]
	(*s)[topIdx] = zero
	*s = (*s)[:topIdx]
	return data, true
}

func (s *Stack[T]) top() (T,bool) {
	var zero T
	if len(*s) == 0 {
		return zero, false
	}
	return (*s)[len(*s)-1], true
}

func (s *Stack[T]) isEmpty() bool {
	return len(*s) == 0
}

// Comments:
/*
When you work with a generic type T, you do not always know if T will be a pointer, a struct, or an interface. Setting the slot to var zero T ensures that whatever the type is, its reference is completely wiped from the underlying array segment, making it safe for Go's garbage collector.

Even though stack is declared as a value variable (var stack Stack), Go automatically handles this via a compiler feature called automatic addressability (or implicit pointer dereferencing).How It Works Behind the ScenesWhen a method requires a pointer receiver (*Stack), but you call it on a value variable (stack), Go checks if the variable is addressable (meaning it has a specific location in memory).Because your stack is a package-level global variable, it is fully addressable. Go automatically rewrites your code under the hood:

// What you write:
stack.pop()

// What the Go compiler actually executes:
(&stack).pop()

The One Catch: Slice Header ModificationBecause you are modifying a slice (Stack []interface{}), using a pointer receiver (*Stack) for your pop() method is actually the mandatory and correct approach.A slice in Go is a header containing a pointer to the underlying array, a length, and a capacity. If you were to pass it by value instead of a pointer:The pop method would receive a copy of the slice header.Truncating the slice inside the method would only affect the copy.The global stack variable would never change its length.By using (s *Stack) pop(), you ensure that changes to the slice length and capacity persist directly to your global variable.

The Memory Leak Problem
In Go, a slice is a window into an underlying array. When you truncate the slice using *s = (*s)[:len(*s)-1], you move the slice's end marker backward.However, the element you just "popped" still remains in the underlying array in memory. Because interface{} can hold pointers to large objects, Go's garbage collector cannot free that memory as long as the stack's underlying array keeps a reference to it.The Fix: Nil Out the ElementTo prevent the leak, you must explicitly set the deleted slot to nil before truncating the slice:
func (s *Stack) pop() interface{} {
	if len(*s) == 0 {
		return nil
	}
	
	// 1. Get the index of the last element
	topIdx := len(*s) - 1
	
	// 2. Grab the data
	data := (*s)[topIdx]
	
	// 3. Clear the reference to prevent memory leaks 💡
	(*s)[topIdx] = nil 
	
	// 4. Truncate the slice
	*s = (*s)[:topIdx]
	
	return data
}
*/
