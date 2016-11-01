#include <iostream>
#include <string>
using namespace std;
//T 实例化之后只能表示一种数据类型
template<class T>
class array
{
	public :
		array(int len);
		T& operator[](int);
		const T& operator[](int) const;
		int getlen()const{ return length;};
		~array();
		//friend ostream& operator<<(ostream& os,const array<T>& t);
		void show_not();
	private :
		array(){};
		int length;
		T * arr;
};
//函数中无论用不用模板参数 都需要声明T
template<class T>
void array<T>::show_not()
{
	int ta;
	cout<<"input the ta"<<endl;
	cin>>ta;
	cout<<"without the ta"<<ta<<endl;
	return;
}
template<class T>
array<T>::array(int len)
{
	this->length = len;
	//T类的数据
	arr = new T[length];
	
	
}
template<class T>
array<T>::~array()
{
	delete[] arr;
}
template<class T>
T& array<T>::operator[](int i)
{
	if(i<0 || i>(length-1))
	{
		cout<<"out bounds"<<endl;
	}
	else 
	{
		return (this->arr)[i];
	}
}
template<class T>
//const成员函数能够 改变const
const T& array<T>::operator[](int i) const
{
	if(i<0 || i>(length-1))
	{
		cout<<"out bounds"<<endl;
	}
	else 
	{
		return (this->arr)[i];
	}
}
template<class T>
//重载array类的输出函数，<T>声明的是类中有T类型数据
ostream& operator<<(ostream& os,const array<T>& t)
{
	for(int i =0;i<t.getlen();i++)
	{
		os<<t[i]<<","<<endl;
	}
	return os;
}
int main()
{
	int t1[3] = {1,2,3};
	array<int> a1(3);
	for(int i=0;i<3;i++)
	{
		a1[i] = t1[i];
	}
	cout<<a1<<endl;
	a1.show_not();
	return 0;
}
