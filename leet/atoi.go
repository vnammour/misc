/* Thu Sep  3 01:18:15 PM IDT 2026 */
/* By: vnammour */
/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
The algorithm for myAtoi(string s) is as follows:
Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.
Example 1:
Example 1:
Input: s = "42"
Input: s = "42"
Output: 42
Output: 42
Explanation:
Explanation:
The underlined characters are what is read in and the caret is the current reader position.
The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
         ^
Step 3: "42" ("42" is read in)
Step 3: "42" ("42" is read in)
           ^
           ^
Example 2:
Example 2:
Input: s = " -042"
Input: s = " -042"
Output: -42
Output: -42
Explanation:
Explanation:
Step 1: "   -042" (leading whitespace is read and ignored)
Step 1: "   -042" (leading whitespace is read and ignored)
            ^
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^
               ^
Example 3:
Example 3:
Input: s = "1337c0d3"
Input: s = "1337c0d3"
Output: 1337
Output: 1337
Explanation:
Explanation:
Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^
             ^
Example 4:
Example 4:
Input: s = "0-1"
Input: s = "0-1"
Output: 0
Output: 0
Explanation:
Explanation:
Step 1: "0-1" (no characters read because there is no leading whitespace)
Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^
          ^
Example 5:
Example 5:
Input: s = "words and 987"
Input: s = "words and 987"
Output: 0
Output: 0
Explanation:
Explanation:
Reading stops at the first non-digit character 'w'.
Reading stops at the first non-digit character 'w'.
 
 
Constraints:
Constraints:
0 <= s.length <= 200
0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/
package main
import (
	"fmt"
	"strconv"
)
var intsize int = 32;//<<(^uint(0) >> 63)
var maxint int = 1 << (intsize - 1) - 1
var minint int = -1 << (intsize - 1)

func main() {
	max_str := strconv.Itoa(maxint)
	min_str := strconv.Itoa(minint)
	fmt.Printf("%s %s\n", max_str, min_str)
	max_str = "    " + max_str
	fmt.Printf("%d\n", myAtoi(max_str))
}
func isspace(r rune) bool {
	return r == ' ' || r == '\t' || r == '\v' || r == '\n' || r == '\r' || r == '\f'
}
func isdigit(r rune) bool {
	return r >= '0' && r <= '9'
}
func myAtoi(s string) int {
	i := 0
	var r rune
	for i,r = range s {
		if !isspace(r) {
			break;
		}
	}
	s = s[i:]
	sign := 1
	if s[0] == '-' || s[0] == '+' {
		if s[0] == '-' {
			sign = -1
		}
		s = s[1:]
	}
	var num uint = 0
	var base uint = 10
	var m uint = uint(maxint)
	if sign < 0 {
		m++
	}
	ok := true
	for _,r := range s {
		if !isdigit(r) {
			break
		}
		if num > m/base {
			ok = false
			break;
		}
		num *= base
		t := uint(r - '0')
		if num > m - t {
			ok = false
			break;
		}
		num += t
	}
	result := 0
	if !ok {
		if sign < 0 {
			result = minint
		} else {
			result = maxint
		}
	} else {
		if (sign < 0 && num > 0) {
			result = int(num-1) * sign
			--result
		} else {
			result = int(num) * sign
		}
	}
	return result
}
