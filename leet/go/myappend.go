/* Sun Nov  8 01:26:19 AM IST 2026 */
/* By: Tia Nammour */
package main
import (
	"fmt"
)
func main() {
	arr := []int{1,2,3}
	arr = myappend(arr,[]int{4,5,6,7,8}...)
	arr = myappend(arr,2)
	fmt.Println(arr)
}

func myappend[T any](arr []T, values ...T) []T {
	z := arr
	zlen := len(arr) + len(values)
	if zlen < cap(arr) {
		z = z[:zlen]
	} else {
		zcap := zlen
		if zcap < 2 * cap(arr) {
			zcap = 2 * cap(arr)
		}
		z = make([]T,zlen,zcap)
		copy(z,arr)
	}
	copy(z[len(arr):],values)
	return z
}
