#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include "refe.h"
using namespace std;
int fib_m(int a)
{
	if(a == 0 || a == 1)
	{
		return 1;
	}
	else
	{
		int temp;
		temp = fib_m(a-1) + fib_m(a-2);
		return temp;
	}	
}
void fib()
{
	//1,1,2,3,5
	//int * a = new int[];
	cout<<"fib is coming"<<endl;
	vector<int> vc1;
	vector<int>::iterator j = vc1.begin();
	
	for(int i = 0;i<12; ++i,++j)
	{
		vc1.push_back(fib_m(i));
	}
	
	vector<int>::iterator jj = vc1.begin();
	for(int i = 0;jj!=vc1.end();++jj,++i)
	{
		cout<<i<<"is"<<*jj<<" ";
	}
}
void shuixian()
{
	for(int i = 100; i<999; ++i)
	{
		int b = i/100;
		int s = (i/10)%(10);
		int g = i%10;
		if(pow(b,3) + pow(s,3) + pow(g,3) == i)
		{
			cout<<"the"<<i<<"one"<<endl;
		}
	}
}
class ct
{
	public :
		ct(){};
		ct(int a){this->a = a;};
		int a;
};
int main(int argc, char ** argv[])
{
	/*
	fib
	fib();
	int res = fib_m(5);
	cout<<"res is"<<res<<endl;
	*/
	shuixian();
	ct c;
	c = 2;
	cout<<"begin refe"<<endl;
	refe(2);
	return 0;
}
