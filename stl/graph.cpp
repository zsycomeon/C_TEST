#include<iostream>
#include<fstream>
#include<string>
#include "linkedstack.h"
#include "linkedlist.h"
using namespace std;
template<class T>
class test
{
	public:
		int imtest;
};
//临接链表的实现类
template<class vType>
class linkedListGraph : public linkedlistType<vType>,public test<vType>
{
	public :
		void getAsjacentVertices(vType adjacencyList[] , int & length);
		void destroyList();
		void print();
		void insertFirst(const vType& newItem);
	
};
//为了模板函数的二次查找，需要重新引用一下
//重新destroy
template<class vType>
void linkedListGraph<vType>::destroyList()
{
	linkedlistType<vType>::destroyList();
}
//重新print
template<class vType>
void linkedListGraph<vType>::print()
{
	linkedlistType<vType>::print();
}
//重新print
template<class vType>
void linkedListGraph<vType>::insertFirst(const vType& newItem)
{
	linkedlistType<vType>::insertFirst(newItem);
}
//遍历中用到
template<class vType>
void linkedListGraph<vType>::getAsjacentVertices(vType adjacencyList[] , int & length)
{
	//int test;
	//test = this->imtest;
	nodetype<vType> * current;
	length = 0;
	//模板类继承中，有两段寻找编译,不用this无法找到
	current = this->first;
	while(current != NULL)
	{
		adjacencyList[length++] = current->info;
		current = current->link;
	}
	
}
//图的实现类
template<class vType, int size>
class graphType
{
	public : 
		bool isEmpty();
		void createGraph();
		void clearGraph();
		int test();
		void printGraph() const;
		graphType();
		~graphType();
	protected : 
		int maxsize;
		int gsize;
		//可以是列表 可以是单个指针
		linkedListGraph<vType> * graph;
};
template<class vType,int size>
bool graphType<vType, size>::isEmpty()
{
	return (gsize == 0);
}
template<class vType,int size>
void graphType<vType,size>::createGraph()
{
	//int temp;
	//ifstream infile;
	//char fileName[50];
	vType vertex;
	vType adjacentVertex;
	cout<<"input the verNum"<<" ";
	cin>>gsize;
	cout<<"gsize is "<<gsize<<" "<<endl;
	//for中是一次声明多个参数
	for(int index = 0,i = 0;index < gsize; ++index,++i)
	{
		vertex = i;
		graph[vertex] = * (new linkedListGraph<vType>);
		for(int temp = 1; temp<3 ; ++temp)
		{
			graph[vertex].insertFirst(i+temp);
		}
		
		
		
	}
	return;
	
	
	
}
template<class vType,int size>
void graphType<vType,size>::clearGraph()
{
	int index;
	for(index = 0;index<gsize; ++index)
	{
		graph[index].destroyList();
		
	}
	gsize = 0;
}
template<class vType,int size>
void graphType<vType,size>::printGraph() const
{
	int index;
	for(index = 0; index<gsize; ++index)
	{
		cout<<"index is"<<index<<endl;;
		graph[index].print();
		
		
	}
}
/*
*
*图的默认构造函数
*
*/
template<class vType,int size>
graphType<vType,size>::graphType()
{
	maxsize = size;
	gsize = 0;
	graph = new linkedListGraph<vType>[maxsize];
}
template<class vType,int size>
graphType<vType,size>::~graphType()
{
	clearGraph();
	delete[] graph;
}
template<class vType,int size>
int graphType<vType,size>::test()
{
	int temp;
	cout<<"input the verNum"<<" ";
	cout<<"gsize is "<<1<<" ";
	cout<<endl;
	return 0;
}
int main(int argv,char** argc[])
{
	graphType<int,5> g1;
	g1.createGraph();
	//g1.test();
	g1.printGraph();
	return 0;
}
