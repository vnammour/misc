/* Tue Jun 16 10:44:24 AM IDT 2026 */
/* By: vnammour */
package piscine
import (
	// "fmt"
)
/*func main() {
	fmt.Println(reversemenuindex([]string{"desserts", "mains", "drinks", "starters"}))
}*/

func ReverseMenuIndex(items []string) []string {
	slice := make([]string,len(items))
	for i,j := 0, len(slice)-1; i <= j; i,j = i+1, j-1 {
		slice[i],slice[j] = items[j],items[i]
	}
	return slice
}
