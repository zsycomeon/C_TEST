#include<iostream>
using namespace std;
class price
{
	public :
		static int a;
		static void aa();
		int b;
		void bb();
		~price();
};
void aa()
{
	//static  成员函数不能调用非静态成员变量
	//b=2;
	//重定义每次调用方法每次加1
	int b = 2;
	price::a = 2;
}
price::~price()
{
	cout<<"done"<<endl;
}
int price::a = 123;
//静态的调用尽量用解析符调用

//友元函数 友元类 (A B两个类 B中声明 frind A意味着A可以调用B的私有成员)
//如同C一样,调用后定义的类或者方法，应该先声明它，否则编译时报错
class B;
class A
{
	public :
		A(){};
		void show(B &b);
		
};
class B
{
	public :
		int a;
		B();
		//直接声明友元类 :A类是本类的朋友可以调用本类的私有成员了
		//friend void A::show(B &b);
		//直接声明友元类 需要加上class-key关键字
		friend class A;
	private :
		int Ba;
		int Bb;
};
B::B()
{
	this->Ba = 11;
	this->Bb = 22;
}
void A::show(B &b)
{
	cout<<b.Ba<<" "<<b.Bb<<endl;
}
int main()
{
	price p1;
	cout<<p1.a<<" "<<price::a<<endl;
	B b;
	A a;
	a.show(b);
	return 0;
}
