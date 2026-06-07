/* Wed May 20 03:43:03 PM IDT 2026 */
/* By: vnammour */
package main

import (
	"fmt"
)

func main() {
	fmt.Println(CountIf(isnumeric,[]string{"hello","123","world","-11","-","+", "+123","-123"}))
	fmt.Println(CountIf(isnumeric,[]string{"hello","world","-","+"}))
}

func CountIf(f func(string) bool, tab []string) int {
	count := 0
	for _,s := range tab {
		if f(s) {
			count++
		}
	}
	return count
}

func isnumeric(s string) bool {
	if len(s) == 0 {
		return false
	}
	if s[0] == '+' || s[0] == '-' {
		s = s[1:]
	}
	if len(s) == 0 {
		return false
	}
	for _,r := range s {
		if r < '0' || r > '9' {
			return false
		}
	}
	return true
}
