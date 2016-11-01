#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<string>
#include<numeric>
#include<math.h>
#include "mystack.h"
#include "linkedstack.h"
#include "listqueue.h"
using namespace std;
void getChain()
{
	struct A
	{
		int id;
		string des;
		//如果不设定默认值，link会被分配一个不可预测的指针值
		A * link;
	};
	string temp;
	A * pa;
	//定义链表第一个节点
	A t_t;
	int i = 0;
	while(cin>>temp)
	{
		if(temp == "end")
		{
			break;
		}
		else
		{
			if(i == 0)
			{

			t_t.id = i;
			t_t.des = temp;
			//当未给link赋值的时候。附上默认值，否则程序始终能找到一个不确定的指针值。运行中崩溃
			t_t.link = 0;
			pa = &t_t;
			}
			else
			{
			//重新开辟空间
			A * a_t = new A;
			a_t->des = temp;
			a_t->id = i;
			a_t->link = 0;
			pa->link = a_t;
			pa = a_t;
			}
			++i;
		}
	}	
	A * out;
	out = &t_t;
	//cout<<out->id<<out->link->id<<out->link->link->id<<endl;
	//out默认值0
	while(out)
	{
		
		cout<<"id:"<<out->id<<"descript:"<<out->des<<endl;
		out = out->link;
		
	}
		
		
	
	return;
}
int main(int argc , char ** argv[])
{
	//数组定义的栈
	Mystack<int> st_a(100);
	Mystack<int> st_b(100);
	st_a.push(1);
	st_b = st_a;
	int temp;
	st_b.pop(temp);
	cout<<temp<<endl;
	//getChain();
	//链表定义的栈
	linkedstack<string> lt_a;
	//linkedstack<string> lt_b;
	
	lt_a.push("aaa");
	lt_a.push("bbb");
	lt_a.push("ccc");
	//泛型的拷贝构造函数，不能分开引用
	linkedstack<string> lt_b(lt_a);
	
	lt_a.showstack();
	lt_a.destroy();
	lt_a.showstack();
	cout<<"now is lt_b"<<endl;
	lt_b.showstack();
	linkedstack<string> lt_c;
	lt_c = lt_b;
	cout<<"now is lt_c"<<endl;
	lt_c.showstack();
	linkedstack<string> lt_d;
	lt_d.push("ff1");
	lt_d.push("ff2");
	lt_d.push("ff3");
	lt_d.push("ff4");
	lt_d.push("ff5");
	lt_d = lt_c;
	cout<<"now is lt_d"<<endl;
	lt_d.showstack();
	cout<<"-------------now the queue is on the platform---------------------"<<endl;
	int a[] = {1,2,3,4,5};
	listqueue<int> lt1(6);
	lt1.initialize();
	lt1.addqueue(11);
	lt1.addqueue(232);
	lt1.addqueue(3);
	lt1.addqueue(44);
	lt1.addqueue(5);
	lt1.addqueue(644);
	lt1.showinfo();
	listqueue<int> lt2(6);
	lt2 = lt1;
	lt2.showinfo();
	int de;
	lt2.deque(de);
	lt2.showinfo();
	cout<<"the delete is"<<de<<endl;
	
	lt1.upturn();
	cout<<"after turning..."<<endl;
	lt1.showinfo();
	return 0;
}
