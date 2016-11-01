#include <iostream>
#include <vector>
#include <string>
using namespace std;
//枚举类中定义的都是常量，++数值加一
enum A{a = 1, b = 2 , c = 1,d};
template<class T>
int getArrayLen(const T& array)
{
	//引用的内存的总量 除以 单个数据的内存
	return  (sizeof(array) / sizeof(array[0]));
}
int main()
{
	//声明定义的取长度类
	
	//int getArrayLen<T>(const T& array);
	A a;
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<d<<endl;
	if(typeid(a) == typeid(A))
	{
		cout<<"yes"<<endl;
	}
	//cout<<a::a<<endl;
	char s1[] = "asss";
	//字符数组和 字符串 方法通用
	int s2[] = {1,2,3,3};
	cout<<sizeof(s1)<<endl;
	cout<<sizeof(s2)<<endl;
	cout<<getArrayLen(s2)<<endl;
	//通用strlen
	//多一个 \0结束字符
	cout<<strlen(s1)<<endl;
	for (int i = 0; i<getArrayLen(s1)-1; ++i)
	{
		//cout<<s1[i]<<endl;
	}
	for (int i = 0; i<getArrayLen(s2); ++i)
	{
		//cout<<s2[i]<<endl;
	}
	return 0;
}

