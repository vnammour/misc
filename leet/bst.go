/* Mon Nov  2 02:44:58 PM IST 2026 */
/* By: Tia Nammour */
package main
import (
	"fmt"
)

type TreeNode[T any] struct {
	Data T
	Parent, Left, Right *TreeNode[T]
	// compare func(a,b T) int
}

func (t *TreeNode[T]) Insert(data T) *TreeNode[T] {
	node := new(TreeNode[T]{Data: data})
	if t == nil {
		return node
	}
	var paren, tree *TreeNode[T] = nil, t
	for tree != nil {
		paren = tree
		if t.compare(node.Data, tree.Data) < 0 {
			tree = tree.Left
		} else {
			tree = tree.Right
		}
	}
	if t.compare(node.Data, paren.Data) < 0 {
		paren.Left = node
	} else {
		paren.Right = node
	}
	return t
}

func (t *TreeNode[T]) compare(a,b T) int {
	var aAny, bAny any = a, b
	switch aAny.(type) {
	case int:
		return aAny.(int) - bAny.(int)
	default: return 0
	}
}

func (t *TreeNode[T]) InOrderTraversal(tree *TreeNode[T]) {
	if tree != nil {
		tree.InOrderTraversal(tree.Left)
		fmt.Printf("%v\n", tree.Data)
		tree.InOrderTraversal(tree.Right)
	}
}

func main() {
	// compareints := func(a,b int) int {
	// 	return a - b
	// }
	var tree *TreeNode[int]
	for i := 0; i < 10; i++ {
		tree = tree.Insert(i)
	}
	tree.InOrderTraversal(tree)
}
