/* Sun Jun 28 03:48:39 PM IDT 2026 */
/* By: vnammour */
package main
import (
	bst "ds"
	"fmt"
)
func main() {
	testinsert()
}

func testinsert() {
	// data := []int{-4,10,15,-10,22,14,101,-1,0}
	data := []int{4,1,2,5,3,4}
	var root *bst.TreeNode = &bst.TreeNode{Data:3}
	for i := 0; i < len(data); i++ {
		root.Insert(data[i])
	}
	fmt.Printf("root: %v\n", root.Data)
	// root.InOrderWalk()
	bst.Iow(root)
}
