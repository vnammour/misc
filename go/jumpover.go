/* Tue Jun  9 05:24:15 PM IDT 2026 */
/* By: vnammour */
package main

import (
	"fmt"
)

func main() {
	fmt.Print(JumpOver("1010101010"))
	fmt.Print(JumpOver(""))
	fmt.Print(JumpOver("t w e l v e"))
	fmt.Print(JumpOver("12"))
}

func JumpOver(s string) string {
	buf := make([]rune,0,len(s))
	for i,r := range s {
		if (i+1)%3 == 0 {
			buf = append(buf,r)
		}
	}
	buf = append(buf,'\n')
	return string(buf)
}
