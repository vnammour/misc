/* Sun Jun 28 02:18:05 PM IDT 2026 */
/* By: vnammour */
package ds

import (
	"fmt"
	"reflect"
)

/*
Let x be a node in a binary search tree. If y is a node in the left subtree
of x, then key[y] <= key[x]. If y is a node in the right subtree of x, then
key[x] <= key[y].
*/

type TreeNode struct {
	Left, Right, Parent *TreeNode
	Data interface{}
}

func (t *TreeNode) Insert(data interface{}) {
	if t == nil {
		return
	}
	node := new(TreeNode{Data:data})
	comp := 0
	var p *TreeNode
	for t != nil {
		comp = bstcompare(t.Data,node.Data)
		p = t 
		if comp < 0 {
			t = t.Right
		} else {
			t = t.Left
		}
	}
	if comp < 0 {
		p.Right = node
	} else {
		p.Left = node
	}
	node.Parent = p
}
func Iow(t *TreeNode) {
	if t != nil {
		Iow(t.Left)
		fmt.Printf("%v\n", t.Data)
		Iow(t.Right)
	}
}
func (t *TreeNode) InOrderWalk() {
	if t != nil {
		t.Left.InOrderWalk()
		fmt.Printf("%v\n", t.Data)
		t.Right.InOrderWalk()
	}
}

func bstcompare(v1, v2 interface{}) int {
	if reflect.TypeOf(v1) != reflect.TypeOf(v2) {
		return 0
	}
	switch v1.(type) {
	case int, byte, int8, int32:
		return v1.(int) - v2.(int)
	case float32,float64:
		if v1.(float64) - v2.(float64) < 0 {
			return -1
		} else if v1.(float64) - v2.(float64) > 0 {
			return 1
		} else {
			return 0
		}
	case string:
		if v1.(string) > v2.(string) {
			return 1
		} else if v1.(string) < v2.(string) {
			return -1
		} else {
			return 0
		}
	default: return 0
	}
}
