// 定义常量两种方式
// 1 #define 宏常量
// 2 const 修饰的变量

// 1 #define 宏常量
// #define Day 7 //Day 是常量 不可以修改

// 函数声明
// void swap(int a, int b);
// 函数定义
// void swap(int a,int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
// }

// 单行注释 双斜线 /*多行注释*/
/*int a = 10;
cout << "a=" << a<<endl;
cout << "hello world" << endl;
cout << "一周总共有：" << Day << "天" << endl;*/
// 2 const 修饰的变量
// const int month = 12;//const 修饰的变量也不可修改
// short ：短整型 2字节， int：4字节，long ：windows中占4字节 linux（32位）4字节  linux（64位）8字节
// long long：8字节
// sizeof 返回数据类型大小
/*short num1 = 10;
cout << "short占内存空间为：" << sizeof(short) << endl;
int num2 = 10;
cout << "int占内存空间为：" << sizeof(int) << endl;*/
// 浮点型
// float（7位有效数字） 占4字节， double（15-16位有效数字） 占8字节
// float f1 = 3.14f;//如果不写f，会默认3.14为double类型，然后用float接受时转换为float，如果在后面加上f会直接为float类型，不用转换
// 默认情况下 输出一个小数，只显示6位有效数字

// 科学计数法表示小数
/*float f3 = 3e-2;
cout << "f3=" << f3 << endl;*/

// 字符类型 ''单引号中只能有一个字符，双引号中不能只有1个字符，字符变量占用1个字节
// bool类型占1个字节

// 除法 ：整数和整数相除得到整数， 两个小数可以相除得到的结果可以是小数也可以是整数
// 小数不能做取模运算

// 三目运算符
// 将a和b作比较，将变量大的赋值给变量c
// int a1 = 10;
// int b = 20;
// int c = 0;
// c = (a1 > b ? a1 : b);
// cout << "c=" << c << endl;
// zai C++中三目运算符返回的是变量，可以继续赋值
//(a1 > b ? a1 : b) = 100;
// cout << "a1=" << a1 << endl;
// cout << "b=" << b << endl;

/*swich(表达式){
case1:执行语句;break;
case2:执行语句;break;
...
default:执行语句;break;
};*/
/*
do{}
while();*/

// sizeof(数组名)统计数组长度

// 函数的声明可以有多次，一般写一次

// 函数分文件编写一般有四个步骤
// 1 创建后缀名位.h的文件
// 2 创建后缀名位.cpp的文件
// 3 在头文件中写函数的声明
// 4 在源文件文件中写函数的定义

// 指针占4个字节（32位操作系统,顶部选择x86）  占8个字节（64位操作系统，顶部选择x64）

// 空指针:指向内存中编号为0的空间(0~255之间的内存编号是系统占用的,不可访问),指针初始化没有指向时,就指向这,空指针指向的内存时不可以访问的
// int* p = NULL;//空指针不可以访问

// 野指针:指针变量指向非法的内存空间

// const修饰指针,有三种情况
// 1 const修饰指针,常量指针
// 2 const修饰常量,指针常量
// 3 const即修饰指针,又修饰常量

/*
	1 const修饰指针,常量指针
	在指针前面加上 const , 例如 const int *p = &a;
	此时,指针的指向可以修改,指针指向的值不可以修改

*/

/*
	2 const修饰常量,指针常量
		int * const p = &a; 此时为指针常量
		指针的指向不可以改,指针指向的值可以改

*/

/*
	3 const修饰指针和常量
		const int * const p3 = &a;
		指针指向和指针指向的值都不可以改

*/

// 结构体
/*
struct 结构体名 {结构体成员列表};

struct Student
{
	//成员列表
	string name;//姓名
	int age;    //年龄
	int score;  //分数
};
创建结构体变量：
	1 struct Student s1;
		s1.name="张三";
		s1.age=18;
		s1.score=100;
	2 struct Student s2={"李四",19,80};
	3 定义结构体时创建结构体变量:
	struct Student
{
	//成员列表
	string name;//姓名
	int age;    //年龄
	int score;  //分数
}s3;
创建时可以省略结构体名称 Student s1;
*/

// 通过指针访问结构体变量中的数据 用->
/*
	student s={"张三",18,100};
	student *p = &s;
	cout<<"姓名:"<<p->name<<endl;
*/

// 结构体嵌套结构体
/*
	struct teacher
	{
		int id;//教师编号
		string name;//教师姓名
		int age;//年龄
		struct student stu;
	}
	struct student
	{
		string name;//姓名
			int age;//年龄
			int score;//分数

	}
*/

/*
c++执行时，将内存划分为4个区，代码区，全局区，栈区，堆区，分4个区的意义时不同区存放的数据，赋予不同的声明周期，更灵活的编程
代码区：存放函数体的二进制代码，由操作系统进行管理，代码区只读，存放cpu执行的机器指令
全局区：存放全局变量和静态变量以及常量包括字符串常量和其他常量(包含全局常量，不包括局部常量)，全局区的数据在程序结束后由操作系统释放
栈区：由编译器自动分配释放，存放函数的参数值，局部变量等，函数的形参也会放在栈区
堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收

C++中在程序运行前分为全局区和代码区，栈区和堆区是运行后的区

静态变量 在普通变量前面加static就属于静态变量
static int s_a=10;
static int s_b=10;


栈区数据注意事项，不要返回局部变量的地址(如果返回的话第一次会保留，之后不再保留)
示例:int *func()
{
	int a=10;
	return &a;
}
int main()
{
	int *p = func();

	cout<<*p<<endl;
	cout<<*p<<endl;

	system("pause");

	return 0;
}


再C++中主要使用new再堆区开辟内存
示例:
int *func()
{
	//利用new关键字 可以将数据开辟到堆区，new返回的是创建数据的地址
	//指针 本质也是局部变量放在栈中，指针保存的数据是放在堆区
	int *p = new int(10);
	return p;
}
int main()
{
	int *p = func();
}

在堆区利用new开辟数组
示例:
void test02()
{
	//创建10个整型数据的数组，在堆区
	int  *arr = new int[10];//返回数组首地址
	for(int i=0;i<10;i++)
	{
		arr[i] = i + 100;
	}
	delete[] arr;// 释放数组时，要加[]
}
*/

/*
引用:
int a = 10;
int &b = a;
引用必须初始化,引用初始化后不可更改

引用做函数参数
1.值传递:
void mySwap01(int a,int b)
{
int temp = a;
a = b;
b = temp;
}
2.地址传递
void mySwap02(int * a,int *b)
{
int temp =*a;
*a = *b;
*b = temp;
}
引用做函数的返回值
1.不要返回局部变量的引用
int&  test01()
{
int a = 10;
return a;
}
int main(){
int &ref = test01();
cout<<"ref="<<ref<<endl;//第一次返回的结果正确 因为编译器做了保留
cout<<"ref="<<ref<<endl;//第二次结果错误 a的内存已经释放
}
2.函数的调用可以作为左值
int&  test02()
{
static int a = 10;//静态变量，存放在全局区，全局区上的数据在程序结束后系统释放
return a;
}
int main(){
int &ref2 = test02();
cout<<"ref2="<<ref2<<endl;//结果为10
cout<<"ref2="<<ref2<<endl;//结果为10
test02() = 1000;//如果函数的返回值是引用 函数调用可以作为左值
cout<<"ref2="<<ref2<<endl;//结果为1000
cout<<"ref2="<<ref2<<endl;//结果为1000
}

引用的本质:引用的本质在C++内部就是一个指针常量
//发现是引用，转换为int* const ref = &a;
void func(int& ref)
{
ref=100;//ref是引用，转换为*ref=100；
}
int main()
{
int a=100;

//自动转换为int* const ref = &a;指针常量是指针指向不可改，也说明为什么引用不可更改
int& ref =a;
ref = 20;//内部发现ref是引用，自动转换为:*ref =20;

cout<<"a:"<<a<<endl;
cout<<"ref:"<<ref<<endl;

func(a);
return 0;
}

常量引用
int & ref=10;//错误用法
//加上const之后 编译器将代码修改为 int temp=10; cosnt int &ref = temp;
const int & ref=10;//正确用法
*/
/*
	函数声明由默认参数，函数实现就不能有默认参数，声明和实现只能有一个有默认参数
*/

/*
	函数重载:函数名相同 参数不同 函数返回值不能作为函数重载的条件
	1.引用作为函数重载的条件
	void func(int &a) //int &a = 10; 不合法
	{
		cout<<"func(int &a)调用"<<endl;
	}
	void func(const int &a) //const int &a = 10; 合法
	{
		cout<<"func(const int &a)调用"<<endl;
	}
	int main（）
	{
		int a = 10;
		func(a);//走第一个
		func(10);//走第二个
	}

	2.函数重载碰到默认参数
	void func(int a)
	{
		cout<<"func(int a)调用"<<endl;
	}
	void func(int a,int b=10)
	{
		cout<<"func(int a,int b=10)调用"<<endl;
	}
	int main()
	{
		//func(10)//错误 出现二义性 编译器不知道调用哪个
	}
*/
/*
	函数占位参数:返回值类型 函数名 (数据类型){},占位参数也可以有默认参数
	void func(int a,int = 10)
	{
		cout<<"this is func"<<endl;
	}
*/
/*
	类访问权限
	protected 子类可以访问父类中protected内容
	struct和class默认的访问权限不同 struct默认为公有 class默认为私有
*/

