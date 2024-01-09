<font Size=3 color="#6c69f">我是浅紫色3号字体,默认字体就是3号</font>

1. classes的构造函数都被声明为 explicit, 这可阻止它们被用来执行隐式类型转换 (implicit type conversions) ，但它们仍可被用来进行显式类型转 (explicit type conversions) 。声明为 explicit 的构造函数通常比其 non-explicit 兄弟更受欢迎，因为它们禁止编译器执行非预期（往往也不被期望）的类型转换。除非我有一个好理由允许构造函数被用于隐式类型转换，否则我会把它声明为explicit。  


2. c++11之后:`string` 转`int`,`int x = stoi(str);`


3. 智能指针：`tr1::shared_ptr` 和 `auto_ptr`转型`(cast):` `static_cast<Investment*>(0)`,`0`转成`Incestment*`指针类型



4. 自定义`sort`比较函数：
```cpp
static bool cmp(vector<int> a, vector<int> b) {
    if (a[0] == b[0])
        return a[1] < b[1];
    else
        return a[0] > b[0];
}
```
5. `vector`集合取最后一个元素用`back()`函数，例如：`result.back()`

6. pass by what？情况 -> 传值、传指针、传引用
   - 总体：对于cpu寄存器来说，三种情况是一样的传值：实际上是把值传递给了寄存器传地址、传指针：实际上是把地址暴露给了寄存器为什么使用内置类型时，建议直接传值呢？因为使用内置类型时，数据是直接放在栈上或者寄存器里，直接调用就可以了；而使用指针或者引用，得做一次取地址操作才能得到值。但是使用例如类这种复杂的传递，开销会更大，会使用引用传递。为什么使用引用传递，而不是指针传递？在某些编译器上传递指针的开销比引用大，因为编译器需要保证子类空指针转换成父类指针时还是空指针，从而不得不先判断指针是否为空，如果为空则传0否则加一个偏移量后传递。而引用，在语义上不应该存在“空引用”，所以部分编译器在传递引用时可以不执行这个判断而直接传递加偏移量后的结果。
7. `c++`中的`explicit`关键字只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的, 跟它相对应的另一个关键字是 `implicit`, 意思是隐藏的,类构造函数默认情况下即声明为 `implicit` (隐式).

8. `priority_queue<int, vector<int>, greater<int>> q;`第一个参数是优先级队列类型，第二个是容器类型，不写默认为`vector`，第三个是比较方式`(greater<int>是小堆)`，不写默认大堆(优先输出最大元素)
9. `c`语言风格转型,两种没有区别：
    ```c
    (T)expression
    T(expression) 
    ```
    `c++`风格转型：
    ```cpp
    const_cast<T>(expression)
    dynamic_cast<T>(expression)
    reinterpret_cast<T>(expression)
    static_cast<T>(expression)
    ```

10. typedef:定义一种类型的别名




11. `typedef std::tr1::function<int(const GameCharacter&)> HealthCalcFunc`详解：这段代码是一个C++的`typedef`声明，定义了一个名为`HealthCalcFunc`的类型别名。它指定了一个函数类型，该函数接受一个`GameCharacter`对象的常量引用作为参数，并返回一个`int`类型的值。`std::tr1::function`是一个模板类，用于封装可调用对象（函数、函数指针、函数对象等）。在这里，`std::tr1::function`被用作函数类型的容器。下面是一个示例，展示如何使用`HealthCalcFunc`类型别名来声明变量和使用函数对象进行赋值：
```cpp
// 假设已经定义了GameCharacter类和相应的HealthCalcFunc函数
typedef std::tr1::function<int(const GameCharacter&)> HealthCalcFunc;
// 定义一个函数对象
struct MyHealthCalculator {
    int operator()(const GameCharacter& character) const {
        // 根据character的属性计算生命值
        // 并返回生命值
    }
};
int main() {
    // 声明一个HealthCalcFunc类型的变量
    HealthCalcFunc calcFunc;

    // 使用函数对象进行赋值
    calcFunc = MyHealthCalculator();

    // 调用函数对象并得到计算结果
    GameCharacter character;
    int health = calcFunc(character);

    return 0;
}
```

12. 在上述示例中，`HealthCalcFunc`类型别名用于声明了一个名为`calcFunc`的变量，它是一个函数类型的容器。然后，我们通过将一个函数对象`MyHealthCalculator`赋值给`calcFunc`来进行初始化。最后，我们调用`calcFunc`并传递一个`GameCharacter`对象作为参数，获取计算结果并存储在`health`变量中。通过使用`typedef`和`std::tr1::function`，可以方便地声明和使用函数类型的容器，并将不同的函数对象分配给这个容器来实现不同的行为。这提供了更大的灵活性和可扩展性。请注意，`std::tr1::function`是在C++11之前引入的技术，而在`C++11`及以后的版本中，可以直接使用`std::function`来代替`std::tr1::function`。

