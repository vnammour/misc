/* Mon Jul  6 10:07:35 AM IDT 2026 */
/* By: vnammour */
package main

import (
	"fmt"
)

type TreeNode struct {
	Left, Right, Parent *TreeNode
	Data int
}

func main() {
	// data := []int{5,4,7,8,2,1, 5, 6, 9, 10}
	data := []int{4,1,7,5}
	var root *TreeNode
	for _,val := range data {
		root = Insert(root,val)
	}
	// InOrderTraversal(root)
	inordertraversal(root)
	fmt.Println("depth = ",Depth(root))

	node := search(root,1)
	rplc := &TreeNode{Data: 3}
	fmt.Println(node,rplc)
	root = transplant(root, node, rplc)
	inordertraversal(root)
}

func search(root *TreeNode, data int) *TreeNode {
	for root != nil && root.Data != data {
		if data < root.Data {
			root = root.Left
		} else {
			root = root.Right
		}
	}
	return root
}

func TreeSuccessor(root *TreeNode) *TreeNode {
	if root == nil || root.Right == nil {
		return root
	}
	return TreeMin(root.Right)
}

func TreePredecessor(root *TreeNode) *TreeNode {
	if root == nil || root.Left == nil {
		return root
	}
	return TreeMax(root.Left)
}

func TreeMin(root *TreeNode) *TreeNode {
	var x,y *TreeNode = root, nil
	for x != nil {
		y = x
		x = x.Left
	}
	return y
}

func TreeMax(root *TreeNode) *TreeNode {
	var x, y *TreeNode = root, nil
	for x != nil {
		y = x
		x = x.Right
	}
	return y
}

func Search(root *TreeNode, data int) *TreeNode {
	for root != nil && root.Data != data {
		if data < root.Data {
			root = root.Left
		} else {
			root = root.Right
		}
	}
	return root
}

func Depth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	l := 1 + Depth(root.Left)
	r := 1 + Depth(root.Right)
	if l > r {
		return l
	} else {
		return r
	}
}

func Insert(root *TreeNode, data int) *TreeNode {
	node := &TreeNode{Data:data}
	var x,y *TreeNode = root, nil
	for x != nil {
		y = x
		if data < x.Data {
			x = x.Left
		} else {
			x = x.Right
		}
	}
	if y != nil {
		if data < y.Data {
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

func InOrderTraversal(root *TreeNode) {
	if root != nil {
		InOrderTraversal(root.Left)
		fmt.Printf("%v\n", root.Data)
		InOrderTraversal(root.Right)
	}
}

func inordertraversal(root *TreeNode) {
	if root == nil {
		return
	}
	dummy := &TreeNode{}
	stack := append(make([]*TreeNode,0,10),dummy)
	x := root
	for len(stack) > 0 {
		for x != nil {
			stack = append(stack,x)
			x = x.Left
		}
		x = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		if x != dummy {
			fmt.Printf("%v\n",x.Data)
		}
		x = x.Right
	}
}

func transplant(root, node, rplc *TreeNode) *TreeNode {
	if node == nil {
		fmt.Println("0")
		return root
	}
	var x *TreeNode = root
	for x != nil && x != node {
		if node.Data < x.Data {
			x = x.Left
		} else {
			x = x.Right
		}
	}
	if x == nil {
		fmt.Println("1")
		return root
	}
	y := x.Parent

	if x == y.Left && rplc.Data >= y.Data {
		fmt.Println("2")
		return root
	} else if x == y.Right && rplc.Data < y.Data {
		fmt.Println("3")
		return root
	}
	rplc.Parent, x.Parent = x.Parent, nil
	rplc.Left, x.Left = x.Left, nil
	rplc.Right, x.Right = x.Right, nil
	if rplc.Data < y.Data {
		y.Left = rplc
	} else {
		y.Right = rplc
	}
	return root
}
