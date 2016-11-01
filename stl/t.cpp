#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<date>
using namespace std;
template<class T>
int getArrLen(const T& arr)
{
	int len = sizeof(arr)/sizeof(arr[0]);
	return len;
}


int main(int argc,char * agrv[])
{
	set<int> set1;
	set1.insert(set1.begin(),1);
	set1.insert(set1.end(),2);
	set1.insert(3);
	//set关联容器，自动去重，但是插入只有三种写法，其余默认向最后插入
	set1.insert(set1.begin()++,888);
	set<int>::iterator si = set1.begin();
	//set选定位置插入，暂时行不通
	for (si = set1.begin(); si!=set1.end();++si)
	{
		cout<<*si<<endl;
	}
	//list
	list<int> lit1(2,10);
	lit1.push_back(11);
	int n = 0;
	list<int>::iterator lj = lit1.begin();
	//begin是第一个元素之前的指针
	for(int i = 0; lj!=lit1.end(); ++i,++lj)
	{
		if(i == n)
		{
			lit1.insert(lj,888);
		}
	}
	for (lj = lit1.begin();lj!=lit1.end();++lj)
	{
		cout<<* lj<<endl;
	}
	return 0;
}
