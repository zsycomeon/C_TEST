#include<iostream>
#include<string>
using namespace std;
template<typename Type>
//二叉树
struct nodetype
{
	Type info;
	nodetype<Type> * llink;
	nodetype<Type> * rlink;
	
	
};
template<class T>
class tree
{
	public :
		//无参数构造 和insert冲突
		//tree(){root = new nodetype<T>;};
		//初始化加定义
		tree(T item);
		//树的高度
		int getHei(nodetype<T>* p);
		//深拷贝，左右一起;
		void copyTree(nodetype<T>* sourceRoot,nodetype<T> * &copyRoot);
		//中序
		void inorder(nodetype<T> * &p,void (* visit)(T &mod));
		//执行中序查找查找，执行内置方法
		void showin(void (* visit)(T &mod));
		//前序
		void preorder(nodetype<T> * &p);
		//外部调用前序
		void showpre();
		//插入
		void insert(const T in);
		//销毁二叉树
		void destroy(nodetype<T> * &p);
		//拷贝函数
		tree(const tree<T> &other);
		//赋值重载
		const tree<T> & tree<T>::operator=(const tree<T>& other);
		//寻找树寻找
		bool search(const T &target);
		//一般树寻找
		void searchN(T target, nodetype<T> * &p , bool &found);
		//执行一般寻找
		void dosearchN(T target);
		//删除节点
		void deleteNode(nodetype<T> * &p);
		//执行删除节点
		void deleteItem(const T&item);
		//遍历执行函数
		void min(T &mod);
	protected :
		nodetype<T> * root;
};
template<class T>
tree<T>::tree(T rootinfo)
{
	nodetype<T> * newnode = new nodetype<T>;
	this->root = newnode;
	root->info = rootinfo;
	root->llink = NULL;
	root->rlink - NULL;
}
//传值引用，相当于深拷贝了一份对象，进行操作
template<class T>
int tree<T>::getHei(nodetype<T>* p)
{
	if( p == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + max(getHei(p->llink) , getHei(p->rlink));
	}	
}
//拷贝
template<class T>
void tree<T>::copyTree(nodetype<T>* sourceRoot,nodetype<T> * &copyRoot)
{
	if(sourceRoot == NULL)
	{
		copyRoot = NULL;
	}
	else
	{
		copyRoot = new nodetype<T>;
		copyRoot->llink = NULL;
		copyRoot->rlink = NULL;
		copyRoot->info = sourceRoot->info;
		copyTree(sourceRoot->llink , copyRoot->llink);
		copyTree(sourceRoot->rlink , copyRoot->rlink);
	}	
}
int max(int a, int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}	
}