13. 详细分析下列代码：`typedef int (*HealthCalcFunc)(const GameCharacter&):`
这段代码是一个C++的`typedef`声明，定义了一个名为`HealthCalcFunc`的类型别名。它指定了一个函数指针类型，该函数指针指向一个接受一个`GameCharacter`对象的常量引用作为参数，并返回一个`int`类型的值的函数。下面是一个示例，展示如何使用`HealthCalcFunc`类型别名来声明变量和使用函数指针进行赋值：
```cpp
// 假设已经定义了GameCharacter类和相应的HealthCalcFunc函数
typedef int (*HealthCalcFunc)(const GameCharacter&);

// 定义一个函数
int MyHealthCalculator(const GameCharacter& character) {
    // 根据character的属性计算生命值
    // 并返回生命值
}

int main() {
    // 声明一个HealthCalcFunc类型的变量
    HealthCalcFunc calcFunc;

    // 使用函数指针进行赋值
    calcFunc = MyHealthCalculator;

    // 调用函数指针并得到计算结果
    GameCharacter character;
    int health = calcFunc(character);

    return 0;
}
```

14. `typename std::list<T>::iterator it = std::find(rep.begin(), rep.end(), item);`
在C++模板中，当使用嵌套类型时，有时需要使用关键字typename来告诉编译器某个名称是一个类型名而不是一个静态成员名。在这个代码片段中，`typename std::list<T>::iterator`是一个嵌套类型，它表示`std::list<T>`容器的迭代器类型。但是，因为这是在模板中使用的，编译器无法确定`iterator`是一个类型名还是一个静态成员名，因此需要使用`typename`来显式指示`iterator`是一个类型名。所以，`typename std::list<T>::iterator`可以理解为指示了`std::list<T>::iterator`是一个类型名，用于声明一个变量的类型。这个变量将被命名为`it`，并且可以用于迭代访问`std::list<T>`容器中的元素。这种使用`typename`关键字的情况通常出现在嵌套类型中，以帮助编译器解析嵌套类型的意图。它在告诉编译器如何解释特定的名称时非常有用。



15. 注意：不同系统会有所差异，一字节为 8 位。注意：`long int `8 个字节，`int` 都是 4 个字节，早期的C编译器定义了 `long int` 占用 4 个字节，`int` 占用 2 个字节，新版的 `C/C++` 标准兼容了早期的这一设定。`uint8_t/uint16_t/uint32t/uint64_t`是什么首先要声明一点`*_t`是`typedef`定义的表示标志，是一种规范化的表示。即`uint8_t/uint16_t/uint32t/uint64_t`都不是新的数据类型，而是通过`typedef`给类型起的别名这些数据类型都是在C99标准中定义的，具体如下:
```cpp
/* There is some amount of overlap with <sys/types.h> as known by inet code */
#ifndef __int8_t_defined
# define __int8_t_defined
typedef signed char             int8_t;
typedef short int               int16_t;
typedef int                     int32_t;
# if __WORDSIZE == 64
typedef long int                int64_t;
# else
__extension__
typedef long long int           int64_t;
# endif
# endif

/* Unsigned.  */
typedef unsigned char           uint8_t;
typedef unsigned short int      uint16_t;
#ifndef __uint32_t_defined
typedef unsigned int            uint32_t;
# define __uint32_t_defined
#endif
#if __WORDSIZE == 64
typedef unsigned long int       uint64_t;
#else
__extension__
typedef unsigned long long int  uint64_t;
#endif
```

16. `Isalnum()`函数用来检测一个字符是否是字母或者十进制数字。如果仅仅检测一个字符是否是字母，可以使用`isalpha()`函数；如果仅仅检测一个字符是否是十进制数字，可以使用`isdigit()`函数。如果一个字符被`isalpha()`或者`isdigit()`检测后返回“真”，那么它被`isalnum()`检测后也一定会返回“真”。

17. 在实际多文件开发中，我们往往使用如下的宏定义来避免发生重复引入：
```cpp
#ifndef _NAME_H
#define _NAME_H
//头文件内容
#endif
```
其中，`_NAME_H` 是宏的名称.需要注意的是,这里设置的宏名必须是独一无二的,不要和项目中其他宏的名称相同.当程序中第一次 `#include` 该文件时，由于 `_NAME_H` 尚未定义，所以会定义 `_NAME_H` 并执行"头文件内容"部分的代码;当发生多次 `#include` 时,因为前面已经定义了 `_NAME_H`,所以不会再重复执行“头文件内容”部分的代码.也就是说,我们可以将前面项目中的 `student.h` 文件做如下修改:
```cpp
#ifndef _STUDENT_H
#define _STUDENT_H
class Student {
    //......
};
#endif
```
虽然该项目 `main.cpp` 文件中仍 `#include` 了2次 `"student.h"`，但鉴于 `_STUDENT_H` 宏只能定义一次，所以 `Student` 类也仅会定义一次。再次执行该项目会发现，其可以正常执行。


