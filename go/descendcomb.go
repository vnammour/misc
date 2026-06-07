/* Fri Jun  5 11:55:17 AM IDT 2026 */
/* By: vnammour */
package main
import (
	"github.com/01-edu/z01"
	"math"
	"fmt"
)
func main() {
	printnbr(123)
	fmt.Println()
	printnbr(math.MinInt)
	fmt.Println()
	fmt.Println(itoa(math.MinInt))
	descendcomb()
}

func descendcomb() {
	for i:=99; i>=1; i-- {
		for j := i-1; j >=0; j-- {
			if i < 10 {
				z01.PrintRune('0')
			}
			printnbr(i)
			z01.PrintRune(' ')
			if j < 10 {
				z01.PrintRune('0')
			}
			printnbr(j)
			if !(i == 1 && j == 0) {
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
		printnbr(n/10 * sign)
	}
	z01.PrintRune(rune(n%10 * sign + '0'))
}

func itoa(n int) string {
	if n == 0 {
		return "0"
	}
	sign := 1
	base := 10
	if n < 0 {
		sign = -1
	}
	buf := make([]byte,21)
	i := len(buf)
	for n != 0 {
		i--
		buf[i] = byte(n%base * sign + '0')
		n /= base
	}
	if sign < 0 {
		i--
		buf[i] = '-'
	}
	return string(buf[i:])
}
