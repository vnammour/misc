/* Tue Nov 10 03:02:57 PM IST 2026 */
/* By: Tia Nammour */
package main
import (
	"ds"
	"fmt"
)
func main() {
	stack := new(ds.Stack[[]int])
	stack.Push(make([]int,5))
	arr := stack.Top()
	for i := 0; i < 5; i++ {
		arr[i] = i
	}
	fmt.Printf("%v\n", arr)
	arr = stack.Top()
	fmt.Printf("%v\n", arr)
	arr = append(arr,[]int{5,6,7}...)
	stack.Pop()
	stack.Push(arr)
	fmt.Printf("%v\n", arr)
	arr = stack.Top()
	fmt.Printf("%v\n", arr)
	stack.Pop()
	arr2:= stack.Pop()
	arr3:= stack.Pop()
	fmt.Printf("%v\n", arr2)
	fmt.Printf("%v\n", arr3)
	fmt.Printf("%v\n", arr2 == nil)
}
