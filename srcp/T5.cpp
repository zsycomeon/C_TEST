#include<iostream>
using std::cout;
using std::endl;
//说明类的继承 只看pub private protected 不看static const 这两个关键字的继承不变 protected继成 基类的pub pro全是pro pub继承不变
//积累中的private不可在派生类中访问
//using可以将改变继承自基类的成员的可见性

//枚举类型
enum weekday {sun,mon,tue,wed,thu,fri,sat};
//声明(enum weekday 是一个类型 写不写enum都行,赋值形式是常量形式，返回值是int)
weekday day = tue;

class A
{
	public :
		A(){this->tk2 = 123;};
		A(int a){e = a;};
		void Aa(){cout<<"Aa"<<endl;};
		void Aa2(){A::sa++;};
		static int sa;
		void set(char * a){tk = a;}
		int tk2;
		int e;
		~A(){cout<<"A is done"<<endl;};
		//多态：继承 同名虚函数 基类指针(没指定虚函数的话 会受到指针的影响)
		void show(){cout<<"A class shit"<<endl;};
	protected :
		
		int b;
	private :
		
		char * tk;
		void Ac(){cout<<"Ac"<<endl;};
		int Ac2(){return 2;};
		int c;
};
int A::sa = 1;
class B : public A
{
	public :
		int d;
		//默认构造函数就是无参构造函数，派生类中可以自动调用基类的默认构造函数，没有默认的不调用，必须先是调用否则报错
		B(){this->tk2 = 333;};
		//也就是说可以在派生类的构造函数中 显式调用基类的
		//调用的基类中的参数如果是派生类的形参 不需要声明了
		B(int a):A(a){this->e = a+1;};
		void Bd(){this->d = this->Bf();};
		void Bd2(){cout<<B::sa<<endl;};
		void set(int x){tk2 = x;}
		int tk2;
		int e;
		~B(){cout<<"B is done"<<endl;};
		//虚函数 多态：继承 同名虚函数 基类指针
		//如此来看多态就是 同一函数 在不同类调用时候的不同结果
		void show(){cout<<"B class shit"<<endl;};
	protected :
		
	private :
		
		int Bf(){return 33;};
		int f;
};
class C
{
	public :
		C(){};
		C(int a);
		//声明多个非默认构造函数,第二个没法用，报错，编译无措
		C(char * x,int b);
		virtual void show(){cout<<"this is C class"<<endl;};
		void show2(){cout<<"this is C2 class"<<endl;};
		virtual void hello(){cout<<"C said hello"<<endl;};
		~C(){cout<<"C destructor"<<endl;};
		int a;
};
//虚继承 不影响本类的继承 影响的是后续的继承
class D: virtual public C
{
	public :
		D():C(22){this->a = 3;};
		//不调用基类中的构造函数报错
		//D(){this->a = 3;};
		void show(){cout<<"this is D class"<<endl;};
		void show2(){cout<<"this is D2 class"<<endl;};
		void hello(){cout<<"D said hello"<<endl;};
		~D(){cout<<"D destructor"<<endl;};
		int a;
};
C::C(int a)
{
	a = 2;
}
int main()
{
	A a;
	B b(2);
	a.Aa2();
	b.Bd2();
	//b.set(2);
	//同名继承后覆盖，可以用类解析调用
	//b.A::set("aaa");
	//同理 派生类的同名成员变量覆盖了基类的，只是覆盖可以通过对象。类：：变量访问
	cout<<b.tk2<<endl;
	cout<<b.A::tk2<<endl;
	cout<<day<<endl;
	cout<<"object b from B "<<b.e<<endl;
	cout<<"A e"<<b.A::e<<endl;
	//C c("abv",123);
	D d;
	//delete 接的参数是指针,new出来的直接返回的就是指针
	//delete &a;
	//delete &b;
	//delete &d;
	//p是指向A类的指针
	A * p;
	//B * p;
	//B类继承了A类
	B b2;
	//给p赋b2的指针
	p = &b2;
	//p指向A 
	p->show();
	//re::C , D
	C * p2;
	D d2;
	p2 = &d2;
	p2->show();
	//virtual 虚拟函数加上之后 实现正多态 即派生类和基类中的同名函数 真正指向本类不受指针影像
	//有虚函数生成虚函数表，指针调用虚函数的话，从虚函数表找出函数入口地址，虚函数地址在对象堆地址的开头处
	//delete p2;
	//virtural测试
	C * t = new C;
    t->hello();
    //delete t;
    t = new D;
    t->hello();
    //delete t;
    D k;
    k.hello();
	//delete &k;
	return 0;
}
