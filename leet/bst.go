/* Mon Nov  2 02:44:58 PM IST 2026 */
/* By: Tia Nammour */
package main
import (
)

type TreeNode[T any] struct {
	Data T
	Parent, Left, Right *TreeNode[T]
}

func (t *TreeNode[T]) Insert(data T) *TreeNode[T] {
	node := new(TreeNode[T]{Data: data})
	if t == nil {
		return node
	}
	var paren, tree *TreeNode[T] = nil, t
	for tree != nil {
		paren = tree
		if node.Data < tree.Data {
			tree = tree.Left
		} else {
			tree = tree.Right
		}
	}
	if node.Data < paren.Data {
		paren.Left = node
	} else {
		paren.Right = node
	}
	return t
}

func InOrderTraversal(tree *TreeNode[T]) {
	if tree != nil {
		InOrderTraversal(tree.Left)
		fmt.Printf("%v\n", tree.Data)
		InOrderTraversal(tree.Right)
	}
}

func main() {
	var tree *TreeNode[int]
	for i := 0; i < 10; i++ {
		tree = tree.Insert(i)
	}
	InOrderTraversal(tree)
}