/*
	构造函数和析构函数:
	构造函数和析构函数没有返回值
	构造函数可以有参数 所以可以重载
	析构函数不可以有参数 所以不能重载
	程序在堆笑销毁前自动调用析构，无需手动调用，而且只会 调用一次

	拷贝构造函数:
	class Person
	{
	public:

		Person(int a)
		{
			age=a;
		}
		Person(const Person &p)
		{
			age=p.age;//将传入对象属性拷贝到当前对象
		}

		int age;
	}

	显示法创建对象:
	Person p1;
	Person p2 = Person(10);
	Person p3 = Person(p2);

	Person(10);//匿名对象 特点：当前执行结束后 系统会立即回收掉匿名对象


	Person(p3);//不要利用拷贝构造函数初始化匿名对象 编译器会认为 Person(p3)等价于Person p3;

	隐式转换法创建对象:
	Person p4 = 10;//相当于写了 Person p4 = Person(10);
	Person p5 = p4;//拷贝构造

	拷贝函数调用时机 3种
	1.使用一个已经创建完毕的对象来初始化一个新对象
	class Person
	{
	public:
		Person()
		{
			cout << "Person默认构造函数调用" << endl;
		}
		Person(int age)
		{
			m_Age = age;
			cout << "Person有参构造函数调用" << endl;
		}
		Person(const Person &p)
		{
			m_Age = p.m_Age;
			cout << "Person拷贝构造函数调用" << endl;
		}
		~Person()
		{
			cout << "Person析构函数调用" << endl;
		}
		int m_Age;

	};
	void test01()
	{
		Person p1(20);
		Person p2(p1);
	}
	int main() {
		test01();
		return 0;

	2.值传递的方式给函数参数传值

	class Person
	{
	public:
		Person()
		{
			cout << "Person默认构造函数调用" << endl;
		}
		Person(int age)
		{
			m_Age = age;
			cout << "Person有参构造函数调用" << endl;
		}
		Person(const Person &p)
		{
			m_Age = p.m_Age;
			cout << "Person拷贝构造函数调用" << endl;
		}
		~Person()
		{
			cout << "Person析构函数调用" << endl;
		}
		int m_Age;

	};
	void test01()
	{
		Person p1(20);
		Person p2(p1);
	}
	void dowork(Person p)
	{

	}
	void test02()
	{
		Person p;
		dowork(p);
	}
	int main() {
		//test01();
		test02();
		return 0;
	}
	3.以值的方式返回局部对象

	class Person
	{
	public:
		Person()
		{
			cout << "Person默认构造函数调用" << endl;
		}
		Person(int age)
		{
			m_Age = age;
			cout << "Person有参构造函数调用" << endl;
		}
		Person(const Person &p)
		{
			m_Age = p.m_Age;
			cout << "Person拷贝构造函数调用" << endl;
		}
		~Person()
		{
			cout << "Person析构函数调用" << endl;
		}
		int m_Age;

	};
	//3.值方式返回局部对象
	Person doWork2()
	{
		Person p1;
		cout << (int*)&p1 << endl;
		return p1;
	}
	void test03()
	{
		Person p = doWork2();
		cout << (int*)&p << endl;
	}

	int main() {
		test03();
		return 0;
	}
*/
/*
* 深拷贝构造
	class Person
	{
	public:

		Person(int age, int height)
		{
			m_Age = age;
			m_Height = new int(height);
			cout << "Person有参构造函数调用" << endl;
		}

		//深拷贝 解决浅拷贝带来的问题
		Person(const Person &p)
		{
			cout << "Person拷贝构造函数调用" << endl;
			m_Age = p.m_Age;
			//m_Height = p.m_Height;编译器默认实现的拷贝
			//深拷贝操作
			m_Height = new int(*p.m_Height);

		}
		~Person()
		{
			if (m_Height != NULL)
			{
				delete m_Height;
				m_Height = NULL;
			}
			cout << "Person析构函数调用" << endl;
		}
		int m_Age;
		int* m_Height;

	};
	void test01()
	{
		Person p1(20,160);
		cout << "p1的年龄为：" << p1.m_Age << "身高为："<<p1.m_Height<<endl;
		Person p2(p1);
		cout << "p2的年龄为：" << p2.m_Age << "身高为：" << p2.m_Height << endl;
	}

	int main() {
		test01();
		return 0;
	}
*/

/*
初始化列表:用来初始化属性
构造函数():属性1(值1),属性2(值2)...{}
*/

/*
类对象作为函数成员时 先构造函数成员的对象 再构造自身类对象， 先析构自身对象 再析构其他类对象
//手机类
class Phone
{
public:
	Phone(string pName) :m_PName(pName)
	{
		cout << "phone的构造函数调用" << endl;
	}
	~Phone()
	{
		cout << "phone的析构函数调用" << endl;
	}
	//手机品牌
	string m_PName;
};
class Person
{
public:
	//姓名
	string m_Name;
	//手机
	Phone m_Phone;
	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "person的构造函数调用" << endl;
	}
	~Person()
	{
		cout << "person的析构函数调用" << endl;
	}
};
void test01()
{
	Person p("张三", "iphone");
	cout << p.m_Name << "拿着：" << p.m_Phone.m_PName << endl;
}
int main() {
	test01();
	return 0;
}
*/

/*
//静态成员:静态成员变量 静态成员函数
//静态成员变量
class Person
{
	//静态成员变量:所有对象共享 编译阶段分配内存(在全局区) 类内声明 类外初始化
public:
	static int m_A;//类内声明

	//静态成员变量也是有访问权限的
private:
	static int m_B;
};

int Person::m_A = 100;//类外初始化
int Person::m_B = 200;//类外初始化
void test01() {
	Person p;
	cout << p.m_A << endl;
	//cout << p.m_B << endl; 私有数据不能访问

}
void test02()
{

	//静态成员变量 不属于某个对象上 所有对象都共享同一分数据
	//因此静态成员变量有两种访问方式
	//1.通过对象进行访问
	Person p;
	cout << p.m_A << endl;
	//2.通过类名进行访问
	cout << Person::m_A << endl;
}
int main() {
	test01();
	return 0;
}
*/

/*
	静态成员函数:所有对象共享一个函数 静态成员函数只能访问静态成员变量
*/

/*
	在C++种类内的成员变量和成员函数分开存储  只有非静态成员变量才属于类的对象上
	空对象占用内存空间为1字节  C++编译器会给每个空对象也分配一个字节空间 是为了区分空对象占内存的位置
	每个空对象也应该有一个独一无二的内存地址
*/

/*
	this指针:
	当形参和成员变量同名时，可用this指针来区分
	在类的非静态成员函数中返回对象本身， 可用return *this
class Person
{
public:
	Person(int age)
	{
		this->age = age;
	}
	Person& PersonAddAge(Person& p)//如果返回类型为Person会创建新的对象返回 每次调用都创建新对象 但是Person&会返回本身
	{
		this->age += p.age;
		return *this;
	}
	int age;
};
void test02()
{
	Person p1(10);
	Person p2(10);
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);//链式调用  由return *this实现
	cout << "p2的年龄为：" << p2.age << endl;
}
int main() {
	test02();
	return 0;
}
*/

/*
C++中空指针可以调用成员函数 但是要注意有没有用到this指针
如果用到this指针  加以判断保证代码的健壮性
class Person
{
public:
	void showClassName()
	{
		cout << "this is Person class " << endl;
	}
	void showPersonAge()
	{
		cout << "age=" << m_Age << endl;//m_Age相当于this->m_Age
	}
	int m_Age;
};
void test01()
{
	Person* p = NULL;
	p->showClassName(); //正确  空指针可以访问成员函数 但是不能有this指针
	//p->showPersonAge(); 错误
}
int main()
{
	test01();
	return 0;
}
*/

/*
const修饰成员函数:
常函数:	成员函数后加const后我们成为这个函数为常函数
		常函数内不可以修改成员属性
		成员属性声明时加关键字mutable后，在常函数中依然可以修改
常对象:	声明对象前加const称该对象为常对象
		常对象只能调用常函数


class Person
{
public:
	//this指针的本质 是指针常量 指针的指向是不可以修改的
	//在成员函数后面加const 修饰的是this指向，让指针指向的值也不可以修改 叫做常函数
	void showPerson() const
	{
		//m_A = 100; 因为加入了const 所以不能修改
		m_B=100;//因为变量前加了mutable 所以可以修改
		//this =NULL; this指针不可以修改指针的指向 但是this指针指向的值是可以修改的
	}

	int m_A;
	mutable int m_B; //特殊变量 即使在常函数中 在常对象中 也可以修改这个值
};
void test01()
{
	Person p;
	p.showPerson();
}
void test01()
{
	const Person p;//在对象前加一个const变成常对象 该对象属性值不允许修改，但是m_B加了mutable可以修改
	//常对象只能调用常函数
}
int main()
{
	test01();
	return 0;
}
*/

/*
友元三种实现:全局函数做友元
			类做友元
			成员函数做友元
全局函数做友元:
class Building
{
	//goodGay全局函数是友元函数 可以访问building中的私有成员
	friend void goodGay(Building* building);
public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
public:
	string m_SittingRoom;//客厅
private:
	string m_BedRoom;//卧室
};

void goodGay(Building *building)
{
	cout << "正在访问：" << building->m_BedRoom << endl;
	cout << "正在访问：" << building->m_SittingRoom << endl;
}
void test01()
{
	Building b;
	goodGay(&b);
}
int main() {
	test01();
	return 0;
}

类做友元:
class Building
{
	friend class GoodGay;
public:
	Building();
	string m_SittingRoom;//客厅
private:
	string m_BedRoom;//卧室

};
class GoodGay
{
public:
	GoodGay();
	void visit();//参观函数 访问Building中的属性
	Building* building;
};
GoodGay::GoodGay()
{
	//创建建筑物对象
	building = new Building;
}
void GoodGay::visit()
{
	cout << "正在访问：" << building->m_SittingRoom << endl;
	cout << "正在访问：" << building->m_BedRoom << endl;
}
void test01()
{
	GoodGay g;
	g.visit();
}
//类外成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
int main()
{
	test01();
	return 0;
}



成员函数做友元:
class Building;
class GoodGay
{
public:
	GoodGay();
	void visit();//让visit函数可以访问Building中私有成员
	void visit2();//让visit2函数不可以访问Building中私有成员
	Building* building;
};
class Building
{
	//GoodGay类下的visit成员函数作为本类的friend 可以访问私有成员
	friend void GoodGay::visit();
public:
	Building();
	string m_SittingRoom;//客厅
private:
	string m_BedRoom;//卧室

};

GoodGay::GoodGay()
{
	//创建建筑物对象
	building = new Building;
}
void GoodGay::visit()
{
	cout << "visit正在访问：" << building->m_SittingRoom << endl;
	cout << "visit正在访问：" << building->m_BedRoom << endl;
}
void GoodGay::visit2()
{
	cout << "visit2正在访问：" << building->m_SittingRoom << endl;
}
void test01()
{
	GoodGay g;
	g.visit();
	g.visit2();
}
//类外成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
int main() {
	test01();
	return 0;
}
*/

