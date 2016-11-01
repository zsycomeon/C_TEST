//纯链表ADT
#include<string>
#include<iostream>
using namespace std;
template<class T>
struct nodetype
{
	T info;
	nodetype<T> * link;
};
template<class T>
class linkedlistType
{
	public :
		void initializeList();
		linkedlistType();
		void print();
		void destroyList();
		void insertFirst(const T& newItem);
		void insertLast(const T& newItem);
		~linkedlistType();
	public:
		nodetype<T> * first;
		nodetype<T> * last;
		int at;
};
template<class T>
linkedlistType<T>::linkedlistType()
{
	first = NULL;
	last = NULL;
}
template<class T>
void linkedlistType<T>::destroyList()
{
	nodetype<T> * current;
	while(current != NULL)
	{
		//delete current;
		current = first;
		first = first->link;
		delete current;
	}
	last = NULL;
}
template<class T>
void linkedlistType<T>::initializeList()
{
	destroyList();
}
template<class T>
void linkedlistType<T>::print()
{
	nodetype<T> * current;
	if(first == NULL)
	{
		cout<<"empty"<<endl;
	}
	else
	{
		current = first;
		while(current != NULL)
		{
			cout<<current->info<<endl;
			current = current->link;
		}
	}	
}
template<class T>
void linkedlistType<T>::insertFirst(const T & newItem)
{
	nodetype<T> * temp;
	temp = new nodetype<T>;
	temp->info = newItem;
	
	
	temp->link = first;
	temp->info = newItem;
	first = temp;
		
	
	if(last == NULL)
	{
		last = temp;
	}
}
template<class T>
void linkedlistType<T>::insertLast(const T & newItem)
{
	nodetype<T> * temp;
	temp = new nodetype<T>;
	if(last == NULL)
	{
		last = first = temp;
	}
	else
	{
		temp->info = newItem;
		temp->link = NULL;
		last->link = temp;
		last = temp;
	}	
}
template<class T>
linkedlistType<T>::~linkedlistType()
{
	destroyList();
}
