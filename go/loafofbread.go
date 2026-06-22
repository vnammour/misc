/* Tue Jun 16 01:20:09 PM IDT 2026 */
/* By: vnammour */
package main
import (
	"fmt"
)
func main() {
	// fmt.Printf("len(arg) = %d\n", len("deliciousbread"))
	// fmt.Printf("%s\n", LoafOfBread("deliciousbread"))
	// fmt.Printf("%s\n",LoafOfBread("This is a loaf of bread"))
	// fmt.Printf("%s\n",LoafOfBread("loaf"))
	table := []string{
                "Loaf of bread",
				"amazing loaf of bread",
				"bread crumbles",
				"",
				"bread slice",
				"bread",
				"This is a loaf of bread",
				"",
				"                       ",
			}
			//              "This is a loaf of brea",
			//              " This is a loaf of bread",
			//              " This is a loaf of bread ",
			//              "This is a loaf of bre ",
			//              "This     is a loaf  of bread",
			//              "This     is a  loaf of bre ",
			//              "This is a loaf of bre  ",
			//              "This is a loaf of br  ",
			//              "      This     is a l o a f     of   br    ead",
			// }
	for _, arg := range table {
		fmt.Print(LoafOfBread(arg))
	}
}

func LoafOfBread(str string) string {
	if len(str) < 5 {
		return "Invalid Output\n"
	}
	buf := make([]rune, 0, len(str))
	i := 0
	for _,r := range str {
		if isspace(r) || i == -1 {
			if i == -1 {
				i = 0
			}
			continue
		}
		buf = append(buf,r)
		i++
		if i % 5 == 0 {
			buf = append(buf,' ')
			i = -1
		}
	}
	if len(buf) > 0 && isspace(buf[len(buf)-1]) {
		buf = buf[:len(buf)-1]
	}
	buf = append(buf,'\n')
	// if len(buf) < 5 {
	// 	return "Invalid Output\n"
	// }
	return string(buf)
}

func isspace(r rune) bool {
	return r == ' ' || r == '\t' || r == '\v' || r == '\n' || r == '\r'
}
