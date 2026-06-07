/* Sat Jun  6 08:07:04 PM IDT 2026 */
/* By: vnammour */
package main

import (
	"fmt"
	"os"
	"bytes"
)

const (
	intsize = 32 << (^uint(0) >> 63)
	maxint = 1 << (intsize-1) - 1
	minint = -1 << (intsize -1)
)

func main() {
	if len(os.Args) != 3 {
		return
	}
	arr, ok := parsearray(os.Args[1])
	if !ok {
		os.Exit(1)
	}
	sum, ok := atoi(os.Args[2])
	if !ok {
		fmt.Fprintf(os.Stderr,"Invalid target sum.\n")
		os.Exit(1)
	}
	fmt.Printf("%v\n", arr)
	fmt.Println(sum)
	keys := make(map[int]*List)
	for i := 0; i < len(arr); i++ {
		keys[arr[i]] = addnode(keys[arr[i]],i)
	}

	soln := 0
	// buf := bytes.NewBuffer(make([]byte,0,len(arr))) // or below
	buf := new(bytes.Buffer)
	buf.WriteByte('[')
	for i := 0; i < len(arr); i++ {
		index := sum - arr[i]
		// note that sum - key = index. So once I am done with that entry,
		// I can set sum - index to nil
		if list, ok := keys[index]; ok {
			var sep string
			for ; list != nil && list.Head != nil && i != list.Head.Data;
				list.Head = list.Head.Next {
					if soln == 0 {
						sep = ""
					} else {
						sep = " "
					}
					soln++
					buf.WriteString(fmt.Sprintf("%s[%d %d]",sep,i,list.Head.Data))
			}
			keys[sum - index] = nil
		}
	}
	if soln == 0 {
		fmt.Printf("No pairs found.\n")
	} else {
		buf.WriteByte(']')
		fmt.Printf("%s\n", buf)
	}
}

func parsearray(s string) ([]int,bool) {
	i := index(s,"[")
	j := index(s,"]")
	if i == -1 || j == -1 {
		fmt.Fprintf(os.Stderr, "Invalid input.\n")
		return nil,false
	}
	s = s[i+1:j]
	arr := make([]int, len(s))
	j = 0
	for {
		i = index(s,",")
		if i == -1 {
			i = len(s)
		}
		num, ok := atoi(s[:i])
		if !ok {
			return arr,false
		}
		// fmt.Printf("j = %d, num = %d\n", j, num)
		arr[j] = num
		j++
		if i != len(s) {
			s = s[i+1:]
		} else {
			break
		}
	}
	return arr[:j],true
}

func hasprefix(s, sub string) bool {
	return len(s) >= len(sub) && s[:len(sub)] == sub
}

func index(s, sub string) int {
	for i := 0; i < len(s); i++ {
		if hasprefix(s[i:], sub) {
			return i
		}
	}
	return -1
}

func atoi(s string) (int,bool) {
	i := 0
	for ; i < len(s) && isspace(s[i]); i++ {}
	s = s[i:]
	if len(s) == 0 {
		return 0, false
	}
	sign := 1
	if s[0] == '-' || s[0] == '+' {
		if s[0] == '-' {
			sign = -1
		}
		s = s[1:]
	}
	// fmt.Printf("atoi(%s)\n", s)
	var num, base uint = 0, 10
	m := uint(maxint)
	if sign < 0 {
		m++
	}
	for i:=0; i < len(s); i++ {
		if !isdigit(s[i]) {
			fmt.Fprintf(os.Stderr, "Invalid number: %c\n", s[i])
			return 0, false
		}
		d := uint(s[i] - '0')
		if num > m/base {
			return 0, false
		}
		num *= base
		if num > m - d {
			return 0, false
		}
		num += d
	}
	answer := 0
	if sign < 0 {
		num--
		answer = int(num)
		answer *= sign
		answer--
	} else {
		answer = int(num)
	}
	return answer, true
}

func isspace(b byte) bool {
	return b == ' ' || b == '\n' || b == '\t' || b == '\v' || b == '\r'
}

func isdigit(b byte) bool {
	return b >= '0' && b <= '9'
}

type Node struct {
	Data int
	Next *Node
}

type List struct {
	Head *Node
}

func addnode(list *List, data int) *List {
	node := new(Node{data,nil})
	if list == nil || list.Head == nil {
		return &List{Head: &Node{data,nil}}
	}
	p := list.Head
	for ; p.Next != nil; p = p.Next {}
	p.Next = node
	return list
}
