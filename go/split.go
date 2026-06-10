/* Wed Jun 10 01:29:22 PM IDT 2026 */
/* By: vnammour */
package main

import (
	"fmt"
	"strings"
)

func main() {
	test()
}

func test() {
	separators := []string {
		"",
		" ",
		"Water",
		"e",
	}
	table := []string {
		"",
		" ",
		"Burger Burger Water Coffee Water Chips Carrot",
		"Burger Burger Water Coffe    e     Water Chips Carrot",
		"Burger Burger Water Coffe    e Water Chips Carrot",
		"32312&%",
		"#$sds     ",
	}
	for _,sep := range separators {
		for _,str := range table {
			mine := split(str,sep)
			lib := strings.Split(str,sep)
			// fmt.Println(len(mine) == len(lib))
			if len(mine) != len(lib) {
				fmt.Printf("len(sep) = %d, len(str) = %d\n", len(sep), len(str))
				fmt.Printf("sep = >%s<\nstring = >%s<\n", sep,str)
				fmt.Printf("mine: %#v\n",mine)
				fmt.Printf("lib : %#v\n",lib)
				return
			}
		}
	}
}

func hasprefix(s, sub string) bool {
	return len(s) >= len(sub) && s[:len(sub)] == sub
}

func hassuffix(s, sub string) bool {
	return len(s) >= len(sub) && s[len(s)-len(sub):] == sub
}

func index(s, sub string) int {
	for i:=0; i < len(s); i++ {
		if hasprefix(s[i:],sub) {
			return i
		}
	}
	return -1
}

func trim(s, sep string) string {
	i := 0
	for hasprefix(s,sep) {
		i += len(sep)
		s = s[i:]
	}
	i = len(s)
	for hassuffix(s,sep) {
		i -= len(sep)
		s = s[:i]
	}
	return s
}

func split(s, sep string) []string {
	buf := make([]string,0,len(s))
	if len(sep) == 0 {
		for i := 0; i < len(s); i++ {
			buf = append(buf,s[i:i+1])
		}
		return buf
	}
	for i := 0; i <= len(s); {
		s = s[i:]
		if i = index(s,sep); i == -1 {
			i = len(s)
		}
		buf = append(buf,s[:i])
		i += len(sep)
	}
	return buf
}
