/* Tue Jun  9 04:11:28 PM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	summary := "Water Coffee Coffee Water Carrot Cake Water Carrot Cake Coffee Water"
	for i,item := range split(summary," ") {
		fmt.Printf("arr[%d] = >%s<\n", i,item)
	}
	for item,count := range shoppingcounter1(summary) {
		fmt.Printf("%s => %d\n", item,count)
	}
}

func shoppingcounter2(s string) map[string]int {
	summary := make(map[string]int,len(s))
	for i := 0; i <= len(s); {
		if i == len(s) || isspace(s[i]) {
			summary[s[:i]]++
			i++
			if i > len(s) {
				break
			}
			s = s[i:]
			i = 0
		} else {
			i++
		}
	}
	return summary
}

func shoppingcounter1(s string) map[string]int {
	items := split(s," ")
	summary := make(map[string]int,len(items))
	for _,item := range items {
		summary[item]++
	}
	return summary
}

func split(s, sep string) []string {
	buf := make([]string,0,len(s))
	for i := 0; i < len(s); {
		s = s[i:]
		if i = index(s,sep); i == -1 {
			i = len(s)
		}
		buf = append(buf,s[:i])
		i += len(sep)
	}
	return buf
}

func hasprefix(s, sub string) bool {
	return len(s) >= len(sub) && s[:len(sub)] == sub
}

func index(s, sub string) int {
	for i := 0; i < len(s); i++ {
		if hasprefix(s[i:], sub) {
			return i
		}
	}
	return -1
}

func isspace(b byte) bool {
	return b == ' ' || b == '\t' || b == '\n' || b == '\r' || b == '\v'
}