/*
运算符重载:
class Person
{
public:
	int m_A;
	int m_B;
	Person(int m_A=0, int m_B=0) { this->m_A = m_A; this->m_B = m_B; }
	//加法重载(成员函数)
	//Person operator+(Person &p)
	//{
	//	Person temp;
	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;
	//	return temp;
	//}

};
//加法重载(类外重载)
Person operator+(Person& p1,Person &p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
Person operator+(Person& p1, int num)
{
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}
void test01()
{
	Person p1(10, 10);
	Person p2(10, 10);
	Person p3 = p1 + p2;
	Person p4 = p1 + 100;
	cout << "p3.m_A=" << p3.m_A << endl;
	cout << "p3.m_B=" << p3.m_B << endl;
	cout << "p4.m_A=" << p4.m_A << endl;
	cout << "p4.m_B=" << p4.m_B << endl;
}
int main() {
	test01();
	return 0;
}


//赋值运算符重载
class Person
{

public:
	int* m_Age;
	Person(int age)
	{
		m_Age = new int(age);
	}
	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;

		}
	}
	Person& operator=(Person&p)
	{
		if (this->m_Age != NULL)
		{
			delete this->m_Age;
			m_Age = NULL;
		}
		this->m_Age = new int(*p.m_Age);
		return *this;
	}

};
void test01()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);
	p3=p2 = p1;
	cout << "p1的年龄为:" << *p1.m_Age << endl;
	cout << "p2的年龄为:" << *p2.m_Age << endl;
	cout << "p3的年龄为:" << *p3.m_Age << endl;
}
int main() {
	test01();
	return 0;
}





//左移运算符重载  前置++和后置++运算符重载
class MyInteger
{
	friend ostream& operator<<(ostream& cout,MyInteger);
private:
	int m_Num;
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//重载++运算符(前置)
	MyInteger& operator++()
	{
		this->m_Num++;
		return *this;
	}
	//重载++运算符(后置)
	MyInteger operator++(int)//int代表占位参数 可以用于区分前置和后置递增
	{
		//后置递增返回的是局部引用 函数调用结束后 对象就释放掉 所以不能返回引用 要返回值
		MyInteger temp = *this;
		m_Num++;
		return temp;
	}
};

ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num;
	return cout;
}

void test01()
{
	MyInteger myint;
	cout << ++myint << endl;
}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
}
int main() {
	test01();
	test02();
	return 0;
}
*/

/*
继承:
	public:公有继承 ，父类中属性 访问权限不变
	protected:保护继承 父类中的public和protected都变成protected权限
	private:私有继承 父类中的public和protected都变成private权限


	继承中的构造和析构的顺序:父类构造->子类构造->子类析构->父类析构


	继承同名成员处理方式: 访问子类同名成员 直接访问即可  s.m_A
						访问父类同名成员 需要加减作用域 s.Base::m_A
	如果子类中出现和父类同名的成员函数 子类的同名成员会隐藏掉父类中所有同名成员函数
	如果想访问到父类中被隐藏的同名成员函数需要加作用域


	继承中同名静态成员处理方法:静态成员和非静态成员的处理方式一至 加作用域即可
	或者Son::Base::m_A   Son::Base::func()访问

	可以同时继承多个类:
	class 子类:继承方式 父类1,继承方式 父类2
	实际开发中不建议使用多继承

*/

/*
	菱形继承:
					动物
				-    -
				-      -
				羊        骆驼
				-     -
					- -
					羊驼
菱形继承问题：1羊继承了动物的数据 骆驼继承了动物的数据 当羊驼使用数据时 会产生二义性
				2羊驼继承自动物的数据继承了两份，其实只需要一份即可

利用虚继承 继承是加上关键字virtual变为虚继承 Animal称为虚基类  例: class Sheep:virtual public Animal{};
虚继承后 基类数据就只有一份 虚继承时继承的是vbptr(虚基类指针) 它会指向各自vbtable(虚基类表) 虚基类表记录了各自偏移量(不相同)
两个指针会通过偏移量找到唯一的一份数据
*/

/*
多态:
		静态多态: 函数重载和运算符重载 复用函数名
		动态多态:派生类和虚函数实现运行时多态
静态和动态的区别:
			静态多态的函数地址早绑定，编译阶段确定函数地址
			动态多态的函数地址晚绑定，运行阶段确定函数地址

//多态

//动物类
class Animal
{
private:

public:
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};
//狗类
class Dog :public Animal {
public:
		void speak()
	{
		cout << "小狗在说话" << endl;
	}
};
//猫类
class Cat :public Animal
{
public:
	//虚函数
		void speak()
	{
		cout << "小猫在说话" << endl;
	}
};
//执行说话的函数
//地址早绑定 在编译阶段确定函数地址
//如果想执行让猫说话 那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，进行地址晚绑定
//解决办法是 在基类的函数前加上virtual 变成虚函数

//动态多态满足条件
//1. 有继承关系
//2. 子类重写父类的虚函数

//动态多态使用
//父类指针或者引用 执行子类对象
void doSpeak(Animal &animal)
{
	animal.speak();
}
void test01()
{
	Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);
}
int main() {
	test01();
	return 0;
}

*/

/* P137  多态实现 计算器类
class Calculator
{
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		//开发中提倡开闭原则:对扩展进行开放，对修改进行关闭
		//
	}
	int m_Num1;
	int m_Num2;
};
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//加法计算器类
class AddCalculator :public AbstractCalculator
{
	virtual int getResult()
	{
		return m_Num1 +m_Num2;
	}
};
//减法计算器类
class SubCalculator :public AbstractCalculator
{
	virtual int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
//乘法计算器类
class MulCalculator :public AbstractCalculator
{
	virtual int getResult()
	{
		return m_Num1 * m_Num2;
	}
};
void test02()
{
	//多态使用条件
	//父类指针或者引用指向子类对象

	//加法运算
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	AbstractCalculator* abcd = new SubCalculator;
	abcd->m_Num1 = 100;
	abcd->m_Num2 = 100;
	cout << abcd->m_Num1 << "-" << abcd->m_Num2 << "=" << abcd->getResult() << endl;
	delete abcd;
}
void test01()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;

}
int main() {
	test01();
	test02();
	return 0;
}
*/

/*P138 纯虚函数
写法:virtual 返回值类型 函数名 (参数列表) =0 ;
当类中有纯虚函数 类称为抽象类
抽象类: 无法实例化对象，子类必须重写抽象类中的纯虚函数，否则也属于抽象类

class Base {
public:
	//只要有一个纯虚函数，这个类就称为抽象类
	virtual void func() = 0;
};
class Son :public Base
{
public:
	virtual void func() {
		cout << "func函数的调用" << endl;
	};
};
void test01() {
	Base* base = new Son;
	base->func();
}
int main()
{
	test01();
	return 0;
}

*/
/*P140 虚析构和纯虚析构
多态使用时，如果子类中有属性开辟到堆区，父类指针在释放时无法调用子类的析构代码
解决方法：将父类中的析构函数改为虚析构或者纯虚析构
虚析构和纯虚析构的共性：
	都可以解决父类指针释放子类对象
	都需要有具体的函数实现
虚析构和纯虚析构的区别：
	如果是纯虚析构，该类属于抽象类，无法实例化对象
class Animal
{
public:
	Animal()
	{
		cout << "Animal的构造函数调用" << endl;
	}
	//virtual ~Animal()
	//{
	//	cout << "Animal的析构函数调用" << endl;
	//}
	//纯虚析构  纯虚析构和虚析构只能存在一个
	//有纯虚析构后，也属于抽象类 不能实例化
	virtual ~Animal() = 0;
	virtual void speak()=0;
};
//Animal下的纯虚析构 当Animal中也有堆区数据时 自身也需要析构
Animal::~Animal()
{
	cout << "Animal的纯虚析构函数调用" << endl;
}
class Cat :public Animal
{
public:
	Cat(string name) {
		cout << "Cat的构造函数调用" << endl;
		m_Name = new string(name);
	}
	virtual void speak() {
		cout <<*m_Name<< "小猫在说话" << endl;
	}
	string* m_Name;
	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "Cat的析构函数调用" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
};
void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//父类指针在析构时候，不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄露，应该改为虚析构就会走子类析构函数
	delete animal;

}
int main()
{
	test01();
	return 0;
}
*/
/*P143写文件
文件类型分为两种：文本文件和二进制文件
	文本文件：文件以文本的ASCII码形式存储在计算机中
	二进制文件：文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们
操作文件的三大类：
	1 ofstream：写操作
	2 ifstream：读操作
	3 fstream：读写操作
写文件步骤如下：
1 包含头文件：
	#include<fstream>
2 创建流对象
	ofstream ofs;
3 打开文件
	ofs.open("文件路径",打开方式);
4 写数据
	ofs<<"写入的数据";
5 关闭文件
	ofs.close();

文件打开方式：
打开方式             解释
ios::in				为读文件而打开文件
ios::out			为写文件而打开文件
ios::ate			初始位置：文件尾
ios::iapp			追加方式写文件
ios::trunc			如果文件存在 先删除 再创建
ios::binary			二进制方式
文件打开方式可以配合使用 利用 | 操作符
ios::binary | ios::out



void test01()
{
	//1 包含头文件 fstream
	//2 创建流对象
	ofstream ofs;
	//3 指定打开方式
	ofs.open("test.txt",ios::out);
	//4 写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;
	ofs.close();
}
void test02()
{
	//1 包含头文件

	//2 创建流对象
	ifstream ifs;
	//3 打开文件 判断是否打开成功
	ifs.open("test.txt",ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//4 读数据
		//第一种
			//char buf[1024] = {0};
			//while (ifs >> buf)
			//{
			//	cout << buf << endl;
			//}
		//第二种
			//char buf[1024] = { 0 };
			//while (ifs.getline(buf,sizeof(buf)))
			//{
			//	cout << buf << endl;
			//}
		//第三种
			//string buf;
			//while (getline(ifs,buf))
			//{
			//	cout << buf << endl;
			//}
		//第四种 不推荐用
			//char c;
			//while ((c=ifs.get())!=EOF)
			//{
			//	cout << c;
			//}
	//5 关闭文件
			ifs.close();
}
int main()
{
	test01();
	test02();
	return 0;
}
*/
/*P145二进制读写文件
二进制方式写文件主要利用流对象调用成员函数write
函数原型: ostream& write(const char* buffer,int len);
二进制方式读文件主要利用流对象调用成员函数read
函数原型:istream& read(char *buffer,int len);
参数解释:字符指针buffer指向内存中一段空间。len是读写的字节数

//二进制文件 写文件
class Person
{
public:
	char m_Name[64];//姓名
	int m_Age;//年龄
};
void test01()
{
	ofstream ofs("person.txt", ios::out | ios::binary);
	//ofs.open("person.txt",ios::out | ios::binary);
	Person p = { "张三",18 };
	ofs.write((const char*)&p,sizeof(Person));
	ofs.close();
}
//二进制文件 读文件
void test02()
{
	ifstream ifs;
	ifs.open("person.txt",ios::in|ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	Person p;
	ifs.read((char *)&p,sizeof(Person));
	cout << "姓名："<< p.m_Name  << "年龄："<<p.m_Age << endl;
	ifs.close();
}
int main()
{
	//test01();
	test02();
	return 0;
}
*/

