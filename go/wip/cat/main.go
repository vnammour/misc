/* Mon May 11 06:26:27 PM IDT 2026 */
/* By: vnammour */
package main

import (
	"os"
	"bufio"
)

func main() {
	if len(os.Args) == 1 {
		cat(os.Stdin.Name())
	} else {
		for _,arg := range os.Args[1:] {
			if !cat(arg) {
				os.Exit(1)
			}
		}
	}
}

func cat(filename string) bool {
	file, err := os.Open(filename)
	if err != nil {
		os.Stdout.WriteString("ERROR: " + err.Error() + "\n")
		return false
	}
	for scanner := bufio.NewScanner(file); scanner.Scan(); {
		os.Stdout.WriteString(scanner.Text() + "\n")
	}
	return true
}
