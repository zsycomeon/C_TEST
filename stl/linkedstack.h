#include<iostream>
#include<string>
#include<vector>
using namespace std;
template<typename T>
struct nodeType
{
	T info;
	nodeType<T> * link;
};
//类和结构，可以单独成立新的模板
template<typename Type>
class linkedstack
{
	public :
		void push(const Type&);
		void pop(Type &);
		//无参构造函数
		linkedstack();
		//拷贝构造函数
		linkedstack(const linkedstack<Type>& other);
		//重载等于赋值号
		const linkedstack<Type>& operator=(const linkedstack<Type>&);
		//显示栈中的内容
		void showstack();
		//销毁整个栈
		void destroy();
		//链表直接排序
		void upturn();
		//高度
		int getHei(nodeType<Type>*p);
		int height;
		nodeType<Type> * getTop();
		//排序链表栈：拆分链表
		//first2中保存2分的指针
		void divideList(nodeType<Type> * first1,nodeType<Type> *&first2);
		
		
	protected : 
		nodeType<Type> * top;
		
};
template<typename Type>
linkedstack<Type>::linkedstack()
{
	top = NULL;
}
template<typename Type>
void linkedstack<Type>::push(const Type &t)
{
	nodeType<Type> * p = new nodeType<Type>;
	if(top == NULL)
	{
		top = p;
		top->link = NULL;
		top->info = t;
	}
	else
	{
		//符合栈的向上规则
		p->link = top;
		p->info = t;
		top = p;
		/*
		top->link = p;
		top = p;
		top->link = NULL;
		top->info = t;
		*/
	}	
}
template<typename Type>
void linkedstack<Type>::pop(Type &poppedlinkedItem)
{
	poppedlinkedItem = top->info;
	nodeType<Type> * temp;
	temp = top;
	top = top->link;
	/*
	*
	*delete操作的参数是指针,delete[]操作参数是指针，顺着初始指针往下删除，释放指针的内存空间
	*/
	delete temp;
}
template<typename Type>
linkedstack<Type>::linkedstack(const linkedstack<Type> &other)
{
	
	//other临时变量
	nodeType<Type> * current, *newNode,*temp,*realtop;
	if(other.top == NULL)
	{
		top = NULL;
		
	}
	else
	{
		top = new nodeType<Type>;
		//开始的问题出在top最后的值被写成了压栈的最后一层，用影子变量穿最初的top值
		realtop = top;
		current = other.top;
		//分界处
		/*
		top->info = current->info;
		top->link = NULL;
		temp = top;
		current = current->link;
		while(current != NULL)
		{
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->link = NULL;
			temp->link = newNode;
			temp = newNode;
			current = current->link;
		}
		*/
		
		
		while(current != NULL)
		{
			cout<<current->info<<endl;
			if(current->link != NULL)
			{
				temp = new nodeType<Type>;
				top->link = temp;
				top->info = current->info;
				top = temp;
				current = current->link;
			}
			else
			{
				top->link = NULL;
				top->info = current->info;
				current = current->link;
			}	
			
			
		}
		top = realtop;
		
		
		
		
		
	}	
}
template<typename Type>
void linkedstack<Type>::showstack()
{
	nodeType<Type> * temp = new nodeType<Type>;
	temp = top;
	int i = 1;
	if(temp != NULL)
	{
		while(temp!=NULL)
		{
			cout<<"rank is "<<i<<endl;
			cout<<"info is "<<temp->info<<endl;
			temp = temp->link;
			++i;
		}
	}
	else
	{
		cout<<"err : this stack is empty"<<endl;
	}	
	
}
template<typename Type>
void linkedstack<Type>::destroy()
{
	nodeType<Type> * temp = new nodeType<Type>;
	if(top == NULL)
	{
		cout<<"err: this stack is empty"<<endl;
	}
	else
	{
		cout<<"destroying..."<<endl;
		
		while(top != NULL)
		{
			temp = top;
			top = top->link;
			//最后删除指针
			delete temp;
			
		}
		top = NULL;
		
	}
}

//如果右侧长度大于左侧长度，会造成内存浪费，需要先清理一下
template<typename Type>
const linkedstack<Type>& linkedstack<Type>::operator=(const linkedstack<Type>&other)
{
	if(this != &other)
	{
		nodeType<Type> * temp,* current,*realtop;
		//清理
		destroy();
		if(other.top == NULL)
		{
			top = NULL;
		}
		else
		{
			current = other.top;
			top = new nodeType<Type>;
			realtop = top;
			while(current != NULL)
			{
				if(current->link != NULL)
				{
					temp = new nodeType<Type>;
					top->link = temp;
					top->info = current->info;
				}
				else
				{
					top->link = NULL;
					top->info = current->info;
				}
				top = top->link;
				current = current->link;
			}
			top = realtop;
		}
		//返回的是一个const对象
		return * this;
	}
}
//归并排序(分步运行)

//拆分链表
template<typename Type>
void linkedstack<Type>::divideList(nodeType<Type> * first1,nodeType<Type> * &first2)
{
	nodeType<Type>* middle;
	nodeType<Type>* current;
	if(first1 = NULL) 
	{
		first2 = NULL;
	}
	else
	{
		if(first1->link = NULL)
		{
			first2 = NULL;
		}
		else
		{
			middle = first1;
			current = first1->link;
			//链表长度大于3的话，间隔两个节点
			if(current!=NULL)
			{
				current = current->link;
			}
			while(current != NULL)
			{
				middle = middle->link;
				current = current->link;
				if(current != NULL)
				{
					current = current->link;
				}
			}
			first2 = middle->link;
			//拆分成两个链表
			middle->link = NULL;
		}	
	}	
}

//链表直接排序
template<typename Type>
void linkedstack<Type>::upturn()
{
	nodeType<Type> * min, * current, *incurrent;
	current = min = top;
	while(current->link!=NULL)
	{
		incurrent = top;
		while(incurrent->link!=NULL)
		{
			Type temp;
			if(incurrent->info > incurrent->link->info)
			{
				temp = incurrent->info;
				incurrent->info = incurrent->link->info;
				incurrent->link->info = temp;
			}
			incurrent = incurrent->link;
		}
		current = current->link;
	}
    
      
}
//二叉树高度
template<typename Type>
int linkedstack<Type>::getHei(nodeType<Type>* p)
{
	//int hei;
	//p = top;
	if(p == NULL)
	{
		//hei = 0;
		return 0;
	}
	else
	{
		return 1 + getHei(p->link);
	}	
	//return hei;
}
//getTop
template<typename Type>
nodeType<Type>* linkedstack<Type>::getTop()
{
	return top;
}
