/* Tue Jun 16 10:25:38 AM IDT 2026 */
/* By: vnammour */
package piscine

import (
	// "fmt"
)

/*func main() {
	slice := []string{"Pineapple", "Honey", "Mushroom", "Tea", "Pepper", "Milk"}
	fmt.Printf("%#v\n", slice)
	fmt.Printf("%#v\n", ShoppingListSort(slice))
}*/

func ShoppingListSort(slice []string) []string {
	for i:=1; i < len(slice); i++ {
		for j:=i-1; j >=0; j-- {
			if len(slice[j]) > len(slice[j+1]) {
				slice[j],slice[j+1] = slice[j+1],slice[j]
			}
		}
	}
	return slice
}