/*p168函数模板基本句法
模板分为：函数模板和类模板
函数模板作用：建立一个通用函数，其函数返回值类型和形参类型可以不具体指定，用一个虚拟的类型来代表

template<typename T>
函数声明或定义
//函数模板
template<typename T>//声明一个模板，告诉编译器T是通用数据类型
void mySwap(T &a,T&b)
{
	T temp = a;
	a = b;
	b = temp;
}
void test01()
{
	int a = 10;
	int b = 20;
	//有两种方式使用函数模板
	//1.自动类型推导
	mySwap(a,b);
	cout << "a=" << a << endl;
	cout << "b=" << b<< endl;
	//2.显示指定类型
	mySwap<int>(a, b);
}
int main()
{
	test01();
	return 0;
}




//函数模板注意事项
//函数模板
template<typename T>//声明一个模板，告诉编译器T是通用数据类型
void mySwap(T &a,T&b)
{
	T temp = a;
	a = b;
	b = temp;
}
//1.自动类型推导，必须推导出一致的数据类型T才可以使用
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//有两种方式使用函数模板
	//1.自动类型推导
	mySwap(a,b);
	//mySwap(a,c);//错误 推导出不一致的数据类型
	cout << "a=" << a << endl;
	cout << "b=" << b<< endl;
	//2.显示指定类型
	mySwap<int>(a, b);
}

//2.模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()
{
	cout << "func调用" << endl;
}
void test02()
{
	func<int>();
}
int main()
{
	test01();
	test02();
	return 0;
}
*/

/*P171普通函数与函数模板的区别

//1.普通函数调用可以发生隐式类型转换
//2.含糊模板 用自动类型推导，不可以发生隐式类型转换
//3.函数模板，用显示指定类型，可以发生隐式类型转换
//普通函数
int myAdd01(int a, int b)
{
	return a + b;
}
//函数模板
template<class T>
T myAdd02(T a, T b)
{
	return a + b;
}
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';//a对应97  c对应99
	cout << myAdd01(a, c) << endl;

	//自动类型推导
	myAdd02(a,b);
	cout << myAdd02(a, b) << endl;
	//cout << myAdd02(a, c) << endl;//错误


	//显示指定类型 可以隐式转换
	cout << myAdd02<int>(a, c)<< endl;
}
int main()
{
	test01();
	return 0;
}
*/

/*P172 普通函数和函数模板调用规则
 1.如果函数模板和普通函数都可以调用，优先调用普通函数
 2.可以通过空模板参数列表 强制调用 函数模板
 3.函数模板可以发生函数重载
 4.如果函数模板可以产生更好的匹配，优先调用函数模板
 既然提供了函数模板，最好就不要提供普通函数，否则容易产生二义性
 void myPrint(int a,int b)
{
	cout << "调用的普通函数" << endl;
}
template<class T>
void myPrint(T a, T b)
{
	cout << "调用的模板函数" << endl;
}
template<class T>
void myPrint(T a, T ,T c)
{
	cout << "调用的重载模板函数" << endl;
}
void test01()
{
	int a = 10;
	int b = 20;
	myPrint(a,b);//优先调用普通函数

	//通过空模板参数列表，强制调用函数模板
	myPrint<>(a,b);
	myPrint<>(a,b,b);//重载

	//如果函数模板产生更好的匹配，优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1,c2);
}
int main()
{
	test01();
	return 0;
}
*/

/*P173 模板的局限性
模板的通用性不是万能的      有些特定数据类型，需要用具体化方式做特殊实现

class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
//对比两个数据是否相等
template <class T>
bool myCompare(T&a,T&b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <>
bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age && p1.m_Name == p2.m_Name)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void test01()
{
	int a = 10;
	int b = 20;
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
}
void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1!=p2" << endl;
	}
}
int main()
{
	test01();
	test02();
	return 0;
}
*/

/*P174类模板基本语法
类模板作用：建立一个通用类，类中的成员，数据类型可以不具体指定，用一个虚拟类型来代表

template<class T>
类

//类模板
template<class NameType,class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "name:" << this->m_Name << "  age:" << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

void test01()
{
	Person<string, int> p1("孙悟空", 999);
	p1.showPerson();
}

int main()
{
	test01();
	//test02();
	return 0;
}
*/

/*P175类模板与函数模板区别
1.类模板没有自动类型推导的使用方式
2.类模板在模板参数列表中可以有默认参数

//类模板
template<class NameType,class AgeType=int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "name:" << this->m_Name << "  age:" << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

//1.类模板没有自动类型推导使用方式
void test01()
{
	//Person p1("孙悟空", 999); 错误用法 类模板不能自动推导数据类型

}
//2.类模板在模板参数列表中可以有默认参数
void test02()
{
	Person<string> p("猪八戒", 999);//年龄的模板参数有默认值 可以不赋值int
	p.showPerson();
}
int main()
{
	test01();
	test02();
	return 0;
}
*/

/*P176类模板中成员函数创建时机
类模板中成员函数和普通类中成员函数创建时机是有区别的
1.普通类中的成员函数一开始就可以创建
2.类模板中的成员函数在调用时才创建
//类模板成员函数创建时机
class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}

};
class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}

};
template<class T>
class MyClass
{
public:
	T obj;
	//类模板中成员函数
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}

};

void test01()
{
	MyClass<Person1>m;
	m.func1();
	//m.func2(); 错误 没有showPerson2函数
	MyClass<Person2>m2;
	m2.func2();
	//m2.func1(); 错误 没有showPerson1函数

}

int main()
{
	test01();
	//test02();
	return 0;
}
*/

/*p177类模板对象做函数参数
三种方式：
 1.指定传入的类型 直接显示对象的数据类型
 2.参数模板化     将对象中的参数变为模板进行传递
 2.整个类模板化   将这个对象类型 模板化进行传递

template<class T1, class T2>
class Person
{
public:
	T1 m_Name;
	T2 m_Age;
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "name：" << this->m_Name << " age：" << this->m_Age << endl;
	}
};
//1.指定传入类型
void printPerson1(Person<string, int>& p)
{
	p.showPerson();
}
void test01()
{
	Person<string, int>p("sun", 100);
	printPerson1(p);
}
//2.参数模板化
template<class T1,class T2>
void printPerson2(Person<T1,T2>& p)
{
	p.showPerson();
	//cout << "T1的类型为：" << typeid(T1).name() << endl;
	//cout << "T2的类型为：" << typeid(T2).name() << endl;

}
void test02()
{
	Person<string, int>p("zhu", 99);
	printPerson1(p);
}
//3.将整个类模板化
template<class T>
void printPerson3(T& p)
{
	p.showPerson();
}
void test03()
{
	Person<string, int>p("tang", 30);
	printPerson1(p);
}
int main()
{
	test01();
	test02();
	test03();
	return 0;
}
*/

/*P178类模板与继承
当类模板碰到继承时，注意：
当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
如果不指定，编译器无法给子类分配内存
如果想灵活指定出父类中T的类型，子类也需要变为类模板
//类模板与继承
template<class T>
class Base
{T m;};
class Son :public Base<int>//子类继承时需要指定父类中的T类型
{};
//想要灵活的指定父类中T类型，子类也需要变为类模板
template<class T1,class T2>
class Son2 :public Base<T2>
{T1 obj;};
void test01()
{Son2<int, char>S2;}
*/

/*P179类模板成员函数类外实现
template<class T1, class T2>
class Person
{
public:
	T1 m_Name;
	T2 m_Age;
	Person(T1 name, T2 age);
	void showPerson();
};
template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}
template<class T1,class T2>
void Person<T1, T2>::showPerson()
{
	cout << "name：" << this->m_Name << " age：" << this->m_Age << endl;
}
void test01()
{
	Person<string, int>p("Tom",20);
	p.showPerson();
}
int main()
{
	test01();
	return 0;
}
*/

/*P180类模板份文件编写
类模板中成员函数创建时机是在调用阶段，导致份文件编写时链接不到
解决方法1：直接包含.cpp源文件
解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp hpp是约定的名字，并不是强制
//#include "person.cpp"//第一种解决方式.h看不见成员函数 类模板的成员函数创建时机晚 所以改成.cpp
//第二种解决方式  将.h和.cpp中的内容写到一起 将后缀名改为.hpp文件
#include"person.hpp"
*/

/*P181类模板与友元
全局函数内实现-直接在类内声明友元即可
全局函数类外实现-需要提前让编译器知道全局函数的存在
template<class T1, class T2>
class Person;
template<class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
	cout << "name：" << p.m_Name << " age：" << p.m_Age << endl;
}
template<class T1, class T2>
class Person
{
	//全局函数类内实现
	friend void printPerson(Person<T1,T2> p)
	{
		cout << "name：" << p.m_Name << " age：" << p.m_Age << endl;
	}
	//全局函数类外实现
	//加空模板的参数列表
	//如果全局函数是类外实现 需要让编译器提前知道这个函数的存在
	friend void printPerson2<>(Person<T1, T2> p);

private:
	T1 m_Name;
	T2 m_Age;
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
};
//1.全局函数在类内实现
void test01()
{
	Person<string, int>p("Tom",20);
	printPerson(p);
}
//2.全局函数在类外实现
void test02()
{
	Person<string, int>p("Jerry", 20);
	printPerson2(p);
}
int main()
{
	test01();
	test02();
	return 0;
}
*/

/*P184类模板案例
void test01()
{
	MyArray <int>arr1(5);
	for (int i=0;i<5;i++)
	{
		arr1.Push_Back(i);
	}
	MyArray<int>arr2(arr1);
	MyArray<int>arr3(100);
	arr3 = arr1;
}
int main()
{
	test01();
	return 0;
}
*/

/*P185  STL(标准模板库)
广义上分为 容器 算法 迭代器
容器和算法之间通过迭代器进行无缝连接
STL几乎所有的代码都采用了模板类或者模板函数
STL大体分为六大组件：容器 算法 迭代器 仿函数 适配器(配接器) 空间配置器


STL容器就是将运用最广泛的一些数据结构实现出来 数组 链表 栈 队列 树等等
容器分为序列式容器和关联式容器：
序列式容器：强调值的排序，序列式容器中的每个元素均有固定的位置
关联式容器：二叉树结构，各元素之间没有严格的物理上的顺序关系

算法分为质变算法和非质变算法：
质变算法：是指运算过程中会更改区间内的元素的内容，例如拷贝 替换 删除等等
非质变算法：是指运算过程中不会更改区间内的元素内容 例如查找 计数 遍历 寻找极值等等。

迭代器：容器和算法之间的粘合剂
每个容器都有自己专属的迭代器
迭代器种类：
输入迭代器：对数据的只读访问
输出迭代器：对数据的只写访问
前向迭代器：读写操作 并能向前推进迭代器
双向迭代器：读写操作，并能向前和向后操作
随机访问迭代器：读写操作 可以以跳跃的方式访问任意数据 功能最强的迭代器
最后两个迭代器用的多。
*/

