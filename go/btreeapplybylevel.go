/* Thu May  7 05:24:25 PM IDT 2026 */
/* By: vnammour */
package main

import (
"fmt"
)

func main() {
	var root *TreeNode
	root = BTreeInsertData(root, "4")
	root = BTreeInsertData(root, "1")
	root = BTreeInsertData(root, "7")
	root = BTreeInsertData(root, "5")
	// BTreeApplyInorder(root, fmt.Println)
	BTreeApplyByLevel(root,fmt.Println)
	fmt.Println("depth = ",btreedepth(root))
	fmt.Println("numnodes = ",numnodes(btreedepth(root)))
}

type TreeNode struct {
	Left, Right, Parent *TreeNode
	Data                string
}

func BTreeApplyByLevel(root *TreeNode, f func(...interface{}) (int, error)) {
	if root == nil {
		return
	}
	queue := make([]*TreeNode, 0, numnodes(btreedepth(root)))
	queue = append(queue, root)
	bfs(queue, f)
}

func bfs(queue []*TreeNode, f func(...interface{}) (int, error)) {
	if len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]
		if node != nil {
			f(node.Data)
			queue = append(queue, node.Left, node.Right)
		}
		bfs(queue, f)
	}
}

func btreedepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	l := 1 + btreedepth(root.Left)
	r := 1 + btreedepth(root.Right)
	if l >= r {
		return l
	}
	return r
}

func numnodes(depth int) int {
	n := 1
	for depth > 0 {
		n *= 2
		depth--
	}
	return n - 1
}

func BTreeApplyInorder(root *TreeNode, f func(...interface{}) (int, error)) {
	if root != nil {
		BTreeApplyInorder(root.Left, f)
		f(root.Data)
		BTreeApplyInorder(root.Right, f)
	}
}

func BTreeInsertData(root *TreeNode, data string) *TreeNode {
	node := &TreeNode{nil, nil, nil, data}
	var x, y *TreeNode = root, nil
	for x != nil {
		y = x
		if data <= x.Data {
			x = x.Left
		} else {
			x = x.Right
		}
	}
	node.Parent = y
	if y != nil {
		if data < y.Data {
			y.Left = node
		} else {
			y.Right = node
		}
	} else {
		root = node
	}
	return root
}
