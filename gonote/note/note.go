package note

import "fmt"

var v = 100 //全局变量

//2.1
func SayHelloWorld() { // 只有首字母大写的包才能被跨包调用

	fmt.Println("hello world")
}

//2.1 转义字符
func EscapedCharacers() {
	fmt.Println("变量")
	fmt.Println("\"hello world\"")
	fmt.Println("hello worl\bd")
	fmt.Println("he\fll\fo worl\fd")
}

const (
	Version int = 8 //想夸包调用 名字开头字母大写
)

//2.2变量与常量
func VariablesAndConstant() {
	v = 200
	var v1 int
	var v2 int = 2
	v1 = 1
	var v3 = 3
	v4 := 4
	var (
		v5     = 5
		v6 int = 4
		v7 int // 默认值为0
	)

	fmt.Printf("v1=%v,v2=%v,v3=%v,v4=%v,v5=%v,v6=%v,v7=%v\n", v1, v2, v3, v4, v5, v6, v7)
	const (
		c1 = 8
		c2 = iota //常量定义 支持当前所在行  当前行为1 下一行为2
		c3 = iota
		c4 //默认为上一行的值
		c5 = 12
		c6
	)
	fmt.Printf("c1=%v,c2=%v,c3=%v,c4=%v,c5=%v,c6=%v\n", c1, c2, c3, c4, c5, c6)
}
