#include <iostream>
using namespace std;

class Array
{
public:
    Array() : length(0)
    {
        // 报错length = 0; //compile error不能在函数体内部初始化 const 变量：
        num = NULL;
    };
	Array(int * a) : num(a) , length(5){}
	void say()
	{
		cout<<"mum is"<<num<<"length is"<<length;
	}
private:
    const int length;
    int * num;
};


class Counter
{

public:
         // 类Counter的构造函数
         // 特点：以类名作为函数名，无返回类型
         Counter(char * a,int b)
         {
                //m_value = "aaaaaaa";
				//init(a , b);
				m_value = a;
				 k_value = "kkkkkk";
				y = b;
         }
		 //以重构的构造函数
		 Counter()
		 {
			 k_value = "kkkkkk";
		 }
         
public :
		void init(char * a, int b);
         // 数据成员
         char * m_value;
		 char * k_value;
		 int y;
};

class book
{
		//protected和private都无法再类外调用
	public:
		int testa;
	public :
		void setTitle(char * a);
		char * getTitle();
		void setPrice(double a);
		double getPrice();
		void getPri1();
		void show(){
			cout<<"yes ->"<<endl;
		}
		int pri2;
	private:
		char * title;
		int pri1;
		double price;
		void test()
		{
			pri1 = 123;
		};
//类后加分号否则编译报错	
};
//字符数组单写出来的不就是&a[0]数组第一个字符的指针吗
void book::setTitle(char * a/*第一个字符的指针*/)
{
	title = a;
}
char * book::getTitle()
{
	return title;
}
void display(book & b)
{
	cout<<"The title is"<<b.getTitle()<<endl;
}
//返回的是book的实例的引用
book & init(char * t)
{
	//不加static warning: reference to local variable `b' returned
	//static应该是全局的静态变量
	static book b;
	b.setTitle(t);
	return b;
}
void book::getPri1()
{
	
	test();
	pri2 = pri1;
	cout<<"is"<<pri2<<endl;
}

void book::setPrice(double a)
{
	//默认是类内的属性的值的操作
	price = a;
}
double book::getPrice()
{
	return price;
}
int main(void)
{
	/*
	int x,y;
	int a,b;
	cout<<"please input an int number:"<<endl;
	cin>>x;
	cout<<"please input an int number:"<<endl;
	cin>>y;
	cout<<"first:"<<x<<" second:"<<y<<endl;
	cout<<"please input two int numbers"<<endl;
	cin>>a>>b;
	cout<<"third:"<<a<<" forth:"<<b<<endl;
	*/
	book Alice;
	Alice.setPrice(19.22);
	double p = Alice.getPrice();
	cout<<"the price is "<<p<<endl;
	//Alice.test();
	Alice.getPri1();
	book * Rock = new book;
	Rock->show();
	//两种实例化两种调用方式
	Rock->testa = 123;
	Alice.testa = 222;
	int kk = 123;
	//正常的指针
	int * akk = &kk;
	//引用,相当于是 bb是kk变量的一个别名，如果用引用代替函数的形参的话可以减少内存开支
	int &bb = kk;
	cout<<"address:"<<akk<<endl;
	cout<<"ref:"<<bb<<endl;
	Alice.setTitle("I am trying that");
	display(Alice);
	book Harry;
	Harry = init("Harry Potter");
	display(Harry);
	
	Counter count("abc",123);
	cout<<count.m_value<<endl;
	cout<<count.k_value<<endl;
	
	int kkk = 123;
	
	Array arr(&kkk);
	
	arr.say();
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
