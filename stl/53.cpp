#include<string>
#include<iostream>
#include<fstream>
#include<algorithm>
//list和dequeue 双端顺序队列 有前驱和直接后继
#include<deque>
#include<list>
//vector单向队列 只有后驱
#include<vector>
//迭代器
#include<iterator>
//关联容器
#include<set>
//容器适配器
#include<stack>
#include<queue>
using namespace std;
//set自定义
struct strLess
{
	bool operator()(const char * s1,const char * s2)
	{
		//s1大于s2返回正数
		return strcmp(s1 , s2)  < 0;
	}
};
struct strLessb
{
	bool operator()( char * s1, char * s2)
	{
		//s1大于s2返回正数
		//返回true 则通过
		return strcmp(s1 , s2)  > 0;
	}
};
int main()
{
	//向量vector
	vector<int> vec1(10);
	vector<int> vec2(10 , 1);
	//insert迭代器位置
	vec2.insert(vec2.begin()++,2);
	vector<int>::iterator vecit= vec2.begin();
	vec2.front();
	vec2.back();
	vec2[1];
	vec2.at(1);
	//向量单向，操作尾部的效率高
	vec2.push_back(4);
	vec2.pop_back();
	cout<<"----------vector here-------- \n"<<" ";
	int k = 0;
	for(vector<int>::iterator vecit1= vec2.begin();vecit1 != vec2.end(); ++vecit1,++k)
	{
		if(k == 5)
		{
			vec2.insert(vecit1 , 55);
		}
		//cout<<* vecit2<<endl;
	}
	for(vector<int>::iterator vecit2= vec2.begin();vecit2 != vec2.end(); ++vecit2)
	{
		cout<<* vecit2<<endl;
	}
	cout<<"----------vector end-------- \n"<<" ";
	cout<<endl;
	//deque
	deque<int> dq1(10,2);
	deque<int> dq2(10);
	//assign会覆盖初始赋值
	dq1.assign(3,5);
	dq1.push_back(12);
	dq1.push_front(12);
	dq1.pop_front();
	dq1.pop_back();
	for(deque<int>::iterator deit = dq1.begin() ; deit != dq1.end() ; ++deit)
	{
		cout<< * deit <<endl;
	}
	//流迭代器
	//ostream_iterator(output&) // 输出迭代器将数据输出到输出流中
	//将cout对象绑到输出流中
	ostream_iterator<int> screen(cout , " ");
	cout<<"begin"<<endl;
	copy(dq1.begin() , dq1.end() , screen);
	cout<<endl;
	copy(dq1.begin() , dq1.end() , back_inserter(dq2));
	
	//关联容器set multiset map multimap
	/*
	*封装的是查找二叉树所以，无从某位置插入这个操作，有的是从哪里开始
	*/
	//封装的二叉树，无法直接初始化,insert或者拷贝，或者赋值
	set<int> s1;
	//创建空的set对象，元素类型char*，比较函数对象(即排序准则)为自定义strLess
	set<const char*, strLess> s2( strLess);
	//利用set对象s1,拷贝生成set对象s2
	set<int> s3(s1);
	//用迭代区间[&first, &last)所指的元素，创建一个set对象
	int iArray[] = {13, 32, 19};
	set<int> s4(iArray, iArray + 3);
	//用迭代区间[&first, &last)所指的元素，及比较函数对象strLess，创建一个set对象
	const char* szArray[] = {"hello", "dog", "bird" };
	set<const char*, strLess> s5(szArray, szArray + 3 );
	
	set<const char*>::iterator setit = s5.begin();
	//strlessb中大的在前面
	set<char* , strLessb> s6;
	for(int i = 0 ; setit != s5.end(); ++i ,++setit) 
	{
		if(i==1)
		{
			s5.insert(setit,"aaaa");
		}
		//cout<<* setit<<endl;
	}
	for( set<const char*>::iterator setita = s5.begin();setita != s5.end();++setita) 
	{
		
		//cout<<* setita<<endl;
	}
	s6.insert("csd");
	s6.insert("sdf");
	s6.insert("gdfsd");
	s6.insert("kud");
	s6.insert("ngsd");
	for( set<char* , strLessb>::iterator setitb = s6.begin();setitb != s6.end();++setitb) 
	{
		
		cout<<* setitb<<endl;
	}
	return 0;
}