/*P186 vector存放内置数据类型
容器：vector
算法：for_each
迭代器：vector<int> ::iterator
void myPrint(int val)
{
	cout << val << endl;
}
//vector容器存放内置数据类型
void test01()
{
	vector<int> v;//创建一个vector容器
	v.push_back(10);//向容器中插入数据10 尾插法
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//通过迭代器访问容器中的数据
	vector<int>::iterator itBegin = v.begin();//起始迭代器 指向容器中第一个元素
	vector<int>::iterator itEnd = v.end();//结束迭代器 指向容器中最后一个元素的下一个位置
	//第一种遍历方式
	while (itBegin!=itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	//第二种遍历方式
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << endl;
	}
	//第三种遍历方式 利用STL中提供的遍历算法
	for_each(v.begin(), v.end(), myPrint);
}
*/

/*P187vector存放自定义数据类型
//vector容器中存放自定义数据类型
class Person
{
public:
	string  m_Name;
	int m_Age;
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

};
void test01()
{
	vector<Person> v;
	Person p1("aaa",10);
	Person p2("bbb",20);
	Person p3("ccc",30);
	Person p4("ddd",40);
	Person p5("eee",50);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	//遍历容器中的数据
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl;
	}
}
//存放自定义类型的指针
void test02()
{
	vector<Person*> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	for (vector<Person*>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "姓名：" << (*it)->m_Name << " 年龄：" << (*it)->m_Age << endl;
	}

}
int main()
{
	test01();
	test02();
	return 0;
}
*/

/*P188 vector中嵌套容器
//容器嵌套容器
void test01()
{
	vector<vector<int>> v;
	//创建小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	for (int i=0;i<4;i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	for (vector<vector<int>>::iterator it = v.begin();it != v.end();it++)
	{
		for (vector<int>::iterator it2 = (*it).begin();it2 != (*it).end();it2++)
		{
			cout << *it2 ;
		}
		cout << endl;
	}
}
int main()
{
	test01();
	return 0;
}
*/

/*P189 string容器-构造函数
string和char*区别
char*是一个指针
string是一个类，类内部封装了char*，管理这个字符串，是一个char*型的容器

构造函数原型：
string();//创建一个空的字符串 例如string str;
string(const char*s);//使用字符串S初始化
string(const string& str)//使用一个string对象初始化另一个string对象
string(int n,char c);//使用n个字符c初始化
//string的构造函数
void test01()
{
	string s1;//默认构造

	const char* str = "hello world";
	string s2(str);
	cout << "s2=" << s2<<endl;

	string s3(s2);
	cout << "s3=" << s3 << endl;

	string s4(10,'a');
	cout << "s4=" << s4 << endl;
}
int main()
{
	test01();
	return 0;
}
*/

/*P190 string容器-赋值操作
string& operator=(const char*s);//char*类型字符串 赋值给当前字符串
string& operator=(const string&s);//把字符串s赋值给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串
string& assign(const char*s);//把字符串s赋值给当前的字符串
string& assign(const char *s,int n);//把字符串的前n个字符赋给当前的字符串
string& assign(const string &s);//把字符串s赋给当前字符串
string& assign(int n,char c);//用n个字符c赋给当前字符串

//string的赋值操作
void test01()
{
	string str1;
	str1 = "hello world";
	cout << "str1=" << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2=" << str2 << endl;

	string str3;
	str3 = 'a';
	cout << "str3=" << str3 << endl;

	string str4;
	str4.assign("hello c++");
	cout << "str4=" << str4 << endl;

	string str5;
	str5.assign("hello c++", 5);
	cout << "str5 = " << str5 << endl;

	string str6;
	str6.assign(str5);
	cout << "str6=" << str6 << endl;

	string str7;
	str7.assign(10, 'w');	cout << "str7 = " << str7 << endl;
}
int main()
{
	test01();
	return 0;
}
*/

/*  P191 string容器-字符串拼接
string& operator+=(const char*str);//重载+=操作符
string& operator+=(const char c);//重载=+操作符
string& operator+=(const string& str);//重载=+操作符
string& append(const char*s);//把字符串s连接到当前字符串结尾
string& append(const char*s,int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=(const string&str)
string& append(const string &s,int pos,int n);//字符串s中从pos开始的n个字符连接到字符串结尾
//string的拼接操作
void test01()
{
	string str1="我";
	str1 += "爱玩游戏";
	cout << "str1=" << str1 << endl;
	str1 += ':';
	cout << "str1=" << str1 << endl;
	string str2="LOL DNF";
	str1 += str2;
	cout << "str1=" << str1 << endl;

	string str3="I";
	str3.append("  love  ");
	cout << "str3=" << str3 << endl;
	str3.append("game abcde", 4);
	cout << "str3=" << str3 << endl;
	str3.append(str2,0,3);
	cout << "str3=" << str3 << endl;
	str3.append(str2, 4, 3);
	cout << "str3=" << str3 << endl;
}
int main()
{
	test01();
	return 0;
}
*/

/*p192 string查找和替换
int find(const string&str,int pos=0)const;//查找str第一次出现位置，从pos开始查找
int find(const char *s,int pos=0)const;//查找s第一次出现位置，从pos开始查找
int find(const char *s,int pos,int n)const;//从pos位置查找s的前n个字符第一次位置
int find(const char c,int pos=0)const;//查找字符c第一次出现的位置
int rfind(const string&str,int pos=npos)const;//查找str最后一次位置，从pos开始查找
int rfind(const char* s,int pos=npos)const;//查找s最后一次位置，从pos开始查找
int rfind(const char* s,int pos,int n)const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c,int pos=0)const;//查找字符c最后一次出现位置
string& replace(int pos,int n,const string& str);//替换从pos开始n个字符为字符串str
string& replace(int pos,int n,const char*s);//替换从pos开始的n个字符为字符串s

//字符串的查找和替换
//1.查找
void test01()
{
	string str1 = "abcdefgde";
	int pos=str1.find("de");
	cout << "pos=" << pos << endl;

	if (pos = -1)
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "找到字符串 pos=" <<pos<< endl;
	}

	//rfind
	int pos2=str1.rfind("de");
	cout << "pos=" << pos2 << endl;
	//rfind和find区别
	//rfind从右往左找 find从左往右找
}
//2.替换
void test02()
{
	string str1 = "abcdefg";
	str1.replace(1,3,"1111");//从1号位置起 3个字符替换成1111
	cout << "str1=" << str1 << endl;
}
int main()
{
	test01();
	test02();
	return 0;
}
*/

/*P193 string字符串比较
比较方式：字符串比较是按字符的ASCII码进行比较
= 返回0
> 返回1
< 返回-1
函数原型：
int compare(const string &s)const;//与字符串s比较
int compare(const char *s)const;//与字符串s比较

//字符串比较
void test01()
{
	string str1 = "hello";
	string str2 = "hello";
	if (str1.compare(str2)==0)
	{
		cout << "str1等于str2" << endl;
	}
	else if(str1.compare(str2)>0)
	{
		cout << "str1大于str2" << endl;
	}
	else
	{
		cout << "str1小于str2" << endl;
	}
}
int main()
{
	test01();
	return 0;
}
*/

/*P194 string字符存取
strng中单个字符存取方式有两种
char& operator[](int n)//通过[]方式取字符
char& at(int n);//通过at方法获取字符
//string字符存取
void test01()
{
	string str = "hello";
	cout << "str = " <<str<< endl;
	//1.通过[]访问单个字符
	for (int i = 0;i < str.size();i++)
	{
		cout << str[i] << "  ";
	}
	cout << endl;
	//2.通过at方式访问单个字符
	for (int i = 0;i < str.size();i++)
	{
		cout << str.at(i) << "  ";
	}
	cout << endl;

	str[0] = 'x';
	cout << "str = " << str << endl;
	str.at(1) = 'x';
	cout << "str = " << str << endl;
}
int main()
{
	test01();
	return 0;
}
*/

/*P195 string插入和删除
函数原型：
string& insert(int pos,const char*s);//插入字符串
string& insert(int pos,const string& str);//插入字符串
string& insert(int pos,int n,char c);//在指定位置插入n个字符c
string& erase(int pos,int n=pos);//删除从Pos开始的n个字符
//string字符存取
void test01()
{
	string str = "hello";
	str.insert(1,"111");//插入
	cout << "str = " << str << endl;
	str.erase(1,3);	//删除
	cout << "str = " << str << endl;
}
int main()
{
	test01();
	return 0;
}
*/

/*P196 string容器-字串获取
函数原型：
string substr(int pos=0;int n=npos)const;//返回由pos开始的n个字符组成的字符串
//string求字串
void test01()
{
	string str = "abcdef";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;
}
//实用操作
void test02()
{
	string email = "zhangsan@sina.com";
	//从邮件地址中 获取用户名信息
	int pos = email.find("@");
	cout << pos << endl;
	string usrName = email.substr(0, pos);
	cout << usrName << endl;
}
int main()
{
	test01();
	test02();
	return 0;
}
*/

/*P197 vector容器-构造函数
vector数据结构和数组非常相似，也称为单端数组
vector与普通数组区别：
不同之处子啊与数据是静态空间，而vector可以动态扩展
动态扩展：并不是在原空间之后续接新空间，而是找到更大的内存空间，然后将原数据拷贝到新空间，释放原空间

vector构造函数
vector<T> v; //采用模板实现类 实现，默认构造函数
vector(v.begin(),v,end())//将v[begin(),end()]区间中的元素拷贝给本身
vector(n,elem);//构造函数将n个elem拷贝给本身
vector(const vector &vec);//拷贝构造函数

void printVector(vector<int> &v)
{
	for (vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout << (*it) << endl;
	}
}
//vector容器构造
void test01()
{
	vector<int> v1;//默认构造 无参构造
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2(v1.begin(), v1.end());//通过区间方式进行构造
	printVector(v2);

	vector<int> v3(10, 100);//n个elem方式构造
	printVector(v3);

	vector<int>v4(v3);//拷贝构造
	printVector(v4);
}
int main()
{
	test01();
	return 0;
}
*/

/*P198  vector容器-赋值操作
函数原型：
vector& operator=(const vector &vec);//重载等号操作符
assign(beg,end);//将[beg,end]区间中的数据拷贝赋值给本身
assign(n,elelm);//将n个elem拷贝赋值给本身
void printVector(vector<int> &v)
{
	for (vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout << (*it) << endl;
	}
}
//vector赋值
void test01()
{
	vector<int> v1;//默认构造 无参构造
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2(10, 100);//赋值 operator=
	v2 = v1;
	printVector(v2);

	vector<int>v3;//assign
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	vector<int> v4;//n个elem方式赋值
	v4.assign(10, 100);
	printVector(v4);
}
int main()
{
	test01();
	return 0;
}
*/

