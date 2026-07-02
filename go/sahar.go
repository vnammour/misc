func ListSort(l *NodeI) *NodeI {
	if l == nil || l.Next == nil {
		return l
	}
	// step1: Split the list
	mid := getMiddle(l)
	rightHead := mid.Next
	mid.Next = nil

	// Sort both halves recursively
	left := ListSort(l)
	right := ListSort(rightHead)

	// Step 3: Merge the two sorted halves
	return merge(left, right)
}

// merge combines two sorted lists into a single sorted list
func merge(l1, l2 *NodeI) *NodeI {
	// Dummy head to simplify pointer handling
	dummy := &NodeI{}
	tail := dummy

	for l1 != nil && l2 != nil {
		if l1.Data <= l2.Data {
			tail.Next = l1
			l1 = l1.Next
		} else {
			tail.Next = l2
			l2 = l2.Next
		}
		tail = tail.Next
	}

	if l1 != nil {
		tail.Next = l1
	}
	if l2 != nil {
		tail.Next = l2
	}

	return dummy.Next
}

// find the middle node of list
func getMiddle(head *NodeI) *NodeI {
	if head == nil {
		return head
	}
	slow, fast := head, head.Next
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	return slow
}
