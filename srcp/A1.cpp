#include <iostream>
//如果如下这样引用了输入输出的话 重载的话会报错，因为没有全部using std作用域下的所有类和方法，os，oi就缺失了定义
//expected constructor, destructor, or type conversion before '&' token
//using std::cout;
//using std::endl;
//所以需要引入整个std命名空间
using namespace std;
//重载的方法是，这个类的运算符号
class complex
{
	public :
		complex();
		complex(double a);
		complex(double a,double b);
		//&A 是指针， A是存储complex数据的常量
		//const函数 不能改变对象变量
		//重载操作符的关键字operator
		//准对某些类的奥左幅重构，使用该类型数据时可以有特殊的作用
		complex operator+(const complex & A) const;
		complex operator-(const complex & A) const;
		complex operator*(const complex & A) const;
		complex operator/(const complex & A) const;
		friend istream & operator>>(istream& is,const complex& A);
		friend ostream & operator<<(ostream& os,const complex& A);
		//展示
		void show();
	private : 
		double real;
		double img;
		
};
complex::complex()
{
	this->real = 0.0;
	this->img = 0.0;
}
complex::complex(double a)
{
	this->real = a;
	this->img = 0.0;
}
complex::complex(double a,double b)
{
	this->real = a;
	this->img = b;
}
complex complex::operator+(const complex & A) const
{
	complex B;
	B.real = this->real + A.real;
	B.img = this->img + A.img;
	return B;
}
//这里的参数可否不是常量
//而且外部对private变量进行了赋值 是否可行
complex complex::operator-(const complex & A) const
{
	complex B;
	B.real = this->real - A.real;
	B.img = this->img - A.img;
	return B;
}
complex complex::operator*(const complex & A) const
{
    complex B;
    B.real = this->real * A.real - this->img * A.img;
    B.img = this->img * A.real + this->real * A.img;
    return B;
}
//重载除法操作符
complex complex::operator/(const complex & A) const
{
    complex B;
    double square = A.real * A.real + A.img * A.img;
    B.real = (this->real * A.real + this->img * A.img)/square;
    B.img = (this->img * A.real - this->real * A.img)/square;
    return B;
}
void complex::show()
{
	cout<<"real:"<<this->real<<",img:"<<this->img<<endl;
}
//重载输入操作符
istream & operator>>(istream& is,const complex& A)
{
    is >> A.real >> A.img;
    return is;
}
//重载输出操作符
//os是引用，返回的也应该是引用，否则报错
ostream & operator<<(ostream& os,const complex& A)
{
    os << A.real <<" + "<< A.img <<" i ";;
    return os;
}
//测试简单重载
class simple
{
	public :
		simple();
		simple(int a);
		simple operator+(const simple &A) const;
		simple operator-(const simple &A) const;
		//声明一个顶层的操作符重载函数为友元函数
		//const成员函数，顶层函数无法设置const friend simple operator*(const simple & A,const simple & B) const;
		friend simple operator*(const simple & A,const simple & B);
		//friend istream & operator>>(istream & in, complex & A);
		//friend ostream & operator<<(ostream & out, complex & A);
		void show();
	private : 
		int num;
};
simple::simple()
{
	this->num = 0;
}
simple::simple(int a)
{
	this->num = a;
}
simple simple::operator+(const simple &A) const
{
	simple B;
	B.num = this->num + A.num;
	return B;
}
simple simple::operator-(const simple &A) const
{
	simple B;
	B.num = this->num - A.num;
	return B;
}
//顶层函数重载
//如果不声明友元函数的话，就要在类中定义调用private属性的方法，繁琐，故设友元函数

simple operator*(const simple & A,const simple & B) 
{
	simple C;
	C.num = (A.num * B.num)*2;
	return C;
}
void simple::show()
{
	cout<<"the num is"<<this->num<<endl;
	return;
}


int main()
{
	//位于主函数之后定义的函数，可先声明，类没法先声明
	void after();	
	complex c_a(1.2,2.2);
	complex c_b(2.3,3.3);
	complex c_c = c_a + c_b;
	complex c_d = c_a - c_b;
	complex c_e = c_a * c_b;
	complex c_f = c_a / c_b;
	c_c.show();
	c_d.show();
	c_e.show();
	c_f.show();
	c_c.show();
	after();
	simple s1(1);
	simple s2(3);
	simple s3 = s1 + s2;
	simple s4 = s1 - s2;
	s3.show();
	s4.show();
	cout<<"------"<<endl;
	simple ss1(2);
	simple ss2(3);
	//正常的二元操作符
	simple ss3 = ss1 * ss2;
	//直接调用顶层函数的方法
	simple ss4 = operator*(ss1,ss2);
	ss3.show();
	cout<<"-----"<<endl;
	ss4.show();
	cout<<"-------------"<<endl;
	cout<<"when vir is complex"<<c_c<<endl;
	cout<<"-------------"<<endl;
	int ak = 123;
	//相当于扩展了cout
	cout<<"when vir is inter"<<ak<<endl;
	complex yc;
	cin>>yc;
	return 0;
}
void after()
{
	cout<<"after the main"<<endl;
	return;
}
