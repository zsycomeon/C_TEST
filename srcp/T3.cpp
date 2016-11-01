#include<iostream>
using namespace std;
/*
class Array
{
public:
    Array(): length(0)
    {
        num = NULL;
    };
private:
    const int length;
    int * num;
};
*/

class Test
{
	public :
	//没有返回值
	//函数的区别是目，同目的函数不能在同一个空间内重定义 
	//初始化const只能用表的方法
		Test();
		Test(int k);
	
		int a;
		int b;
		void copy(Test &a);
		const int z;
	private :
		int ll;
		int x;
		int y;
		
};
Test::Test():z(123123){}
void Test::copy(Test &a)
{
	if(this == &a)
	{
		cout<<"same"<<endl;
	}
	else
	{
		cout<<"different"<<endl;
	}	
}
//所有构造函数都需要初始化一下const
//声明了构造函数无论哪种形式的 就不会再自动生成默认的构造函数了
//类中显式地声明了默认构造函数，无论其属性被设置为public、private还是protected，系统都不会再自动生成默认构造函数了。
//类中显式地声明了其它任意一个不是默认构造函数的构造函数，系统均不会再自动生成默认构造函数。


//拷贝构造函数 不显式的声明会自动产生默认的,拷贝的指针
/*
Test(Test &a)
{
	x = a.x;
	y = a.y;
}
*/
Test::Test(int k):z(),x(56),y(78){a=2;b=54;}


class Array
{
	public :
	//显示定义拷贝构造函数后要定义
	//声明拷贝函数后也要声明默认构造函数
		Array(){};
		Array(Array & a);
		void getArr(int * a, int n);
		int * a;
		void show();
		//参数解释 Array类的一个实例的地址，就是对象内存的首地址
		void copy(Array &a);
		//析构函数 无参 无返 ~类名 不能私有
		~Array();
	private :
		int * arr;
		int length;
		
};
//&a是指针,a是对象本身
Array::Array(Array & a)
{
	int i = 0;
	if(a.arr != NULL)
	{
		arr = new int[a.length];
		for(; i<a.length;i++)
		{
			arr[i] = a.arr[i];
		}
		length = a.length;
	}
	else
	{
		arr = 0;
		length = 0;
	}	
}
void Array::getArr(int * a,int n)
{
	arr = new int[n];
	length = n;
	int i = 0;
	for(; i<n; i++)
	{
		arr[i] = a[i];
	}	
}
void Array::show()
{
	cout<<arr<<endl;
}
void Array::copy(Array &a)
{
	//this是常量 this->调用说明他是new的 ，指向的是对象的地址 &a=>地址 a=>对象本身
	if(this == &a)
	{
		cout<<"two same objects"<<endl;
	}
	else
	{
		cout<<"two different objects"<<endl;
	}
	//return;
}
//根据栈的原理 后实例化的先执行析构函数
Array::~Array()
{
	if(arr != NULL)
	{
		delete[] arr;
	}
	cout<<&arr<<endl;
	cout<<"destructor run"<<endl;
}
//测试new 和delete
class utest
{
	public :
		utest(){this->a = 1;};
		~utest();
	private :
		int a;
}; 
utest::~utest()
{
	cout<<a<<"utest is over"<<endl;
}
//const 常量不可改变 只能列表定义 常成员函数可以调用任何成员变量但是不能改变任何成员变量
class price
{
	public :
	
		price(int a):arg(2){this->priceA = a;};
		//常成员函数
		int getPrice() const;
		void tt(){};
		//静态变量初始默认值为零 
		static int nur;
	private :
		int priceA;
		const int arg;
};
//在代码块外为静态变量赋值的时候需要带着变量的类型 在类外定义的时候不受到private的限制 
int price::nur = 123;
//声明的时候和定义的时候都需要带着const
int price::getPrice() const
{
	//改变成员属性 编译报错
	//this->priceA = 123;
	return this->priceA;
}
int main()
{
	//返回的是实例对象的内容
	Test t1;
	cout<<t1.z<<endl;
	//new实例化返回的是指针
	Test * t2 = new Test();
	//cout<<t2->z<<endl;
	//cout<<&t1<<endl;
	//cout<<t2<<endl;
	
	Array arr1;
	int a1[5] = {1,2,3,4,5};
	arr1.getArr(a1,5);
	//arr1(arr2);
	//声明一个arr2 拷贝的是arr1
	Array arr2(arr1);
	//自定义的拷贝构造函数，重新开辟空间，所以地址不相同，不同于默认的拷贝构造函数
	arr1.show();
	arr2.show();
	
	arr1.copy(arr1);
	arr1.copy(arr2);
	//即使是默认的拷贝构造函数出来的对象和原来对象的地址不相同
	Test t3;
	Test t4(t3);
	t3.copy(t4);
	cout<<&t3<<endl;
	int * a;
	int yy = 2;
	a = &yy;
	
	//* 指针 =》值 & 值 =>指针
	cout<<* a<<endl;
	//测试new 和delete new返回的是地址 new调用构造函数 delete调用析构函数
	utest * test1 = new utest();
	//三个实例化的对象的=组成的数组 如同 new int[3]
	utest * test2 = new utest[3];
	utest * test3 = (utest *)malloc(sizeof(utest));
	delete test1;
	delete[] test2;
	free(test3);
	
	price pa(3);
	int p = pa.getPrice();
	cout<<p<<"money"<<endl;
	const price pb(4);
	//调用常成员函数ok
	int p2 = pb.getPrice();
	//调用非常 编译报错
	//pb.tt();
	cout<<p2<<"money"<<endl;
	/*
	int a1[3] = {1,2,3};
	arr1.a = a1;
	arr1(arr2);
	arr1.show();
	arr2.show();
	*/
}
