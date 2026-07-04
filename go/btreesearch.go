/* Fri Jul  3 01:06:39 PM IDT 2026 */
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
	for i:=0; i < len(data); i++ {
		root = BTreeInsertData(root,data[i])
	}
	BTreeApplyInorder(root,fmt.Println)
	// inordertraversal(root,fmt.Println)
	fmt.Println("#of levels = ",BTreeLevelCount(root))
	fmt.Println("isbinary = ", BTreeIsBinary(root))
	fmt.Println(BTreeSearch(root,"5"))
	fmt.Println(BTreeSearch_rec(root,"5"))
}

func BTreeSearch(root *TreeNode, data string) *TreeNode {
	for root != nil && root.Data != data {
		if root.Data < data {
			root = root.Left
		} else {
			root = root.Right
		}
	}
	return root
}

func BTreeSearch_rec(root *TreeNode, data string) *TreeNode {
	if root != nil && root.Data != data {
		if root.Data < data {
			BTreeSearch_rec(root.Left, data)
		} else if root.Data > data {
			BTreeSearch_rec(root.Right, data)
		}
	}
	return root
}

func BTreeIsBinary(root *TreeNode) bool {
	if root == nil {
		return true
	}
	left := root.Left == nil || root.Left.Data < root.Data
	right := root.Right == nil || root.Right.Data > root.Data
	if left && right {
		return BTreeIsBinary(root.Left) && BTreeIsBinary(root.Right)
	} else {
		return false
	}
}

func BTreeApplyInorder(root *TreeNode, f func(...interface{}) (int, error)) {
	if root != nil {
		BTreeApplyInorder(root.Left, f)
		fmt.Printf("%v\n", root.Data)
		BTreeApplyInorder(root.Right, f)
	}
}

// check if it can be done iteratively
func BTreeLevelCount(root *TreeNode) int {
	if root == nil {
		return 0
	}
	count := 1
	l := BTreeLevelCount(root.Left)
	r := BTreeLevelCount(root.Right)
	if (l >= r) {
		return count + l
	} else {
		return count + r
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
	dummy := &TreeNode{}
	stack = append(stack,dummy)
	x := root
	for len(stack) > 0 {
		for x != nil {
			stack = append(stack,x)
			x = x.Left
		}
		x = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		// fmt.Printf("%v\n", x.Data)
		// f(x.Data)
		if x != dummy {
			f(x.Data)
		}
		x = x.Right
	}
}

func BTreeInsertData(root *TreeNode, data string) *TreeNode {
	node := &TreeNode{Data:data}
	var x,y *TreeNode = root, nil
	for x != nil {
		y = x
		// if node.Data <= x.Data {
		if node.Data > x.Data {
			x = x.Left
		} else {
			x = x.Right
		}
	}
	if y != nil {
		// if node.Data <= y.Data {
		if node.Data > y.Data {
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
