/* Tue Jun 16 10:31:19 AM IDT 2026 */
/* By: vnammour */
package main

import (
	"fmt"
	"os"
)

func main() {
	args := os.Args[1:]
	comcheck(args)
}

func comcheck(args []string) {
	for _,str := range args {
		if str == "01" || str == "galaxy" || str == "galaxy 01" {
			fmt.Printf("Alert!!!\n")
			break
		}
	}
}
