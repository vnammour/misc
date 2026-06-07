/* Fri Jun  5 05:31:40 PM IDT 2026 */
/* By: vnammour */
package main

import (
	"fmt"
)

func main() {
	arr := make([]string,5)
	arr[0] = "a"
	arr[2] = "b"
	arr[4] = "c"
	fmt.Printf("%#v\n", arr)
	compact_ptr(&arr)
	fmt.Printf("%#v\n", arr)
}

func compact(ptr []string) []string {
	i := 0
	for _,str := range ptr {
		if len(str) != 0 {
			ptr[i] = str
			i++
		}
	}
	return ptr[:i]
}

func compact_ptr(ptr *[]string) {
	i := 0
	for _,str := range *ptr {
		if len(str) != 0 {
			(*ptr)[i] = str
			i++
		}
	}
	*ptr = (*ptr)[:i]
}
