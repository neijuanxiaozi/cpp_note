# Go基础语法
https://www.bilibili.com/read/readlist/rl496566

## init函数

1. 每个包都可以有自己的init函数 且可以有多个

2. 执行顺序(取决于包的依赖关系):被依赖的全局变量>>被依赖包的init函数>>...>>main包的全局变量>>main的init函数>>main函数