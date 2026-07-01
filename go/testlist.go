/* Sat Jun 27 11:00:37 AM IDT 2026 */
/* By: vnammour */
package main

import (
	L "ds"
	"fmt"
)

// create a type alias
type Circle = L.Circle

func main() {
	testsortmerge()
	fmt.Println("------")
	testsortmerge2()
	fmt.Println("------")
	testsortmergenodes();
	fmt.Println("------")
	testsize()
	fmt.Println("------")
}

func testsize() {
	l := new(L.List)
	for i := 0; i < 10; i++ {
		l.Pushback(i)
	}
	fmt.Printf("size = %d\n", l.Size())
	fmt.Printf("recursively: size = %d\n", l.SizeR())
}

func testsortmerge2() {
	l1 := new(L.List)
	l1.Pushback(7)
	l1.Pushback(6)
	l1.Pushback(5)
	l1.Pushback(4)
	l1.Pushback(3)
	l1.Sort()
	l1.Print()
	l2 := new(L.List)
	l2.Pushback(3)
	l2.Pushback(3)
	l2.Pushback(3)
	l1.SortMerge(l2)
	l1.Print()
}

func testsortmerge() {
	l1 := new(L.List)
	l1.Pushback(3)
	l1.Pushback(5)
	l1.Pushback(10)
	l2 := new(L.List)
	l2.Pushback(2)
	l2.Pushback(3)
	l2.Pushback(6)
	l2.Pushback(11)
	l2.SortMerge(l1)
	l2.Print()
}

func testmisctypes() {
	l := new(L.List)
	l.Pushfront(3.14)
	l.Pushfront(3.141)
	l.Pushfront(3.1412)
	l.Pushfront(3.14121)
	l.Print()
	l.Sort()
	l.Print()
	l.Clear()
}

func testcircles() {
	l := new(L.List)
	l.Pushback(new(Circle{4}))
	l.Pushback(new(Circle{3}))
	l.Pushback(new(Circle{2}))
	l.Pushback(new(Circle{1}))
	l.Print()
	l.Sort()
	l.Print()
	l.Reverse()
	l.Print()
}

func testsortmergenodes() {
	data1 := []int{15,72,-43,-11,25,8,-3,-37}
	data2 := []int{15,6,-14,16,1,27,41,29}
	l1 := new(L.List)
	l2 := new(L.List)
	for i := 0; i < len(data1); i++ {
		l1.Pushback(data1[i])
	}
	for i := 0; i < len(data2); i++ {
		l2.Pushback(data2[i])
	}
	l1.Sort()
	l2.Sort()
	l1.Print()
	l2.Print()
	h := L.SortMergeNodes(l1.Head, l2.Head)
	L.PrintNodes(h)
}
