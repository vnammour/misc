/* Wed May 20 03:03:50 PM IDT 2026 */
/* By: vnammour */
package main

import (
	"github.com/01-edu/z01"
)

func main() {
	ForEach(printnbr,[]int{1001,-1234,-98239,1, 0})
}

func ForEach(f func(int), a []int) {
	for _, v := range a {
		f(v)
		z01.PrintRune('\n')
	}
}

func printnbr(n int) {
	sign := 1
	if n < 0 {
		sign = -1
		z01.PrintRune('-')
	}
	if n >= 10 || n <= -10 {
		printnbr(n/10 * sign)
	}
	z01.PrintRune(rune(n%10 * sign) + '0')
}
