#include <string>
#include <iostream>
#include <math.h>
using namespace std;
template<typename T>
struct Node
{
	T info;
	Node<T> * link;
};
/**
*LinkedStack
*/
template<typename T>
class LinkedStack
{
	public :
		LinkedStack(const  LinkedStack<T> &otherLinkStack);
		LinkedStack<T> & operator=(const LinkedStack<T> &otherLinkStack);
	protected :
		//int maxSize;
		//int num;
		Node<T> * top;
};
template<typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T> &otherLinkStack)
{
	Node<T> * current;
	Node<T> * top;
	Node<T> * cursor;
	Node<T> * newNode;
 	if(otherLinkStack.top != NULL)
	{
		current = otherLinkStack.top;
		top = new Node<T>;
		top->info = current->info;
		top->link = NULL;
		cursor = top;
		current = current->link;
		while( current != NULL )
		{
			newNode = new Node<T>;
			newNode->info = current->info;
			newNode->link =NULL;
			cursor->link = newNode;
			cursor = cursor->link;
			current = current->link;
			
		}	
	}
}
template<typename T>
LinkedStack<T> & LinkedStack<T>::operator=( const LinkedStack<T> &otherLinkStack)
{
	if( this != &otherLinkStack)
	{
		if( top != NULL )
		{
			top == NULL;
		}
		
		if( otherLinkStack.top == NULL)
			top = NULL;
		else
		{
			Node<T> * newNode;
			Node<T> * cursor;
			Node<T> * current = otherLinkStack.top;
			
			top->info = current->info;
			top->link = NULL;
			cursor = top;
			current = current->link;
			if( current != NULL)
			{
				newNode = new Node<T>;
				newNode->info = current->info;
				newNode->link = NULL;
				cursor->link = newNode;
				cursor = cursor->link;
				current = current->linkl;
			}	
		}	
	}
}
/**
* ArrayStack
*/
template<typename T>
class ArrayStack
{
	public :
		ArrayStack(const ArrayStack<T>& otherStack);
		ArrayStack<T> & operator=( const ArrayStack<T> &otherStack);
		void push(T newItem);
		void pop(T & popItem);
	protected :
		int top;		//top就是当前数目
		int maxSize;
		T * data;
};
template<typename T>
void ArrayStack<T>::push(T newItem)
{
	if( top == maxSize )
	{
		cout<<"stack is full"<<endl;
	}
	else
	{
		data[top] = newItem;
		top++;
	}	
}
template<typename T>
void ArrayStack<T>::pop(T & popItem)
{
	if( top == 0 )
	{
		cout<<"empty stack"<<endl;
	}
	else
	{
		popItem = data[top-1];
		top--;
	}	
	
}
template<typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& otherStack)
{
	//拷贝构造函数和赋值的不同点在于，拷贝时构造是构造，对象生成的方法，也就是对象中还没有参数
	top = otherStack.top;
	maxSize = otherStack.maxSize;
	
	int i;
	if( top != 0 )
	{	
		data = new T[maxSize];
		for( i = 0; i<top ; ++i)
		{
			data[i] = otherStack.data[i];
		}
	}
		
}
template<typename T>
ArrayStack<T> & ArrayStack<T>::operator=( const ArrayStack<T> & otherStack)
{
	
	int j = 0;
	if( this != &otherStack) //avoid self asset
	{
		if( maxSize == otherStack.maxSize )
		{
			top = otherStack.top;
			if( top != 0 )
			{
				for ( ; j<top ; ++j)
				{
					data[j] = otherStack[j];
				}
			}
		}	
		else
		{
			cout<<"maxSize should be the same"<<endl;
		}
	}
	return * this;
}










template<typename T>
class LinkedListType
{
	public :
		LinkedListType();
		const LinkedListType<T> & operator= (const LinkedListType<T>& list);
		void initialize();
		bool isEmpty();
		bool isFullList();
		void print();
		int getLength();
		void destroyList();
		void search(const T& searchItem);
		void insertFirst(const T& newItem);
		void deleteNode(T &item);
		LinkedListType(const LinkedListType<T>& otherLst);
		//逆向打印链表
		void reversePrint(Node<T> * current) const;
		void insertOrd(T &newItem);
		void deleteOrd(T &newItem);
	public :
	