//遍历二叉树（尾递归）
//中序遍历 第二位遍历root
//可以写到类中
/*
*
*函数作为参数，形参部分 返回 (* anything) (参数)
*			   实参部分 (* anything)
*/
template<class T>
void tree<T>::inorder(nodetype<T> * &p, void (* visit)(T &mod))
{
	if(p!=NULL)
	{
		inorder(p->llink,* visit);
		//递归中工作的尾递归
		(* visit)(p->info);
		//cout<<p->info<<endl;
		inorder(p->rlink,* visit);
	}
	else
	{
		cout<<"empty tree"<<endl;
	}	
}
template<class T>
void tree<T>::showin(void (* visit)(T &mod))
{
	inorder(root , * visit);
}
//前序
template<class T>
void tree<T>::preorder(nodetype<T> * &p)
{
	if(p == NULL)
	{
		//cout<<"node is empty"<<endl;
	}
	else
	{
		cout<<p->info<<endl;
		preorder(p->llink);
		preorder(p->rlink);
	}	
}
//外部调用前序
template<class T>
void tree<T>::showpre()
{
	preorder(root);
}
//销毁二叉树
template<class T>
void tree<T>::destroy(nodetype<T> * &p)
{
	if(p!=NULL)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = NULL;
		
	}
}
//拷贝函数
template<class T>
tree<T>::tree(const tree<T> &other)
{
	if(other.root == NULL)
	{
		root = NULL;
	}
	else
	{
		copyTree(other.root , root);
	}	
}
//赋值重载
template<class T>
const tree<T> & tree<T>::operator=(const tree<T>& other)
{
	if(this != &other)
	{
		//赋值重载时，元对象可能已经有赋值了，要先销毁
		destroy(root);
		if(other.root == NULL)
		{
			
			root = NULL;
		}
		else
		{
			
			copyTree(other.root , root);
		}	
	}
	return * this;
}
//二叉树中寻找,基于查找二叉树
template<class T>
bool tree<T>::search(const T &target)
{
	nodetype<T> * current;
	bool found = false;
	
	if(root == NULL)
	{
		cout<<"this tree is empty"<<endl;
	}
	else
	{
		current = root;
		while(current != NULL && !found)
		{
			if(current->info == target)
			{
				found = true;
			}
			else if(current->info>target)
			{
				current = current->llink;
			}
			else if(current->info<target)
			{
				current = current->rlink;
			}
		}	
	}
	return found;
}
//基于一般二叉树的寻找
template<class T>
void tree<T>::searchN(T target, nodetype<T> * &p , bool &found)
{
	if(found == false && p != NULL)
	{
		if(p->info == target)
		{
			found = true;
			return;
		}
		else
		{
			searchN(target , p->llink,found);
			searchN(target , p->rlink,found);
		}	
	}
	else if(found == false && p == NULL)
	{
		return;
	}
}
//实现一般查找
template<class T>
void tree<T>::dosearchN(T target)
{
	//最终结果保存在这个引用中
	bool fou = false;
	nodetype<T> * temp = root;
	searchN(target,temp,fou);
	if(fou)
	{
		cout<<"normal is in"<<endl;
	}		
	else
	{
		cout<<"normal is not in"<<endl;
	}	
}
//插入
//通过检测节点是否存在的方法,找出最终节点位置
template<class T>
void tree<T>::insert(const T in)
{
	nodetype<T> * current;
	nodetype<T> * trailcurrent;
	//最后添加的新节点
	nodetype<T> * newnode = new nodetype<T>;
	newnode->info = in;
	newnode->llink = NULL;
	newnode->rlink = NULL;
	//current = root;
	if(root == NULL)
	{
		root = newnode;
		//cout<<"this tree is empty"<<endl;
	}
	else
	{
		current = root;
		while(current!=NULL)
		{
			//叶节点，当前节点的保存，当左节点或者右节点不存在的时候该引用保存最后的节点位置（插入位置）
			trailcurrent = current;
			if(current->info == in)
			{
				cout<<"this has existed"<<endl;
				//整个循环停止
				return;
			}
			else
			{
				//由于是查询二叉树模型结构，最终只能指向一个子树的方向
				if(current->info > in)
				{
					current = current->llink;
				}
				else if(current->info <in)
				{
					current = current->rlink;
				}	
			}	
		}//end while
		if(trailcurrent->info > in)
		{
			trailcurrent->llink = newnode;
		}
		else if(trailcurrent->info < in)
		{
			trailcurrent->rlink = newnode;
		}	
		
	}	
}
//删除节点
//一 根据节点删除
template<class T>
void tree<T>::deleteNode(nodetype<T> * &p)
{
	nodetype<T> * current;
	nodetype<T> * trailcurrent;
	nodetype<T> * temp;
	if(p->llink != NULL && p->rlink != NULL)
	{
		temp = p;
		p = NULL;
		delete temp;
	}
	else if(p->llink == NULL && p->rlink != NULL)
	{
		temp = p;
		p = p->rlink;
		delete temp;
	}
	else if(p->llink != NULL && p->rlink == NULL)
	{
		temp = p;
		p = p->llink;
		delete temp;
	}
	else
	{
		//左支中的总是小于右支
		//左支中最右支的值就是原先节点处的值
		current = p->llink;
		trailcurrent = NULL;
		while(current->rlink != NULL)
		{
			//保存后驱的节点
			trailcurrent = current;
			current = current->rlink;
		}
		//最右的值
		p->info = current->info;
		if( trailcurrent == NULL)
		{
			p->llink = current->llink;
		}
		else
		{
			//后驱的节点左支，接移走的节点的左支
			trailcurrent->rlink = current->llink;
		}	
	}	
}
//二 根据info调用删除节点
template<class T>
void tree<T>::deleteItem(const T&item)
{
	//这里如果用&current表示是root的引用，最后跟就变成了找到的节点，二叉树自然就变了
	nodetype<T> * current = root;
	nodetype<T> * trailcurrent;
	//nodetype<T> * tempaa;
	bool found = false;
	if(root != NULL)
	{
		//current = root;
		trailcurrent = root;
		while(current != NULL && !found)
		{
			
			if(current->info > item)
			{
				trailcurrent = current;
				current = current->llink;
			}
			else if(current->info < item)
			{
				trailcurrent = current;
				current = current->rlink;
			}
			else if(current->info == item)
			{
				found = true;
			}
		}
	}
	else
	{
		cout<<"root is empty"<<endl;
	}	
	//此时不清楚 current是后驱trailcurrent的左还是右，需要判断
	if(current == NULL)
	{
		cout<<"this item isnot in "<<endl;
	}
	else
	{
		if(found)
		{
			
			if(current == root)
			{
				
				deleteNode(current);
			}
			
			if(trailcurrent->info > item )
			{
				//cout<<"current is"<<current<<endl;
				//cout<<"rlink type is "<<typeid(trailcurrent->rlink).name()<<endl;
				//cout<<"current type is "<<typeid(current).name()<<endl;
				
					deleteNode(trailcurrent->llink);

				
			}
			else if(trailcurrent->info < item )
			{
				//cout<<"the compare result is"<<(trailcurrent->rlink == current)<<endl;
				//cout<<"rlink type is "<<typeid(trailcurrent->rlink).name()<<endl;
				//cout<<"current type is "<<typeid(current).name()<<endl;
				deleteNode(trailcurrent->rlink);
				
			}
			
			
			
		}
	}	
	
}
//遍历参数 为函数

void addevr(int &mod)
{
	mod = mod + 1000;
}

//内部函数调用
template<class T>
void tree<T>::min(T &mod)
{
	mod = mod + 2000;
}
