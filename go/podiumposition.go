/* Tue Jun 16 11:54:42 AM IDT 2026 */
/* By: vnammour */
package piscine
import (
	// "fmt"
)
/*func main() {
	p4 := []string{"4th Place"}
	p3 := []string{"3rd Place"}
	p2 := []string{"2nd Place"}
	p1 := []string{"1st Place"}
	position := [][]string{p4,p3,p2,p1}
	fmt.Println(PodiumPosition(position))
}*/

func PodiumPosition(podium [][]string) [][]string {
	for i:=1; i < len(podium); i++ {
		for j:= i-1; j>=0; j-- {
			if compare(podium[j],podium[j+1]) > 0 {
				podium[j],podium[j+1] = podium[j+1],podium[j]
			}
		}
	}
	return podium
}

// 0: equal, +ve: a > b, -ve: a < b
func compare(a,b []string) int {
	minlen := 0
	if len(a) < len(b) {
		minlen = len(a)
	} else {
		minlen = len(b)
	}
	for i:=0; i < minlen; i++ {
		if a[i] > b[i] {
			return 1
		} else if a[i] < b[i] {
			return -1
		}
	}
	return len(a) - len(b)
}
