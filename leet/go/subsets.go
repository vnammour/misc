/* Sun Nov  7 06:32:24 PM IST 2026 */
/* By: vnammour */
package main
import (
	// "ds"
	"fmt"
)
func main() {
	arr := []byte{'a','b'}
	fmt.Printf("%v\n", subsets(arr))
	/*s := new(ds.Stack[[]byte])
	s.Push(make([]byte,0,10))
	buf := s.Top().Data
	for _,b := range arr {
		buf = append(buf,b)
	}*/
}

func subsets(items []byte) [][]byte {
	set := make([]byte,0,10)
	super := make([][]byte,0,10)
	var f func(int)
	f = func(index int) {
		fmt.Printf("f(%d)\n", index)
		if index >= len(items) {
			super = append(super,set)
			return
		}
		set = append(set,items[index])
		f(index + 1)
		set = set[:len(set)-1]
		f(index + 1)
	}
	f(0)
	// fmt.Printf("super: %v\n", super)
	return super
}
