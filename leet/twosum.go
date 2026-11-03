/* Sat Oct 31 08:52:00 AM IST 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
type Node struct {
	data int
	next *Node 
}
type Pair struct {
	a, b int
}
func (n *Node) preappend(data int) *Node {
	node := new(Node{data,nil})
	var prev, nxt *Node
	for prev,nxt = nil, n; nxt != nil; prev, nxt = nxt, nxt.next {}
	if prev == nil {
		return node
	}
	prev.next = node
	return n
}
func (n *Node) deletelist() {
	var temp *Node
	for n != nil {
		temp = n.next
		n.next, n = nil, nil
		n = temp
	}
}
func (n *Node) printlist() {
	for ; n != nil; n = n.next {
		fmt.Printf("%d->", n.data)
	}
	fmt.Printf("%v\n", n)
}
func readvalues(arr []int) map[int]*Node {
	m := make(map[int]*Node,int(float32(len(arr)) * 0.25)) // 25% capacity
	for index,value := range arr {
		// m[value] = index
		m[value] = m[value].preappend(index)
	}
	return m
}
// {3, 1, 0, 2, 4, 5, 4}, sum = 8 : indices: (0,5), (4,6)
func method1() {
	arr := []int{3, 1, 0, 2, 4, 5, 4, 3, 3}
	sum := 8
	m := readvalues(arr)
	processed := make(map[int]bool,len(m))
	pairs := make([]Pair, 0, 10)
	for i := 0; i < len(arr); i++ {
		diff := sum - arr[i]
		for node := m[diff]; node != nil; node = node.next {
			if (node.data != i && !processed[node.data + i]) {
				pairs = append(pairs, Pair{i,node.data})
				processed[node.data + i] = true
			}
		}
		m[diff].deletelist()
		m[diff] = nil
	}
	for _,pair := range pairs {
		fmt.Printf("%v\n", pair)
	}
	fmt.Printf("%v\n", pairs)
	for k,_ := range m {
		fmt.Printf("Key: %d\n", k)
		m[k].deletelist()
		m[k] = nil
		m[k].printlist()
	}
}

func main() {
	method1()
}