/*P199  vector容量和大小
函数原型：
empty();//判断容器是否为空
capacity();//容器的容量
size();//返回容器中元素的个数
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置
				//如果容器变短 泽末尾超出容器长度的元素被删除
resize(int num,elem);//重新指定容器的长度为num,若容器变长，则以elem值填充新位置
					  //如果容器变短，则末尾超出容器长度的元素被删除
void printVector(vector<int> &v)
{
	for (vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout << (*it) << "  ";
	}
}
//vector容器的容量和大小操作
void test01()
{
	vector<int> v1;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())//为真，代表容器为空
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1为空" << endl;
		cout << "v1的容量为：" << v1.capacity() << endl;
		cout << "v1的大小为：" << v1.size() << endl;
	}
	v1.resize(15,100);//重新指定大小为15  变长部分用100填充
	printVector(v1);//如果重新指定的比原来长了，默认用0填充新的位置


	v1.resize(5);
	printVector(v1);//如果重新指定的比原来短了 超出部分会删掉
}
int main()
{
	test01();
	return 0;
}
*/

/*P200 vector 插入和删除
函数原型：
push_back(ele);//尾部插入元素ele
pop_back();//删除最后一个元素
insert(const_iterator pos,ele);//迭代器指向位置pos插入元素ele
insert(const_iterator pos,int count,ele);//迭代器指向位置pos插入count个元素ele
erase(const_iterator pos);//删除迭代器指向的元素
erase(const_iterator start,const_iterator end)//删除迭代器从start到end之间的元素
clear();//删除容器中所有元素

void printVector(vector<int> &v)
{
	for (vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout << (*it) << "  ";
	}
	cout << endl;
}
//vector插入和删除
void test01()
{
	vector<int> v1;
	v1.push_back(10);//尾插
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	printVector(v1);//遍历

	v1.pop_back();//尾删
	printVector(v1);

	v1.insert(v1.begin(), 100);//插入
	printVector(v1);

	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);


	//删除
	v1.erase(v1.begin());
	printVector(v1);

	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);
}
int main()
{
	test01();
	return 0;
}
*/

/*P201 vector数据存取
函数原型：
at(int idx);//返回索引idx所指的数据
operator[];//返回索引ids所指的数据
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素
//vector容器 数据存取
void test01()
{
	vector<int> v1;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	//利用[]访问数组中的元素
	for (int i = 0;i < v1.size();i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	for (int i = 0;i < v1.size();i++)
	{
		cout << v1.at(i)<<" ";
	}
	cout << endl;

	//获取第一个元素
	cout << "第一个元素为：" << v1.front() << endl;
	//获取最后一个元素
	cout << "最后一个元素为：" << v1.back() << endl;

}
int main()
{
	test01();
	return 0;
}
*/

/*P202 vector互换容器
函数原型：
swap(vec);//将vec与本身的元素互换


void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << (*it) << "  ";
	}
	cout << endl;
}
//vector容器互换
//1.基本使用
void test01()
{
	vector<int> v1;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	cout << "交换前" << endl;
	printVector(v1);

	vector<int> v2;
	for (int i = 10;i > 0;i--)
	{
		v2.push_back(i);
	}
	printVector(v2);
	cout << "交换后" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);

}
//2.实际用途
//巧用swap可以收缩内存空间
void test02()
{
	vector<int> v;
	for (int i = 0;i < 10000;i++)
	{
		v.push_back(i);
	}
	cout << "v的容量为：" << v.capacity()<<endl;
	cout << "v的大小为：" << v.size()<<endl;
	v.resize(3);//重新指定大小
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
	vector<int>(v).swap(v);//内存收缩 按照v大小初始化一个匿名对象 vector<int>(v)  然后和v做交换 之后那个变大的匿名对象被系统自动回收
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

}
int main()
{
	test01();
	test02();
	return 0;
}
*/

/*P203 vector容器-预留空间
函数原型：
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << (*it) << "  ";
	}
	cout << endl;
}
//vector容器 预留空间
void test01()
{
	vector<int> v;

	v.reserve(100000);//利用reserve预留空间

	int num = 0;//统计开辟次数
	int* p = NULL;
	for (int i = 0;i < 100000;i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "num=" << num << endl;

}
int main()
{
	test01();
	return 0;
}
*/

/*P204 deque(双端队列)容器-构造函数
功能：双端数组 可以对头端进行插入和删除操作

deque与vector区别：
vector对于头部的插入删除效率低，数据量越大，效率越低
deque相对而言 对头部的插入删除速度比vector快
vector访问元素时的速度会比deque快，这和两者内部实现有关

构造函数原型：
deque<T> deqT;//默认构造形式
deque(beg,end);//构造函数将[beg,end)区间中的元素拷贝给本身
deque(n,elem);//构造函数将n个elem拷贝给本身
deque(const deque &deq);//拷贝构造函数


void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it =d.begin();it != d.end();it++)
	{
		cout << (*it) << "  ";
	}
	cout << endl;
}
//vector deque
void test01()
{
	deque<int> d1;
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2(d1.begin(),d1.end());
	printDeque(d2);

	deque<int>d3(10, 100);
	printDeque(d3);

	deque<int>d4(d3);
	printDeque(d4);

}
int main()
{
	test01();
	return 0;
}
*/

/*P205 deque容器-赋值操作
函数原型：
deque& operator=(const deque &deq);//重载等号操作符
assign(beg,end);//将[beg,end)区间中的数据拷贝赋值给本身
assign(n,elem);//将n个elem拷贝赋值给本身


void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it =d.begin();it != d.end();it++)
	{
		cout << (*it) << "  ";
	}
	cout << endl;
}
//deque容器赋值操作
void test01()
{
	deque<int> d1;
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2;
	d2 = d1;//operator=赋值操作
	printDeque(d2);

	deque<int>d3;
	d3.assign(d1.begin(),d1.end());//assign赋值操作
	printDeque(d3);

	deque<int>d4;
	d4.assign(10, 100);
	printDeque(d4);

}
int main()
{
	test01();
	return 0;
}
*/

/*P206 deque容器大小操作
函数原型：
deque.empty();//判断容器是否为空
deque.size();//返回容器中元素个数
deque.resize(num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
				  //如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num,elem);//重新指定容器的长度为num，若容器边长，则以elem值填充新位置
					   //如果容器变短，则末尾超出容器长度的元素被删除

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it =d.begin();it != d.end();it++)
	{
		cout << (*it) << "  ";
	}
	cout << endl;
}
//deque容器大小操作
void test01()
{
	deque<int> d1;
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty())
	{
		cout << "d1为空" << endl;
	}
	else
	{
		cout << "d1不为空" << endl;
		cout << "d1的大小为：" << d1.size() << endl;//deque没有capacity
	}

	//重新指定大小
	d1.resize(15);
	printDeque(d1);

	d1.resize(20, 800);
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
}
int main()
{
	test01();
	return 0;
}
*/

/*P207 deque容器-插入和删除
函数原型：
两端插入操作：
push_back(elem);//在容器尾部添加一个数据
push_front(elem);//在容器头部插入一个数据
pop_back();//删除容器最后一个数据
pop_front();//删除容器第一个数据
指定位置操作：
insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值
clear();//清空容器所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置
erase(pos);//删除pos位置的数据，返回下一个数据的位置


void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it =d.begin();it != d.end();it++)
	{
		cout << (*it) << "  ";
	}
	cout << endl;
}
//deque容器插入和删除
//两端操作
void test01()
{
	deque<int> d1;

	//尾插
	d1.push_back(10);
	d1.push_back(20);
	//头插
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	//尾删
	d1.pop_back();
	printDeque(d1);

	//头删
	d1.pop_front();
	printDeque(d1);
}
void test02()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	//insert插入
	d1.insert(d1.begin(),1000);
	printDeque(d1);

	d1.insert(d1.begin(),2, 99999);
	printDeque(d1);

	//按照区间进行插入
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d1.insert(d1.begin(), d2.begin(), d2.end());//在d1前插入d2的元素
	printDeque(d1);
}
void test03()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	//删除
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printDeque(d1);

	//按区间方式删除
	d1.erase(d1.begin(), d1.end());
	//清空
	d1.clear();
	printDeque(d1);
}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}
*/

/*P208 deque容器-数据存取
函数原型:
at(int idx);//返回所以索引所指的数据
operator[];//返回索引idx所致的数据
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素


//deque容器数据存取
void test01()
{
	deque<int> d;

	//尾插
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	//通过[]方式访问元素
	for (int i = 0;i < d.size();i++)
	{
		cout << d[i]<< "  ";
	}
	cout << endl;
	for (int i = 0;i < d.size();i++)
	{
		cout << d.at(i)<< "  ";
	}
	cout << endl;
	cout << "第一个元素为：" << d.front() << endl;
	cout << "最后一个元素为：" << d.back() << endl;

}
int main()
{
	test01();
	return 0;
}
*/

/*P209 deque容器-排序操作
算法：
sort(iterator beg,iterator end);//对beg和end区间元素进行排序

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it =d.begin();it != d.end();it++)
	{
		cout << (*it) << "  ";
	}
	cout << endl;
}
//deque容器排序
void test01()
{
	deque<int> d;

	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	printDeque(d);

	//排序 默认规则是从小到大 升序
	//对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
	//vector容器也可以利用 sort进行排序
	sort(d.begin(), d.end());
	printDeque(d);

}
int main()
{
	test01();
	return 0;
}
*/

/*P210 STL案例1-评委打分
5名选手：选手ABCDE 10个评委打分，去除最高分，去除评委中最低分， 取平均分
实现步骤：
1.创建五名选手 放到vector中
2.遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
3.sort算法对deque容器中分数排序，去除最高和最低分
3.获取平均分


class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;//姓名
	int m_Score;//平均分
};
void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i=0;i<5;i++)
	{
		string name = "选手";
		name += nameSeed[i];
		int score = 0;
		Person p(name,score);
		v.push_back(p);
	}
}
void setScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		deque<int>d;
		for (int i = 0;i < 10;i++)
		{
			int score = rand() % 41+ 60;//60~100
			d.push_back(score);
		}

		cout << "选手：" << it->m_Name << "打分：" << endl;
		for (deque<int>::const_iterator it = d.begin();it != d.end();it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
		//排序
		sort(d.begin(), d.end());
		//去除最高和最低分
		d.pop_back();
		d.pop_front();
		//取平均分
		int sum = 0;
		for (deque<int>::const_iterator it = d.begin();it != d.end();it++)
		{
			sum += (*it);
		}
		int avg = sum / d.size();
		//将平均分 赋值给选手上
		it->m_Score = avg;
	}
}
void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "姓名：" << it->m_Name << "平均分：" << it->m_Score << endl;
	}
}
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//1.创建5名选手
	vector<Person>v;//存放选手的容器
	createPerson(v);
	//测试
	for (vector<Person>::iterator it=v.begin();it !=v.end();it++)
	{
		cout << "姓名：" << (*it).m_Name << "分数：" << (*it).m_Score << endl;
	}
	setScore(v);
	showScore(v);
	return 0;
}
*/

