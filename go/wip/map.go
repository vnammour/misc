/* Wed May 20 02:52:53 PM IDT 2026 */
/* By: vnammour */
package main

import (
	"fmt"
)

func main() {
	a := []int{7,5,3,-10,2,100,150,180}
	values := Map(isprime,a)
	fmt.Println(values)
}

func Map(f func(int) bool, a []int) []bool {
	buf := make([]bool,len(a))
	for i,v := range a {
		buf[i] = f(v)
	}
	return buf
}

func isprime(n int) bool {
	if n <= 1 {
		return false
	}
	if n == 2 || n == 3 {
		return true
	}
	if n % 2 == 0 || n % 3 == 0 {
		return false
	}
	for i := 5; i < n/i; i+=6 {
		if n % i == 0 || n % (i+2) == 0 {
			return false
		}
	}
	return true
}