		Node<T> * first;
		Node<T> * last;
};
//有序列表删除节点
template<typename T>
void LinkedListType<T>::deleteOrd(T &deleteItem)
{
	Node<T> * current;
	Node<T> * trailCurrent;
	bool isFound = false;
	if( first != NULL)
	{
		current = first;
		while( !isFound && current != NULL)
		{
			if(current->info == deleteItem)
			{
				isFound = true;
			}
			else
			{
				trailCurrent = current;
				current = current->link;
			}	
		}
		if(isFound)
		{
			//不同于插入节点的即使没发现也可以插入，但是删除节点没找到就无法删除
			if(current == first)
			{
				first = first->link;
				delete current;
			}	
			else
			{
				trailCurrent->link = current->link;
				delete current;
			}	
			
		}	
		else
		{
			cout<<"no existing..."<<endl;
		}	
	}
}
//向有序列表中插入节点
template<typename T>
void LinkedListType<T>::insertOrd(T &newItem)
{
	Node<T> * current;
	Node<T> * trailCurrent;
	Node<T> * newNode;
	bool isFound = false;
	newNode = new Node<T>;
	newNode->info = newItem;
	newNode->link = NULL;
	if(first == NULL)
	{
		
		first = last = newNode;
	}
	else
	{
		current = first;
		while( current != NULL && !isFound )
		{
			//如果firstbi他大，自然不需要前驱了
			if( current->info >= newItem )
			{
				isFound = true;
			}	
			else
			{
				trailCurrent = current;
				current = current->link;
			}	
		}
		//确定了current和trailcurrent之后，插入节点
		if( current == first )
		{
			newNode->link = current;
			first = newNode;
		}		
		else
			if( current != NULL )
			{
				newNode->link = current;
				trailCurrent->link = newNode;
			}
			else
			{
				trailCurrent->link = newNode;
			}	
	}	
}
template<typename T>
void LinkedListType<T>::reversePrint(Node<T> * current) const
{
	//从最后的开始打印
	if( current != NULL )
	{
		reversePrint( current->link );
		cout<<current->info<<endl;
	}	
}
template<typename T>
void LinkedListType<T>::insertFirst(const T& newItem)
{
	Node<T> * newNode;
	if(first ==  NULL)
	{
		first = new Node<T>;
		first->info = newItem;
		first->link = NULL;
		last = first;
	}
	else
	{
		newNode = new Node<T>;
		newNode->info = newItem;
		newNode->link = first;
		first = newNode;
	}	
}
template<typename T>
bool LinkedListType<T>::isEmpty()
{
	return (first == NULL);
}
template<typename T>
LinkedListType<T>::LinkedListType()
{
	first = NULL;
	last = NULL;
}
template<typename T>
void LinkedListType<T>::destroyList()
{
	Node<T> * current;
	while( first != NULL )
	{
		current = first;
		//current = current->link;
		first = first->link;
		delete current;
	}
	last = NULL;
}
template<typename T>
void LinkedListType<T>::initialize()
{
	destroyList();
}
template<typename T>
void LinkedListType<T>::print()
{
	Node<T> * current = first;
	while( current != NULL )
	{
		T info = current->info;
		cout<<info<<endl;
		current = current->link;
	}
}
template<typename T>
int LinkedListType<T>::getLength()
{
	int len = 0;
	Node<T> * current = first;
	while( current != NULL )
	{
		len++;
		current = current->link;
	}
	return len;
}
template<typename T>
void LinkedListType<T>::search(const T &item)
{
	bool isFound = false;
	Node<T> * current = first;
	if( first == NULL )
		cout<<"nodeList is empty"<<endl;
	else
	{
		while( current != NULL && !isFound)
		{
			if( current->info == item )
			{
				isFound = true;
				//cout<<"is found"<<endl;
			}
			current = current->link;
		}
		//cout<<"no found"<<endl;
	}
	if( isFound )
		cout<<"is Found"<<endl;
	else
		cout<<"no Found"<<endl;
}
template<typename T>
void LinkedListType<T>::deleteNode(T &item)
{
	Node<T> * current;
	bool isFound = false;
	if ( first == NULL )
	{
		cout<<"nodelst is empty"<<endl;
	}
	else
	{
		if( item == first->info )
		{
			current = first->link;
			first = first->link;
			if( first == NULL )
			{
				last == NULL;
			}
			delete current;
			//delete first;
			//first = current;
		}
		else
		{
			//前驱节点
			Node<T> * trailCurrent = first;
			//found
			bool isFound = false;
			current = first->link;
			while( current != NULL && !isFound )
			{
				if( current->info == item )
				{
					isFound = true;
					//trailCurrent->link = current->link;
					//current->link = NULL;
				}
				else
				{
					trailCurrent = current;
					current = current->link;
				}	
			}
			if( isFound )
			{
				trailCurrent->link = current->link;
				if( last == current)
					last = NULL;
				delete current;
			}	
		}	
	}	
}
template<typename T>
LinkedListType<T>::LinkedListType(const LinkedListType<T>& otherLst)
{
	Node<T> * newNode;
	Node<T> * current;
	if(otherLst.first == NULL)
	{
		first = NULL;
		last = NULL;
	}
	else
	{
		first = new Node<T>;
		current = otherLst.first;
		first->info = current->info;
		first->link = NULL;
		last = first;
		
		current = current->link;
		while( current != NULL )
		{
			//last = new Node<T>;
			newNode = new Node<T>;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			/**
			*last向下移位
			*/
			last = newNode;
			current = current->link;
		}
	
		
	}	
}
template<typename T>
const LinkedListType<T> & LinkedListType<T>::operator=(const LinkedListType<T> &otherLst)
{
	Node<T> * current;
	Node<T> * newNode;
	if( this != &otherLst) // avoid self asset
	{
		//current = otherLst.first;
		if( first != NULL )
		{
			destroyList();
		}	
		if( otherLst.first == NULL )
		{
			first = NULL;
			last = NULL;
		}
		else
		{
			current = otherLst.first;
			first->info = current->info;
			first->link = NULL;
			last = first;
			current = current->link;
			while( current != NULL )
			{
				newNode = new Node<T>;
				newNode->info = current->info;
				newNode->link = NULL;
				last->link = newNode;
				//这里需要说明一下,指针变量重新赋值之后，他就具有了原先指针下的内容了
				last = newNode;
				current = current->link;
			}
		}	
	}	
	return * this;
}