/*p212 stack容器-常用接口
构造函数：
stack<T> stk;//stack采用模板类实现，stack对象的默认构造形式
stack(const stack &stk);//拷贝构造函数
赋值操作：
stack& operator=(const stack &stk);//重载等号操作符
数据存取：
push(elem);//向栈顶添加元素
pop();//从栈顶移除第一个元素
top();//返回栈顶元素
大小操作：
empty();//判断栈顶是否为空
size();//返回栈的大小

//栈stack容器
void test01()
{
	stack<int> s;
	//入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	//栈不为空 产看栈顶 并且执行出栈操作
	while (!s.empty())
	{
		//查看栈顶元素
		cout << "栈顶元素为：" << s.top() << endl;
		//出栈
		s.pop();
	}
	cout << "栈的大小：" << s.size() << endl;
}
int main()
{
	test01();
	return 0;
}
*/

/*P213 queue容器-常用接口
构造函数：
queue<T> que; //queue采用模板类实现，queue对象的默认构造形式
queue(const queue &que);//拷贝构造函数
赋值操作：
queue& operator=(const queue &que);//重载等号操作符
数据存取：
push(elem);//往队尾添加元素
pop();//从队头移除第一个元素
back();//返回最后一个元素
front();//返回第一个元素
大小操作：
empty();//判断堆栈是否为空
size();//返回栈的大小
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;//姓名
	int m_Age;//平均分
};
//栈queue容器
void test01()
{
	//
	queue <Person> q;
	Person p1("tang", 30);
	Person p2("sun", 1000);
	Person p3("zhu", 900);
	Person p4("sha", 800);
	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	cout << "队列大小：" << q.size() << endl;
	//判读队列不为空 查看队头 查看队尾 出队
	while (!q.empty())
	{
		//查看队头
		cout << "队头元素---姓名：" << q.front().m_Name << "年龄：" << q.front().m_Age << endl;
		//查看队尾
		cout << "队尾元素---姓名：" << q.back().m_Name << "年龄：" << q.back().m_Age << endl;
		//出队
		q.pop();
	}
	cout << "队列大小：" << q.size() << endl;
}
int main()
{

	test01();
	return 0;
}
*/

/*P216 list容器-构造函数
STL中List和vecotr是两个最常被使用的容器，各有优缺点
函数原型：
list<T> lst;//list采用模板类实现，对象的默认构造形式
list(beg,end);//构造函数将[beg,end)区间中的元素拷贝给本身
list(n,elem);//构造函数将n个elem拷贝给本身
list(const list &lst);//拷贝构造函数

void printList(const list<int> &l)
{
	for (list<int>::const_iterator it = l.begin();it != l.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//list容器构造函数
void test01()
{
	//创建list容器
	list<int> L1;
	//添加数据
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	//区间方式构造
	list<int>L2(L1.begin(), L1.end());
	printList(L2);

	//拷贝构造
	list<int> L3(L2);
	printList(L3);

	list<int>L4(10, 1000);
	printList(L4);
}
int main()
{
	test01();
	return 0;
}
*/

/*P217 list容器-赋值和交换
函数原型：
assign(beg,end);//将[beg,end)区间中的数据拷贝赋值给本身
assign(n,elem);//将n个elem拷贝赋值给本身
list& operator=(const list&lst);//重载等号操作符
swap(lst);//将lst与本身的元素互换

void printList(const list<int> &l)
{
	for (list<int>::const_iterator it = l.begin();it != l.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//list容器构造函数
void test01()
{
	//创建list容器
	list<int> L1;
	//添加数据
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	list<int>L2 = L1;//operator赋值
	printList(L2);

	list<int>L3;
	L3.assign(L2.begin(), L2.end());
	printList(L3);

	list<int>L4;
	L4.assign(10, 100);
	printList(L4);
}
void test02()
{
	//创建list容器
	list<int> L1;
	//添加数据
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int> L2;
	L2.assign(10, 100);

	cout << "交换前：" << endl;
	printList(L1);
	printList(L2);
	L2.swap(L1);
	cout << "交换后" << endl;
	printList(L1);
	printList(L2);
}
int main()
{
	test01();
	test02();
	return 0;
}
*/

/*P218 list中容器-大小操作
函数原型：
empty();//判断容器是否为空
size();//返回容器中元素个数
resize(num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
				  //如果容器变短，则末尾超出容器长度的元素被删除。
resize(num,elem);//重新指定容器的长度为num，若容器边长，则以elem值填充新位置
					   //如果容器变短，则末尾超出容器长度的元素被删除
*/

/*P219 list容器-插入和删除
函数原型：
push_back(elem);//在容器尾部添加一个数据
pop_back();//删除容器最后一个数据
push_front(elem);//在容器头部插入一个数据
pop_front();//删除容器第一个数据
指定位置操作：
insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值
clear();//清空容器所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置
erase(pos);//删除pos位置的数据，返回下一个数据的位置
remove(elem);//删除容器中所有与elem值匹配的元素
*/

/*P220 list数据存取 不支持索引和[]
函数原型:
front();//返回第一个元素
back();//返回最后一个元素
*/

/*P221 list反转和排序
函数原型:
reverse();//反转链表
sort();//链表排序
//所有不支持随机访问迭代器的容器，不可以用标准算法
//不支持随机访问迭代器的容器，内部会提供对应一些算法
//sort(L.begin(),L.end())  错误
L.sort(); 正确  默认升序
L.sort(myCompare);//降序
bool myComPare(int v1,int v2)
{
	return v1>v2;
}
*/

/*P222 list容器-案例
//高级排序  按照年龄排序 如果年龄相同就按照身高排序
写一个person类
bool comparePerson(Person &p1,Person &p2)
{
	//按照年龄 升序
	if(p1.m_Age==p2.m_Age)
	{
		//年龄相同 按照升高降序
		return p1.m_Height > p2.m_Height
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
}
*/

/*P223 set/multiset容器
所有元素都会在插入时自动被排序
set/multiset属于关联式容器，底层结构使用二叉树实现
set和multiset区别：
set不允许容器中有重复的元素
multiset允许容器中有重复的元素

set构造和赋值
构造:
set<T> st;//默认构造函数；
set(const set &st);//拷贝构造函数

赋值:
set& oprator=(cosnt set &st);//重载等号操作符

set插入用insert 不用push_back
*/

/*P224 set大小和交换
函数原型：
size();//返回容器中元素的数目
empty();//判断容器是否为空
swap(st);//交换两个集合容器
*/

/*P225 set插入和删除
函数原型：
insert();//在容器中插入元素
clear();//清除所有元素
erase(pos);//删除pos所指元素 返回下一个元素的迭代器
erase(beg,end);//删除区间[beg,end)的所有元素，返回下一个元素的迭代器
erase(elem);//删除容器中值为elem的元素
*/

/*P226 set查找和统计
函数原型：
find(key);//查找key是否存在， 若存在 返回该键的元素的迭代器；若不存在 返回set.end();
count(key);//统计key的元素个数
*/

/*P227 set容器和multiset区别
set不可以插入重复数据multiset可以
set插入数据的同时会返回插入结果 表示插入是否成功
multiset不会检测数据，因此可以插入重复数据
//set 容器和multiser容器的区别
void test01()
{
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second) {
		cout << "第一次插入成功" << endl;
	}
	else {
		cout << "第一次插入失败" << endl;
	}
	ret = s.insert(10);
	if (ret.second) {
		cout << "第二次插入成功" << endl;
	}
	else {
		cout << "第二次插入失败" << endl;
	}

	multiset<int> ms;
	//允许插入重复值
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}
int main()
{
	test01();
	return 0;
}
*/

/*P228 pair对组创建
成对出现的数据， 利用对组可以返回两个数据
创建方式：
pair<type,type> p (value1, value2);
pair<type,type> p = make_pair(value1, value2);

//set 容器和multiser容器的区别
void test01()
{
	//第一种方式
	pair<string, int> p("Tom", 20);
	cout << "姓名:" << p.first << "年龄:" << p.second << endl;
	//第二种方式
	pair<string, int>p2 = make_pair("jerry", 30);
	cout << "姓名:" << p2.first << "年龄:" << p2.second << endl;
}
int main()
{
	test01();
	return 0;
}
*/

/*P229 set容器排序
set容器默认排序规则为从小到大
利用仿函数 可以改变排序规则

class MyCompare {
public:
	bool operator()(int v1, int v2) const {
		return v1 > v2;
	}
};
//set 容器排序
void test01() {
	set<int> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(50);
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//指定排序规则从大大小
	set<int, MyCompare> s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(50);
	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

}
int main() {
	test01();
	return 0;
}
*/

/* P230 set容器-自定义数据类型指定排序规则

class Person {
public:
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
class comparePerson {
public:
	bool operator()(const Person& p1, const Person& p2) const {
	//按照年龄 降序
		return p1.m_Age > p2.m_Age;
	}

};
//set 容器排序
void test01() {
	set<Person, comparePerson> s;
	Person p1("liu", 24);
	Person p2("guan", 28);
	Person p3("zhang", 25);
	Person p4("zhao", 21);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl;
	}
}
int main() {
	test01();
	return 0;
}
*/

/* P231 map容器-构造和赋值
map中的所有元素都是pair
pair中第一个元素为key(键值) 起到索引作用 第二个元素为value(实值)
所有元素都会根据元素的键值自动排序
本质：
map/maltimap属于关联式容器，底层结构是用二叉树实现
优点：可以根据key值快速找到value值
map和multimap的区别：
map不允许容器中有重复的key值元素
multimap允许容器中有重复key值元素
构造：
map<T1, T2> mp;// map默认构造函数
map(const map &map);//拷贝构造函数
赋值：
map& operator=(const map &map);//重载等号操作符
*/

/*P232 map 大小和交换
size();//返回容器中元素的数目
empty();//判断容器是否为空
swap(st);//交换两个集合容器
*/

/*P233 map插入和删除
insert(elem);//在容器中插入元素
clear();//清除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器
erase(beg,end);//删除区间[beg,end)的所有元素 返回下一个元素的迭代器
erase(key);//删除容器中值为key的元素


m.insert(pair<int,int>(1,10));
m.insert(make_pair(1,10));
m.insert(map<int, int>::value_type(3,30));
m[4] = 40;//不建议插入 可以用key访问到value
*/

/*P234 map查找和统计
find(key);///查找key是否存在，若存在， 返回该键的元素的迭代器，若不存在 返回set.end();
count(key);//统计key的元素个数 返回整型
*/

/*P235 map容器排序
map容器默认排序规则为按照key值 从小到大排序
利用仿函数 改变排序规则
对于自定义类型 map必须指定排序规则吗， 同set容器
*/

/*P236 STL案例员工分组
 */

