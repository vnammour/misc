/* Tue Nov 17 10:45:19 PM IST 2026 */
/* By: Tia Nammour */
// wip
package main
import (
	"fmt"
	"bytes"
	"strings"
	"math"
)
func main() {
	buf := new(bytes.Buffer)
	rows := 11
	var arr []int = make([]int,0,rows)
	arr = arr[:2]
	arr[0],arr[1] = 1,1
	prettyprint(arr,rows-1,buf)
	// rowprint(arr, 1)
	for i := len(arr); i < rows; i++ {
		arr = generate(arr,i)
		// rowprint(arr, rows - i)
		prettyprint(arr,rows-i-1,buf)
	}
	fmt.Printf("%s", buf.String())
}

// row 0 gives 0 len array
// row 1 gives |1|1|, so len = 2
// row 2 gives |1|2|1|, so len = 3
func generate(arr []int, row int) []int {
	if len(arr) == 1 {
		return arr // meaningless case
	}
	if len(arr) == 0 || cap(arr) < len(arr) + 1 {
		return arr
	}
	if row == 0 {
		return arr[:0]
	}
	arr = arr[:len(arr)+1]
	mid := len(arr)/2
	p,q := arr[0],arr[1]
	i := 1
	for i = 1; i <= mid; i++ {
		arr[i] = p + q
		p,q = q, arr[i+1]
	}
	// fmt.Printf("##### i = %d, row-i = %d\n", i, row - i)
	for ; i < len(arr); i++ {
		arr[i] = arr[row-i]	// symmetry
	}
	return arr
}

func prettyprint(arr []int, offset int, buf *bytes.Buffer) {
	width := int(math.Log10(float64(arr[len(arr)/2])+1) + 1)
	fmt.Fprintf(buf,"%s", strings.Repeat(" ", offset))
	for i := 0; i < len(arr); i++ {
		// fmt.Fprintf(buf,"%*s%*d ", offset," ",width,arr[i])
		fmt.Fprintf(buf,"%*d ", width,arr[i])
	}
	fmt.Fprintf(buf,"\n")
}

func rowprint(arr []int, offset int) {
	fmt.Printf("%*s", offset," ")
	for i := 0; i < len(arr); i++ {
		if i < len(arr)-1 {
			fmt.Printf("%3d% *s", arr[i], offset, " ")
		} else {
			fmt.Printf("%3d\n", arr[i])
		}
	}
}
