/* Fri Jun  5 05:49:57 PM IDT 2026 */
/* By: vnammour */
package main

import (
	"fmt"
)

func main() {
	fmt.Print(jumpover("1010101010"))
	fmt.Print(jumpover(""))
	fmt.Print(jumpover("t w e l v e"))
	fmt.Print(jumpover("12"))
}

func jumpover(s string) string {
	j := 0
	buf := make([]byte,len(s)/3 + 1)
	for i := 2; i < len(s); i,j = i + 3, j+1 {
		buf[j] = s[i]
	}
	buf[j] = '\n'
	j++
	return string(buf[:j])
}
