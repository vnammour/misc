/* Wed May 20 06:56:05 PM IDT 2026 */
/* By: vnammour */
package piscine
import (
	// "fmt"
)
/*func main() {
	words := []string{"a","A","1","b","B","2","c","C","3"}
	SortWordArr(words)
	fmt.Println(words)
}*/

func SortWordArr(a []string) {
	for i:=1; i < len(a); i++ {
		for j:= i; j > 0; j-- {
			if a[j] < a[j-1] {
				a[j-1],a[j] = a[j],a[j-1]
			}
		}
	}
}
