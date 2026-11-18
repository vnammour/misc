/* Fri Nov 13 08:58:50 PM IST 2026 */
/* By: Tia Nammour */
package main
import (
	"fmt"
)
func main() {
	N := 16
	seta := make([]byte,N)
	setb := make([]byte,N)
	k := byte(2)
	for i := 0; i < len(setb); i++ {
		seta[i] = 2<<3 + byte(i)
		setb[i] = k
		k += 4
		fmt.Printf("i = %3d: %#08b\t%#08b\n", i, seta[i], setb[i])
	}
}
