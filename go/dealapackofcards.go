/* Tue Jun  9 04:57:17 PM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	cards := []int{0,1,2,3,4,5,6,7,8,9,10,11}
	dealapackofcards(cards)
}

func dealapackofcards(cards []int) {
	const divisor = 3
	player := 0
	for i := 0; i < len(cards); i++ {
		if i % divisor == 0 {
			player++
			fmt.Printf("Player %d: %d, ", player, i+1)
		} else {
			if (i + 1) % divisor == 0 {
				fmt.Printf("%d\n", i+1)
			} else {
				fmt.Printf("%d, ", i + 1)
			}
		}
	}
}
