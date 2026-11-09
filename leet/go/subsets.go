/* Sun Nov  7 06:32:24 PM IST 2026 */
/* By: vnammour */
package main
import (
	// "ds"
	"math"
	"fmt"
)
func main() {
	arr := []byte{'a','b'}
	set := subsets(arr)
	fmt.Printf("[")
	for i := 0; i < len(set); i++ {
		if i == len(set) - 1 {
			fmt.Printf("[%s]",set[i])
		} else {
			fmt.Printf("[%s],",set[i])
		}
	}
	fmt.Printf("]\n")
	/*s := new(ds.Stack[[]byte])
	s.Push(make([]byte,0,10))
	buf := s.Top().Data
	for _,b := range arr {
		buf = append(buf,b)
	}*/
}

func subsets(items []byte) [][]byte {
	expo := int(math.Pow(2.0,float64(len(items))))
	set := make([]byte,0,len(items))
	super := make([][]byte,0,expo)
	var f func(int)
	f = func(index int) {
		if index >= len(items) {
			fmt.Printf("f(%d): >%s<\n", index, set)
			// super = append(super,set) // <-- notice what's wrong !
			super = append(super, append([]byte(nil),set...))
			return
		}
		set = append(set,items[index])
		fmt.Printf("f(%d): >%s<\n", index, set)
		f(index + 1)
		set = set[:len(set)-1]
		f(index + 1)
	}
	f(0)
	return super
}