class Recursion
{
	public :
		//递归找到数组中的最大值
		int selectMax(const int a[] , int low , int high);
		//fib
		int fib(int a);
		//BinaryToDecimal
		double binToDec(int bin , double &dec, int weight);
		//DecimalToBinary
		double decToBin(int dec , double &bin , int weight);
		//arrayValueSum
		int getSumArray(const int a[] , int num , int low , int high);
};
int Recursion::selectMax(const int a[] , int low , int high)
{
	int res = 0;
	if( low == high )
	{
		res = a[low];
		//return a[low];	
	}	
	else
	{
		int max = selectMax(a , low + 1 , high);
		if( max > a[low] )
		{
			res = max;
			
		}	
		else
		{
			res = a[low];
		}	
	}
	return res;
}
int Recursion::fib(int a)
{
	int res = 0;
	if( a > 0)
	{
		if( a == 1 || a == 2)
		{
			res = 1;
		}
		else
		{
			res = fib(a-1) + fib(a-2);
		}	
	}
	return res;
}
double Recursion::binToDec(int bin , double &dec , int weight)
{	if(bin >0)
	{
		//bin 
		int residue = bin%10;
		//cout<<"residue:"<<residue<<endl;
		int res = bin/10;
		//cout<<"res:"<<res<<endl;
		dec = dec + residue*pow(2 , weight);
		//cout<<"dec:"<<dec<<endl;
		//这是一个结果实例
		return binToDec(res , dec , weight + 1);
	}
	else
	{
		return dec;
	}	
	
	
}
double Recursion::decToBin(int dec , double &bin , int weight)
{
	if( dec > 0 )
	{
		int res = dec/2;
		int residue = dec%2;
		bin = bin + residue*pow(10 , weight);
		return decToBin(res , bin , weight + 1);
	}
	else
	{
		return bin;
	}	
}
int Recursion::getSumArray(const int a[] , int res , int low , int high)
{
	if(low <= high)
	{
		res = res + a[low];
		return getSumArray(a , res , low+1 , high);
	}
	else
	{
		return res;
	}	
}
int main(int argc , char ** argv[])
{
	int a[] = {1,2,3};
	//Recursion
	Recursion recursion;
	int res1;
	int res2;
	double res3;
	double res4;
	double dec = 0.00;
	double bin = 0.00;
	int res5;
	res1 = recursion.selectMax(a , 0 , 2) ; 
	res2 = recursion.fib(3);
	res3 = recursion.binToDec(101 , dec , 0);
	res4 = recursion.decToBin(57 , bin , 0);
	res5 = recursion.getSumArray(a ,0 ,0 , 2);
	cout<<"now the test line---"<<"   "<<endl;
	cout<<"res1 is"<<res1<<endl;
	cout<<"res2 is"<<res2<<endl;
	cout<<"res3 is"<<res3<<endl;
	cout<<"res4 is"<<res4<<endl;
	cout<<"res5 is"<<res5<<endl;
	//cout<<"dec is"<<dec<<endl;
	cout<<"---linkedTypeLst---"<<endl;
	LinkedListType<int> link;
	//Node<int> node1;
	//node1.info = 111;
	//Node<int> node2;
	//node2.info = 222;
	int ninfo1 = 111;
	int ninfo2 = 222;
	int ordInfo1  = 555;
	int ordInfo2 = 5;
	int deleteItem = 23;
	int deleteItem2 = 5;
	link.insertFirst(ninfo1);
	link.insertFirst(ninfo2);
	link.print();
	link.reversePrint(link.first);
	link.insertOrd(ordInfo1);
	link.insertOrd(ordInfo2);
	link.print();
	link.deleteOrd(deleteItem);
	link.deleteOrd(deleteItem2);
	link.print();
	return 0;
}
