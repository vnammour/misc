/* Tue Jun 30 03:08:48 PM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)

type TreeNode struct {
	Left, Right, Parent *TreeNode
	Data string
}

func main() {
	data := []string{"5","4","6","5","2","6","7"}
	var root *TreeNode
	fmt.Println(root == nil)
	for i:=0; i < len(data); i++ {
		root = BTreeInsertData(root,data[i])
	}
	BTreeApplyInorder(root,fmt.Println)
}
func BTreeApplyInorder(root *TreeNode, f func(...interface{}) (int, error)) {
	if root != nil {
		BTreeApplyInorder(root.Left, f)
		fmt.Printf("%v\n", root.Data)
		BTreeApplyInorder(root.Right, f)
	}
}

func size(root *TreeNode) int {
	count := 0
	if root == nil {
		return count
	}
	return 1 + size(root.Left) + size(root.Right)
}

func inordertraversal(root *TreeNode, f func(...interface{}) (int,error)) {
	if root == nil {
		return
	}
	stack := make([]*TreeNode,0,size(root));
	stack = append(stack,&TreeNode{}) // dummy node
	for len(stack) > 1 {
		for x != nil {
			stack = append(stack,x)
			x = x.Left
		}
		x = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		fmt.Printf("%v\n", x.Data)
		y := x.Parent
		x = x.Right
	}
}

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
