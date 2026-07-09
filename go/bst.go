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
	// data := []int{5,4,7,8,2,1,5,6}
	// data := []int{4,1,7,5}
	data := []int{15, 5, 16, 20, 18, 23, 3, 12, 13, 10, 6, 7}
	var root *TreeNode
	for _,val := range data {
		root = Insert(root,val)
	}
	// InOrderTraversal(root)
	// inordertraversal(root)
	// fmt.Println("depth = ",Depth(root))
	// node := Search(root, 5)
	// fmt.Println(node)
	// node = Delete(root, node)
	// inordertraversal(root)
	for key,value := range hashtree(root) {
		fmt.Printf("%p = %d\n", value, key)
	}
}

func hashtree(root *TreeNode) map[int]*TreeNode {
	if root == nil {
		return nil
	}
	sz := pow2(Depth(root)) - 1
	hash := make(map[int]*TreeNode, sz)
	temp := root
	dummy := &TreeNode{Data:root.Data} // so that root will overwrite dummy before prcedure ends.
	stack := append(make([]*TreeNode, 0, sz), dummy)
	for len(stack) > 0 {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}
		root = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		// if root != dummy {
		hash[root.Data] = root
		// }
		root = root.Right
	}
	hash[temp.Data] = temp
	return hash
}

// The procedure runs in O(h) time on a tree of height h.
func Delete(root, z *TreeNode) *TreeNode {
	if root == nil || z == nil {
		return root
	}
	// if z has no children, we modify it's parent to replace z with null as its child.
	var x,y *TreeNode
	// Determining a node y to splice out. y is either the input node z (if z has at most
	// one child) or the successor of z (if z has two children).
	if z.Left == nil || z.Right == nil {
		y = z
	} else {
		y = TreeSuccessor(z)
	}
	// x is set to the non-nil child of y, or to null if y has no children.
	if y.Left != nil {
		x = y.Left
	} else {
		x = y.Right
	}
	// Node y is spliced out by modifying its pointers in y.Parent and x.
	// Splicing out y is somewhat complicated by the need for proper handling of the boundary
	// conditions, which occur when x = nil or when y is the root.
	if x != nil {
		x.Parent = y.Parent
	}
	if y.Parent == nil {
		root = x
	} else {
		if y == y.Parent.Left {
			y.Parent.Left = x
		} else {
			y.Parent.Right = x
		}
	}
	
	// If the successor of z was the node spliced out, y's key and satellite data are moved to z,
	// overwriting the previous key and satellite data.
	if y != z {
		z.Data = y.Data
	}
	// VJN
	// removing all reference from y to other nodes in the tree.
	y.Parent, y.Left, y.Right = nil, nil, nil
	// The node y is returned so that the calling procedure can recycle it via the free list.
	return y
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


func TreeSuccessor(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}
	if root.Right != nil {
		return TreeMin(root.Right)
	}
	var x, y = root, root.Parent
	for y != nil && x == y.Right {
		x = y
		y = y.Parent
	}
	return y
}

func TreePredecessor(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}
	if root.Left != nil {
		return TreeMax(root.Left)
	}
	var x,y *TreeNode = root, root.Parent
	for y != nil && x == y.Left {
		x = y
		y = y.Parent
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

func Transplant(root, node, rplc *TreeNode) *TreeNode {
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

func pow2(n int) int {
	num := 1
	for n > 0 {
		num *= 2
		n--
	}
	return num
}
