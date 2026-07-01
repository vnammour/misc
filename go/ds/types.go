/* Sat Jun 27 02:29:35 PM IDT 2026 */
/* By: vnammour */
package ds

type Circle struct {
	Radius int
}

func (c *Circle) compare(arg *Circle) int {
	if c.Radius > arg.Radius {
		return 1
	} else if c.Radius < arg.Radius {
		return -1
	} else {
		return 0
	}
}

