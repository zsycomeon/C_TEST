#include<string>
#include<iostream>
using namespace std;
template<typename T>
class Mystack
{
	//对于析构函数和构造函数不声明封装类型，默认为private
	public:
	//实例化
	Mystack(int stacksize);
	//初始化
	void initialize();
	//判空和判满
	bool isEmpty(const Mystack& st);
	bool isFull(const Mystack& st);
	//拷贝和重载赋值符
	Mystack(const Mystack &st);
	const Mystack<T>& operator=(const Mystack<T>&st);
	//压栈和出栈
	void push(const T &t);
	void pop(T &t);
	//析构
	~Mystack();
	private :
		int maxsize;
		int top;
		//数组
		T * list;
	
};
template<typename T>
//泛型类之后的<T>不能缺失
const Mystack<T>& Mystack<T>::operator=(const Mystack<T>&st)
{
	if(this != &st)
	{
		if(maxsize != st.maxsize)
		{
			cout<<"Cannot copy.The two stack are in different sizes"<<endl;
		}
		else
		{
			top = st.top;
			if(top != 0)
			{
				list = new T[maxsize];
				for(int i = 0; i<maxsize;++i)
				{
					list[i] = st.list[i];
				}
			}
		}	
	}
	//内部赋值，返回*this
	return * this;
}
template<typename T>
void Mystack<T>::initialize()
{
	top = 0;
}
template<typename T>
void Mystack<T>::push(const T& newItem)
{
	//top值代表的是当前存储的元素的个数
	list[top] = newItem;
	//数组中的下标是上一个的top值，初始top=0
	++top;
}
//出栈的元素保存在一个定义好的元素中
template<typename T>
void Mystack<T>::pop(T &poppedItem)
{
	//栈顶的下标小于top1
	--top;
	poppedItem = list[top];
}
template<typename T>
Mystack<T>::Mystack(int stacksize)
{
	if(stacksize<=0)
	{
		cout<<"The size of a stack must be positive"<<endl;
	}
	else
	{
		
		maxsize = stacksize;
		list = new T[maxsize];
		top = 0;
	}	
}
template<typename T>
Mystack<T>::~Mystack()
{
	top = 0;
	delete[] list;
}
