/* Fri Jun  5 11:41:51 AM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	fmt.Printf("# of alphabets = %d\n", 'z' - 'a' + 1)
	fmt.Printf("%s\n", rot14("Hello! How are You?"))
}

func rot14(s string) string {
	buf := make([]byte,len(s))
	for i:=0; i < len(s); i++ {
		switch  {
		case isupper(s[i]):
			buf[i] = (s[i] - 'A' + 14) % 26 + 'A'
		case islower(s[i]):
			buf[i] = (s[i] - 'a' + 14) % 26 + 'a'
		default:
			buf[i] = s[i]
		}
	}
	return string(buf)
}

func isupper(b byte) bool {
	return b >= 'A' && b <= 'Z'
}
func islower(b byte) bool {
	return b >= 'a' && b <= 'z'
}