18.  `malloc`函数使用形式:关于`malloc`所开辟空间类型:`malloc`只开辟空间，不进行类型检查，只是在使用的时候进行类型的强转。举个例子：‘我’开辟你所需要大小的字节大小空间，至于怎么使用是你的事malloc函数返回的实际是一个无类型指针，必须在其前面加上指针类型强制转换才可以使用指针自身 = `(指针类型*)malloc(sizeof(指针类型)*数据数量)`
```cpp
int *p = NULL;
int n = 10;
p = (int *)malloc(sizeof(int)*n);
```
19. `free`作用：释放`malloc(或calloc、realloc)`函数给指针变量分配的内存空间。注意：使用后该指针变量一定要重新指向`NULL`，防止悬空指针（失效指针）出现，有效规避错误操作。`free`函数在释放空间之后，把内存前的标志变为`0`，且为了防止数据泄露，它会把所释放的空间用`cd`进行填充。
```cpp
int main()
{
    int *p = (int *)malloc(sizeof(int));
    *p = 100;
    free(p);
    p = NULL;
    return 0;
}
```

20. `C++`的内存管理（五区）理解什么时候用堆或栈，我们先回顾下基础知识，在`C++`中，内存分成5个区，他们分别是堆、栈、自由存储区、全局/静态存储区和常量存储区。

21. `extern`是关于声明的关键字:
    变量的声明有两种情况:
    1. 一种是需要建立存储空间的。例如:`int a` 在声明的时候就已经建立了存储空间。
    2. 另一种是不需要建立存储空间的，通过使用`extern`关键字声明变量名而不定义它。 例如：`extern int `a 其中变量 `a` 可以在别的文件中定义的。简单总结：除非有`extern`关键字，否则都是变量的定义。
    3. `extern`修饰函数声明:
    从本质上来讲，变量和函数没有区别。函数名是指向函数二进制块开头处的指针。如果文件`a.c`需要引用`b.c`中的函数，比如在`b.c`中原型是`int fun(int mu)`，那么就可以在`a.c`中声明`extern int fun(int mu)`，然后就能使用`fun`来做任何事情。就像变量的声明一样，`extern int fun(int mu)`可以放在`a.c`中任何地方，而不一定非要放在`a.c`的文件作用域的范围中。对其他模块中函数的引用，最常用的方法是包含这些函数声明的头文件。
```cpp
extern int i; //声明，不是定义
int i; //声明，也是定义
```


22. `Base *p = new Subject;` 其中`Subject`类继承`Base`类,如果没有虚函数重写,这行代码会早绑定(将`Subject`类型强制转换为`Base`,p指向的是`Base`类型),如果有虚函数重写就会晚绑定,而且p指向的是`Subject`对象

23. ```c
    以下是C语言中常用的转义字符的完整列表：
     
    \\：反斜杠
    \'：单引号
    \"：双引号
    \?：问号
    \a：警报（响铃）
    \b：退格
    \f：换页
    \n：换行
    \r：回车
    \t：制表符（水平制表）
    \v：垂直制表
    \0：空字符
    \ooo：八进制表示的字符（其中 ooo 是一个八进制数，范围为 0-377）
    \xhh：十六进制表示的字符（其中 hh 是一个十六进制数，范围为 00-FF）
    ```

24. [assert](https://so.csdn.net/so/search?q=assert&spm=1001.2101.3001.7020)宏的原型定义在<assert.h>中，其作用是如果它的条件返回错误，则终止程序执行

    ```c++
    #include <assert.h>
    void assert( int expression );
    ```

    assert的作用是现计算表达式 expression ，如果其值为假（即为0），那么它先向stderr打印一条出错信息，然后通过调用 abort 来终止程序运行。

    ```c++
    #include <stdio.h>
    #include <assert.h>
    
    int main(int argc, char const *argv[])
    {
        int i = 0;
    
        while (1)
        {
            i++;
    
            printf("Before assert is %d.\n", i);
            
            assert(i <= 5);
            
            printf("After assert is %d.\n", i);	//当i>5时，不会执行到这一句
        }
        
        return 0;
    }
    ```

    **频繁的调用会极大的影响程序的性能，增加额外的开销。** 在调试结束后，可以通过在包含#include <assert.h>的语句之前插入 #define NDEBUG 来禁用assert调用，示例代码如下：

    ```c++
    #include <stdio.h>
    #define NDEBUG
    #include <assert.h>
    ```

    