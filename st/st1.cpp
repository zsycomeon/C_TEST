#include <iostream>
//引入了string内建数据类型
#include <string>
using namespace std;
//string的操作更多的是对内建数据类提供的方法的操作
int main()
{
	string s1;
	string s2 = "string2";
	string s3 = s2;
	//位数，字符取最后一个
	string s4(10 , 'f');
	int len = s4.length();
	cout<<s4<<"len:"<<len<<endl;
	//string 转换成 字符数组
	const char * c_s = s4.c_str();
	char x = c_s[1];
	cout<<"transform is c_s[1]"<<x<<endl;
	//数组操作
	cout<<s2[2]<<x<<endl;
	//清除 从第几位开始(不包括本身) 清除几位 越界报错
	s2.erase(1,1);
	cout<<s2<<endl;
	//插入，增加 从第几位开始 插入字符串
	s2.insert(1,s2);
	cout<<s2<<endl;
	//字符串互换 必须是两个变量
	s2.swap(s1);
	cout<<s2<<endl;
	//截取 不包含
	s2 = s2.substr(1,1);
	
	return 0;
}
