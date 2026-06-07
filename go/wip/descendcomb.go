/* Wed May 27 12:59:44 PM IDT 2026 */
/* By: vnammour */
package piscine

import (
	"github.com/01-edu/z01"
)

/*func main() {
	descendcomb()
}*/

func DescendComb() {
	for i := 99; i > 0; i-- {
		for j := i - 1; j >= 0; j-- {
			if i < 10 {
				z01.PrintRune('0')
			}
			printnbr(i)
			z01.PrintRune(' ')
			if j < 10 {
				z01.PrintRune('0')
			}
			printnbr(j)
			if i == 1 && j == 0 {
				// z01.PrintRune('\n')
			} else {
				z01.PrintRune(',')
				z01.PrintRune(' ')
			}
		}
	}
}

func printnbr(n int) {
	sign := 1
	if n < 0 {
		sign = -1
		z01.PrintRune('-')
	}
	if n >= 10 || n <= -10 {
		printnbr(n / 10 * sign)
	}
	z01.PrintRune(rune(n%10*sign + '0'))
}
