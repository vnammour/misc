/* Tue Sep  1 07:32:29 PM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	a := []int{1,0,0,0,0,0,12,0,0,0,3,0,0,4};
	singlepass(a)
	fmt.Printf("%v\n", a)
}
func singlepass(a []int) {
	for i,j := 0,0; i < len(a) && j < len(a); {
		for ; i < len(a) && a[i] != 0; i++ {}
		for j = i + 1; j < len(a) && a[j] == 0; j++ {}
		if j < len(a) {
			a[i],a[j] = a[j], a[i]
			i,j = i+1, j+1
		}
	}
}
