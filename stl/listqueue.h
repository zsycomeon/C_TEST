#include<string>
#include<iostream>
using namespace std;
template<typename T>
class listqueue
{
	public :
		listqueue(int maxsize);
		void initialize();
		bool isFull();
		bool isEmpty();
		void addqueue(const T& add);
		void deque(T & del);
		const listqueue<T> & operator=(const listqueue<T>& other);
		void showinfo();
		//冒泡排序
		void upturn();
	private :
		int maxsize;
		int count;
		int front;
		int rear;
		T * list;
};
template<typename T>
listqueue<T>::listqueue(const int max)
{
	this->count = 0;
	this->maxsize = max;
	this->list = new T[maxsize];
}
template<typename T>
void listqueue<T>::initialize()
{
	front = 0;
	rear = maxsize - 1;
	count = 0;
}
template<typename T>
bool listqueue<T>::isFull()
{
	if(maxsize == count)
	{
		return true;
	}
	else
	{
		return false;
	}	
}
template<typename T>
bool listqueue<T>::isEmpty()
{
	if(count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}	
}
template<typename T>
void listqueue<T>::addqueue(const T& add)
{
	if(count < maxsize)
	{
		rear = (rear + 1) % maxsize;
		list[rear] = add;
		++count;
	}
	else
	{
		cout<<"queue is full,cant add"<<endl;
	}	
	
}
template<typename T>
void listqueue<T>::deque(T& de)
{
	if(count>0)
	{
		de = list[front];
		list[front] = NULL;
		front = (front + 1) % maxsize;
		--count;
	}
	else
	{
		cout<<"queue is empty,cant delete";
	}	
}
template<typename T>
const listqueue<T>& listqueue<T>::operator=(const listqueue<T>& other)
{
	if(maxsize != other.maxsize)
	{
		cout<<"max is different"<<endl;
	}
	else
	{
		front = other.front;
		rear = other.rear;
		count = other.count;
		for(int i = 0; i<maxsize; ++i)
		{
			list[i] = (other.list)[i];
		}
	}
	return * this;
}
template<typename T>
void listqueue<T>::showinfo()
{
	cout<<"front = "<<front<<endl;
	cout<<"rear = "<<rear<<endl;
	cout<<"max = "<<maxsize<<endl;
	cout<<"count = "<<count<<endl;
	for(int i = 0; i<maxsize; ++i)
	{
		cout<<i<<"is"<<list[i]<<endl;
	}
}
template<typename T>
void listqueue<T>::upturn()
{
	T temp;
	//冒泡算法，注意不要下标越界
	for(int i = 0;i<maxsize-1; ++i)
	{
		for(int j = 0; j<maxsize-1;++j)
		{
			if(list[j] > list[j+1])
			{
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
		
	}
}