/*P237 STL-函数对象
重载函数调用操作符的类，其对象常称为函数对象
函数对象使用重载的()时 行为类似函数调用，也叫仿函数
本质：
函数对象(仿函数)是一个类，不是一个函数

函数对象使用
特点：
函数对象在使用时，可以像普通函数那样调用， 可以有参数 可以有返回值
函数对象超出普通函数的概念 函数对象可以有自己的状态
函数对象可以作为参数传递


class MyAdd {
public:
	int operator() (int v1, int v2) {
		return v1 + v2;
	}

};
//函数对象
void test01() {
	MyAdd myAdd;
	cout << myAdd(10, 10) << endl;
}

class MyPrint {
public:
	MyPrint() {
		this->count = 0;
	}
	void operator() (string test) {
		cout << test << endl;
		count++;
	}
	int count;//内部自己状态
};
void test02() {
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << myPrint.count << endl;
}
void doPrint(MyPrint& mp, string test) {
	mp(test);
}
//函数对象可以作为参数传递
void test03() {
	MyPrint myPrint;
	doPrint(myPrint, "Hello c++");
}
int main() {
	test01();
	test02();
	return 0;
}
*/

/*P238 谓词-一元谓词
返回bool类型的仿函数称为谓词
如果operator()接收一个参数， 叫做一元谓词
如果operator()接收二个参数， 叫做二元谓词
*/

/*P240 内建函数对象
STL内建了一些函数对象
分类：
算术仿函数
关系仿函数
逻辑仿函数
用法：
这些仿函数所产生的对象，用法和一般函数完全相同
使用内建函数对象，需要引入头文件 #include<functional>

算术仿函数：
其中negate是一元运算 其他都是二元运算
反函数原型：
template<class T> T plus<T> //加法仿函数
template<class T> T minus<T> //减法仿函数
template<class T> T multiplies<T> //乘法仿函数
template<class T> T divides<T> //除法仿函数
template<class T> T modulus<T> //取模仿函数
template<class T> T negate<T> //取反仿函数


//内建函数对象 算术仿函数
//nagate一元仿函数 取反仿函数

//plus 二元仿函数 加法
void test01() {
	negate<int> n;
	cout << n(50) << endl;
}
void test02() {
	plus<int> p;
	cout << p(10, 20) << endl;
}
int main() {
	test01();
	test02();
	return 0;
}
*/

/*P241 关系仿函数

实现关系对比
仿函数原型：
template<class T> bool equal_to<T> //等于
template<class T> bool not_equal_to<T> //不等于
template<class T> bool greater<T> //大于
template<class T> bool greater_equal<T> //大于等于
template<class T> bool less<T> //小于
template<class T> bool less_equal<T> //小于等于



//内建函数对象 _关系仿函数
//大于 greater
void test01() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

int main() {
	test01();
	return 0;
}
*/

/*P242 内建函数对象-逻辑仿函数  //基本用不到
实现逻辑运算
函数原型：
template<class T> bool logical_and<T> //逻辑与
template<class T> bool logical_or<T> //逻辑或
template<class T> bool logical_not<T> //逻辑非


//内建函数对象 _逻辑仿函数
//逻辑 logical_not
void test01() {
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
	//利用逻辑非 将容器v搬运到 容器v2中，并执行取反操作
	vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}
int main() {
	test01();
	return 0;
}
*/

/*P243 常用遍历算法- for_each
头文件主要由头文件<algorithm> <functional> <numeric>组成
<algorithm>时所有STL头文件中最大的一个 范围涉及到 比较，交换，产找，遍历操作，复制，修改等等
<numeric>体积很小 只包括几个再序列上面进行简单数学运算的模板函数
<functional>定义了一些模板类 用以声明函数对象

常用遍历算法
for_each  //遍历容器   ，实际开发中 最常用的遍历算法 必须熟练掌握
transform //搬运容器到另一个容器中

函数原型：
transform(iterator beg1, iterator end1, iterator beg2, _func);
beg1 源容器开始迭代器
end1源容器结束迭代器
beg2目标容器开始迭代器
_func函数或者函数对象


void print01(int val) {
	cout << val << " ";
}
class print02 {
public:
	void operator() (int val) {
		cout << val << " ";
	}
};
void test01() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print01);//普通函数 把函数名放进来
	cout << endl;
	for_each(v.begin(), v.end(), print02());// 仿函数 把匿名对象放进来
}
int main() {
	test01();
	return 0;
}



class TransForm {
public:
	int operator () (int v) {
		return v;
	}
};
class MyPrint {
public:
	void operator () (int val) {
		cout << val << " ";
	}
};
void test01() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int> vTarget;//目标容器
	vTarget.resize(10);
	transform(v.begin(), v.end(), vTarget.begin(), TransForm());
	for_each(vTarget.begin(), vTarget.end(), MyPrint());
	cout << endl;
}
int main() {
	test01();
	return 0;
}
*/

/* P245 常用查找算法
算法简介：
find    //查找元素
find_if  // 按条件查找元素
adjacent_find // 查找相邻重复元素
binary_search // 二分查找法
count //统计元素个数
count_if // 按条件统计元素个数
*/

/*  find 查找指定元素 找到返回指定元素的迭代器，找不到返回结束迭代器end()
函数原型：
find(iterator beg, iterator end, value);
按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//beg开始迭代器
//end结束迭代器
//value 查找的元素
*/

/*P246 find_if
按条件查找元素
函数原型：
find_if(iterator beg, iterator end, _Pred);
//按值查找元素 找到返回指定位置迭代器，找不到返回结束迭代器位置
//beg 开始迭代器
//end 结束迭代器
//_Pred 函数或者谓词（返回bool类型的仿函数）
*/

/* P247 adjacent_find
查找相邻重复元素
adjacent_find(iterator beg,iterator end);
//查找相邻重复元素，返回相邻元素的第一个位置的迭代器
//beg开始迭代器
//end结束迭代器
*/

/*P248 binary_search
查找指定元素是否存在
bool binary_search(iterator beg,iterator end, value);
//查找指定的元素，查到返回true 否则false
//注意：在无序序列中不可用，无序序列结果未知
//beg 开始迭代器
//end 结束迭代器
//value 查找的元素
*/

/*P249 功能描述
统计元素个数
count(iterator beg, iterator end, value);
//统计元素出现次数
//beg开始迭代器
//end结束迭代器
//value 统计的元素
自定义类型数据 要重载==
*/

/*P250 count_if
按条件统计元素个数
函数原型：
count_if(iterator beg, iterator end, _Pred);
//按条件统计元素出现次数
//beg开始迭代器
//end 结束迭代器
//_Pred谓词
*/

/* 常用排序算法
sort   //对容器内元素进行排序
random_shuffle //洗牌 指定范围内的元素随机调整次序
merge //容器元素合并，并存储到另一容器中
reverse  //反转指定范围元素
*/

/*P251 sort
sort(iterator beg, iterator end, _Pred);
//beg 开始迭代器
//end 结束迭代器
//_Pred 谓词
*/

/*P252 random_shuffle
洗牌 指定范围内的元素随机调整次序
random_shuffle(iterator beg, iterator end);
//指定范围内的元素随机调整次序
//beg 开始迭代器
//end 结束迭代器

使用时记得加随机种子
*/

/*P253 merge
两个容器元素合并，并存储到另一容器中
//注意：两个容器必须是有序的
//beg1 容器1开始迭代器
//end1 容器1结束迭代器
//beg2 容器2开始迭代器
//end2 容器2结束迭代器
//dest 目标容器开始迭代器
*/

/*P254 reverse
将容器内元素进行反转
reverse(iterator beg, iterator end);
//反转指定范围的元素
//beg开始迭代器
//end结束迭代器
*/

/*常用拷贝算法和替换算法
copy //容器内指定范围的元素拷贝到另一容器中
replace //将容器内指定范围的旧元素改为新元素
replace_if//容器内指定范围满足条件的元素替换为新元素
swap //互换两个容器的元素
*/

/*P255 copy   用的很少
容器内指定范围的元素拷贝到另一容器中
copy(iterator beg, iterator end, iterator dest);
//beg 开始迭代器
//end 结束迭代器
//dest 目标起始迭代器
*/

/*P256 replace
replace(iterator beg, iterator end,oldvalue, newvalue)
//将区间内旧元素替换成新元素
//beg 开始迭代器
//end 结束迭代器
//oldvalue 旧元素
//newvalue 新元素
*/

/*P257 replace_if
将区间内满足条件的元素 替换成指定元素
函数原型：
replace_if(iterator beg, iterator end, _pred,newvalue);
//按条件替换元素 满足条件的替换成指定元素
//beg 开始迭代器
//end 结束迭代器
//_pred 谓词
//newvalue 替换的新元素
replace_if 按条件查找 可以利用仿函数 灵活筛选满足的条件
*/

/*P258 swap 互换两个容器的元素
swap(container c1, container c2);
//互换两个容器的元素
//c1 容器1
//c2 容器2
同种类型容器 才可以互换
*/

/*常用算术生成算法
算术生成算法属于小型算法， 使用时包含的头文件为#include<numeric>
accumulate//计算容器元素累计综合
fill//像容器中添加元素
*/

/*P259 accumulate
计算区间内 容器元素累计总和
函数原型：
accumulate(iterator beg, iterator end, value);
//计算容器元素累计总和
//beg开始迭代器
//end结束迭代器
//value 起始值
*/

/*P260 fill
向容器 指定区间 填充指定元素
fill(iteratro geb, iterator end, value);
//beg开始迭代器
//end结束迭代器
//value 填充的值
*/

/*常用的集合算法

set_itersection //求两个容器的交集
set_union //求两个容器的并集
set_difference //求两个容器的差集
*/

/*P261 set_intersection
 求两个容器的交集
 set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//注意：两个集合必须是有序序列 目标容器开辟空间需要从两个容器中取小值
//beg1 容器1开始迭代器
//end1 容器1结束迭代器
//beg2 容器2 开始迭代器
//end2 容器2结束迭代器
//dest 目标容器开始迭代器
*/

/*P262 set_union
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
//求两个集合的并集
//两个集合必须是有序序列   目标容器开辟空间需要从两个容器求和
//beg1 容器1开始迭代器
//end1 容器1结束迭代器
//beg2 容器2 开始迭代器
//end2 容器2结束迭代器
//dest 目标容器开始迭代器
*/

/*P263 set_difference
求两个集合的差集
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//求两个集合的差集
//两个集合必须是有序序列   目标容器开辟空间需要两个容器中的最大值
//beg1 容器1开始迭代器
//end1 容器1结束迭代器
//beg2 容器2 开始迭代器
//end2 容器2结束迭代器
//dest 目标容器开始迭代器

v1 ：0 1 2 3 4 5 6 7 8 9
v2：5 6 7 8 9 ·10 11 12 13 14
v1和v2差集 01234
v2和v1差集  10 11 12 13 14

set_differenc 返回值是差集中最后一个元素的位置
*/