/* Wed May 27 12:48:19 PM IDT 2026 */
/* By: vnammour */
package main

import (
	"fmt"
)

func main() {
	s := "Hello! How are You?"
	fmt.Println(s)
	fmt.Println(rot14(s))
}

func rot14(s string) string {
	var rot, size byte = 14, 26
	buf := make([]byte,len(s))
	for i := 0; i < len(s); i++ {
		b := s[i]
		switch {
		case isupper(b):
			buf[i] = ((b - 'A') + rot) % size + 'A'
		case islower(b):
			buf[i] = ((b - 'a') + rot) % size + 'a'
		default: buf[i] = b
		}
	}
	return string(buf)
}

func isupper(b byte) bool {
	return b >= 'A' && b <= 'Z'
}

func islower(b byte) bool {
	return b >= 'a' && b <= 'z'
}
