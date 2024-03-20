package main

import (
	"fmt"
	"gonote/note"
)

func main() {

	// note.SayHelloWorld()
	// note.EscapedCharacers()
	note.VariablesAndConstant()
	fmt.Println(note.Version) //跨包调用的常量
}
