#include<string>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
class Complex
{
	public :
		//转型构造函数 , 如需要用到该类型对象的时候，却调用了另一种类，会自动转化
		Complex(int a){ this->real = a; this->img =0;};
		Complex(int real , int img){ this->real = real ; this->img = img;};
		friend ostream & operator<<(ostream & os , Complex & com);
	private :
		int real;
		int img;
};
//Object类的方法 顶级方法
ostream & operator<<(ostream & os , Complex & com)
{
	os<<"real is "<<com.real<<", img is "<<com.img<<" ";
	return os;
}
//调用转型
void showCom(Complex com)
{
	cout<<com<<endl;
}
int main(int argc , char ** argv[])
{
	cout<<"come"<<endl;
	Complex cp(2 , 1);
	cout<<cp<<endl;
	int i = 2;
	showCom(i);
	return 0;
}
