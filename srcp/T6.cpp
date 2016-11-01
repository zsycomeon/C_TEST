#include <iostream>
using std::cout;
using std::endl;
class A
{
	public :
		A(){cout<<"A construct"<<endl;};
		~A(){cout<<"A destruct"<<endl;};
		//虚函数 就是为了多态服务 没声明虚函数 则函数遮蔽
		virtual void show(){cout<<"this is A class"<<endl;};
		//void show(){cout<<"this is A class"<<endl;};
};
class B:public A
{
	public :
		B(){cout<<"B construct"<<endl;};
		~B(){cout<<"B destruct"<<endl;};
		void show(){cout<<"this is B class"<<endl;};
		
		
};
class base
{
public:
    base();
	//将基类的析构函数声明为虚函数后，派生类的虚函数的自动成为虚函数，虚函数不受指针影响，通过虚函数的入口地址调用
    virtual ~base();
private:
    int * a;
};
class derived: public base
{
public:
    derived();
    ~derived();
private:
    int * b;
};
base::base()
{
    cout<<"base constructor!"<<endl;
    a = new int[10];
}
base::~base()
{
    cout<<"base destructor!"<<endl;
    delete[] a;
}
derived::derived()
{
    cout<<"derived constructor!"<<endl;
    b = new int[1000];
}
derived::~derived()
{
    cout<<"derived destructor!"<<endl;
    delete[] b;
}
int main()
{
	A * b;
	b = new B;
	b->show();
	//B b1;
	//delete &b1;
	base* p;
    p = new derived;
    delete p;
	return 0;
}
