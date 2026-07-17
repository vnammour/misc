/* Fri Jul 17 03:36:16 AM IDT 2026 */
/* By: Jamil Nammour */
package main
import (
	"fmt"
	"bufio"
	"os"
	"io"
)
func main() {
	reader := bufio.NewReader(os.Stdin)
	i := 0
	for {
		i++
		b,err := reader.ReadByte()
		if err == io.EOF || err != nil {
			break
		}
		if b == '\n' && i == 1 {
			reader.UnreadByte()
			i = 0
		}
		fmt.Printf("%c", b);
	}
}
