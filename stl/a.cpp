#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <vector>
//py中的set 只有key的 关联型
#include <set>
#include <map>
//预处理中引入的头文件没找到 报错
//处理效率选用：
//插入频繁-> list
//查询频繁-> vector deque
//序列容器的操作一致，效率不同



///////<int ,string>中声明的数据类型，不可或缺，是声明容器的必要条件
using namespace std;
class vect
{
	public :
		void seri();
};
void vect::seri()
{
	//vector<int> lit;
	list<int> lit;
	//deque<int> lit;
	
	lit.push_back(2);
	
	lit.insert(lit.begin(),-1);
	//指针偏移操作
	//操作的结果是从第一位开始前的位置，向后取位置,+几就是第几位
	//lit.insert(lit.begin()+2,-1);
	//lit.insert(lit.end()-2,4);
	//list插入操作无法直接在begin，end（）操作，需要迭代到相应位置添加
	list<int>::iterator j = lit.begin();//说明容器的位置是一个对象，++ --是经过重载的
	// 报错 lit.begin() + 1;
	int n = 5;
	for(int i = 0; i < n && j!= lit.end(); ++i)
	{
		//重载后的++，改变对象内部的某些变量
		++j;
	}
	  
	lit.insert(j,5,100);
	cout<<"length of the con: "<<lit.size()<<endl;
	//报错 cout<<lit.end()<<endl;
	//自建迭代器
	list<int>::iterator iter;
	for(iter = lit.begin(); iter != lit.end(); iter++)
	{
		//迭代器本身是next对象的指针
		cout<<* iter<<endl;
	}
	
	lit.reverse();
	for(iter=lit.begin(); iter!=lit.end(); iter++)
	{
		cout<<* iter<<endl;
	}
	
}
//关联型key-value 
class kv
{
	public : 
	 void show_info_set();
	 void show_info_map();
};
void kv::show_info_set()
{
	set<string>s;
	string a = "aa";
	s.insert(a);
	//s.push_back(a);
	s.insert(++(s.begin()) , a);
	int n = 1;
	set<string>::iterator j = s.begin();
	for(int i=0; i<n&&j!=s.end();++i)
	{
		//++的效率更高
		++i;
		++j;
	}
	s.insert(j,"kk");
	//定义一个存储string的set容器内的迭代器的对象为i
	set<string>::iterator i = s.begin();
	for(;i!=s.end();++i)
	{
		cout<<* i<<endl;
	}
	i = s.find("a");
	if(i == s.end())
	{
		//s.end()代表容器的尾部，超出容器
		cout<<"5 is not found"<<endl;
	}
}
void kv::show_info_map()
{
	map<string , string> m;
	m["aa1"] = "t1";
	m["aa2"] = "t2";
	m["aa3"] = "t3";
	m["aa4"] = "t4";
	m["aa5"] = "t5";
	m["aa6"] = "t6";
	//实例化一个map类的迭代器
	map<string,string>::iterator j ;
	for(j=m.begin(); j!=m.end(); j++)
	{
		//不同于set j指向一个数组
		cout<<j->first<<" -- "<<j->second<<endl;
	}
}
enum A {a,v,b};
int main()
{
	//vector list duque序列容器
	vect v_t;
	v_t.seri();
	cout<<"end of seri"<<endl;
	kv k_v;
	k_v.show_info_set();
	k_v.show_info_map();
	cout<<"end of key-value"<<endl;
	return 0;
}
