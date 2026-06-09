/* Tue Jun  9 10:43:50 AM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	summary := "Burger Water Carrot Coffee Water Water Chips Carrot Carrot Burger Carrot Water"
	for index, element := range ShoppingSummaryCounter(summary) {
		fmt.Println(index, "=>", element)
	}
	buf := split(summary," ")
	for _,str := range buf {
		fmt.Printf("%s\n", str)
	}
}

func index(s,sep string) int {
	for i:=0; i < len(s); i++ {
		if hasprefix(s[i:], sep) {
			return i
		}
	}
	return -1
}
func hasprefix(s,sep string) bool {
	return len(s) >= len(sep) && s[:len(sep)] == sep
}
func ShoppingSummaryCounter(s string) map[string]int {
	if len(s) == 0 {
		return nil
	}
	summary := make(map[string]int,len(s))
	for i := 0; i < len(s); {
		if i = index(s," "); i == -1 {
			i = len(s)
		}
		summary[s[:i]]++
		if i != len(s) {
			i++
		}
		s = s[i:]
		i = 0
	}
	return summary
}

func split(s, sep string) []string {
	i := 0
	buf := make([]string,0,len(s))
	for i < len(s) {
		s = s[i:]
		if i = index(s,sep); i == -1 {
			i = len(s)
		}
		buf = append(buf,s[:i])
		i++
	}
	return buf
}
