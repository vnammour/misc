/* Mon Nov  2 02:44:58 PM IST 2026 */
/* By: Tia Nammour */
package main
import (
	"fmt"
	"ds"
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

func (t *TreeNode[T]) InsertRec(data T) {
	if t == nil {
		return
	}
	result := t.compare(data,t.Data)
	if result < 0 {
		if t.Left == nil {
			t.Left = new(TreeNode[T]{Data: data})
		} else {
			t.Left.InsertRec(data)
		}
	} else {
		if t.Right == nil {
			t.Right = new(TreeNode[T]{Data: data})
		} else {
			t.Right.InsertRec(data)
		}
	}
}

func (t *TreeNode[T]) compare(a,b T) int {
	var aAny, bAny any = a, b
	switch vA := aAny.(type) {
	case int:
		vB := bAny.(int)
		if vA < vB {
			return -1
		}
		return map[bool]int{true: 1, false: 0} [ vA > vB ]
	default:
		panic(fmt.Sprintf("unsupported type for comparison: %T", vA))
	}
}

func (t *TreeNode[T]) InOrderTraversal(tree *TreeNode[T]) {
	if tree != nil {
		t.InOrderTraversal(tree.Left)
		fmt.Printf("%v\n", tree.Data)
		t.InOrderTraversal(tree.Right)
	}
}

// BFS
func (t *TreeNode[T]) LevelOrderTraversal(tree *TreeNode[T]) {
	if tree == nil {
		return
	}
	q := new(ds.Queue[*TreeNode[T]]{})
	q.Enqueue(tree)
	for !q.IsEmpty() {
		node, ok := q.Dequeue()
		if !ok {
			break
		}
		if node.Left != nil {
			q.Enqueue(node.Left)
		}
		if node.Right != nil {
			q.Enqueue(node.Right)
		}
		fmt.Printf("%v\n", node.Data)
	}
}

func (t *TreeNode[T]) Search(data T) *TreeNode[T] {
	cmp := t.compare(data,t.Data)
	for t != nil && cmp != 0 {
		if cmp < 0 { 
			t.Left.Search(data)
		} else {
			t.Right.Search(data)
		}
	}
	return t
}

func (t *TreeNode[T]) SearchRec(data T) *TreeNode[T] {
	cmp := t.compare(data,t.Data)
	if t == nil || cmp == 0 {
		return t
	}
	if cmp < 0 {
		return t.Left.SearchRec(data)
	} else {
		return t.Right.SearchRec(data)
	}
}

func (t *TreeNode[T]) Minimum() *TreeNode[T] {
	var paren *TreeNode[T] = nil
	for ; t != nil; paren,t = t, t.Left {}
	return paren
}

func (t *TreeNode[T]) Maximum() *TreeNode[T] {
	var paren *TreeNode[T] = nil
	for ; t != nil; paren,t = t, t.Right {}
	return paren
}

func (t *TreeNode[T]) Predecessor() *TreeNode[T] {
	if t == nil {
		return t
	}
	if t.Left != nil {
		return t.Left.Maximum()
	}
	p := t.Parent
	for ; p != nil && t == p.Left; t, p = p, p.Parent {}
	return p
}

func (t *TreeNode[T]) Successor() *TreeNode[T] {
	if t == nil {
		return t
	}
	if t.Right != nil {
		return t.Right.Minimum()
	}
	p := t.Parent
	for ; p != nil && t == p.Right; t, p = p, p.Parent {}
	return p
}

func main() {
	// compareints := func(a,b int) int {
	// 	return a - b
	// }
	var root *TreeNode[int]
	root = root.Insert(8)
	root = root.Insert(3)
	root = root.Insert(10)
	root = root.Insert(1)
	root = root.Insert(6)
	root = root.Insert(14)
	root = root.Insert(7)
	root = root.Insert(4)
	root = root.Insert(13)
	// root.InOrderTraversal(root)
	root.LevelOrderTraversal(root)
}

func test_insertrec() {
	var tree *TreeNode[int] = new(TreeNode[int]{Data:3})
	for i := 2; i > -4; i-- {
		// tree = tree.Insert(i)
		tree.InsertRec(i)
	}
	for i := 4; i < 10; i++ {
		tree.InsertRec(i)
	}
	tree.InOrderTraversal(tree)
	fmt.Printf("root's value = %d\n", tree.Data)
}
