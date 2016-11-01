#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<stack>
//容器算法 演算法 算法
#include<algorithm>
#include<string>
using namespace std;
//自定义枚举错误类型那个
enum index { nume = 1,stringe = 90};
class stac
{
	public :
		void st_t();
		void show_err();
};
//跑出错误
void stac::show_err()
{
	if(1 != 2)
	{
		throw "number wrong";
	}
}
void stac::st_t()
{
	stack<int> s;
	int a;
	//当输入一个类型不符合的，跳出
	while(cin>>a)
	{
		s.push(a);
	}
	/*
	适配器没有迭代器
	stack<int>::iterator j;
	for(j=s.begin(); j!=s.end(); ++j)
	{
		cout<< * j<<endl;
	}
	*/
	
	while(!s.empty())
	{
		//压栈操作，先进后出
		a = s.top();
		s.pop();
		cout<<a<<endl;
	}
	
}
void display(int i)
{
	cout<<i<<endl;
}
bool odd(int i)
{
	return i%2 !=0;
}
bool compare(const int & a,const int & b)
{
	return a>b;
}
int main()
{
	//定义在全局的枚举类中的每一个数据就是常量了
	cout<<nume<<endl;
	cout<<stringe<<endl;
	stac st;
	//st.st_t();
	vector<int> vec(10);
	
	vector<int>::iterator j = vec.begin();
	/*
	for (int i = 0 ; j!=vec.end(); ++j,++i)
	{
		* j = i;
		cout<<* j<<endl;
	}*/
	cout<<"random is:"<<endl;
	//随机数填充vector容器
	generate(vec.begin(),vec.end(),rand);
	for (int i = 0 ; j!=vec.end(); ++j,++i)
	{
		//* j = i;
		cout<<(* j)+1<<endl;
	}
	//replace_if 遍历所有value 第三个参数返回true 变为0或者其他
	replace_if(vec.begin(),vec.end(),odd,0);
	//sort 按照外部的规则函数 a》b 从大到小排列
	sort( vec.begin(), vec.end(), compare );
	try
	{
		int a;
		string b;
		cin>>a;
		cin>>b;
		if(a != 2)
		{
			throw nume;
		}
		else if(b != "kk")
		{
			throw stringe;
		}
	}
	//nume 是常量对象,index e也是常量对象
	catch(index e)
	{
		if(e == nume)
		{
			//枚举类的只可定义 输出1 
			cout<<e<<endl;
			cerr<<"err of number"<<endl;
		}
		else if(e == stringe)
		{
			cout<<e<<endl;
			cerr<<"err of string"<<endl;
		}
		
	}
	return 0;
}
