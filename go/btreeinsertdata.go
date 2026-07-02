/* Tue Jun 30 01:41:39 PM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	data := []string{"4","1","7","5"}
	var root *TreeNode
	fmt.Println(root == nil)
	for i:=0; i < len(data); i++ {
		root = BTreeInsertData(root,data[i])
	}
	inordertraversal(root)
}

type TreeNode struct {
	Left, Right, Parent *TreeNode
	Data string
}

func inordertraversal(root *TreeNode) {
	if root != nil {
		inordertraversal(root.Left)
		fmt.Printf("%v\n", root.Data)
		inordertraversal(root.Right)
	}
}

/*
Let x be a node in a binary search tree. If y is a node in the left subtree
of x, then key[y] <= key[x]. If y is a node in the right subtree of x, then
key[x] <= key[y].
*/
func BTreeInsertData(root *TreeNode, data string) *TreeNode {
	node := &TreeNode{Data:data}
	var x,y *TreeNode = root, nil
	for x != nil {
		y = x
		if node.Data <= x.Data {
			x = x.Left
		} else {
			x = x.Right
		}
	}
	if y != nil {
		if node.Data <= y.Data {
			y.Left = node
		} else {
			y.Right = node
		}
		node.Parent = y
	} else {
		root = node
	}
	return root
}
