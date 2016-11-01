#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
template<typename T>
struct Bnode
{
	Bnode<T> * llink;
	Bnode<T> * rlink;
	Bnode():llink(NULL) , rlink(NULL){};
	
	T info;
};
template<class T>
class Btree
{
	public : 
	Btree(){root = NULL ; height = 0;}
		void insert(T addNode);
		void find(T findnode);
		int getHeight(Bnode<T> * &node);
		void deletenode(T deletenode);
		//int max(T a , T b);
		void preorder(Bnode<T>* &node);
		void dopre();
	private :
		Bnode<T> * root;
		int height;
};

template<class T>
int Btree<T>::getHeight(Bnode<T> * &node)
{
	if(node == NULL)
	{
		//this->height = 0;
		return 0;
	}
	else
	{
		return 1 + max(getHeight(node->llink) , getHeight(node->rlink));
	}	
}
template<class T>
void Btree<T>::find(T findnode)
{
	Bnode<T> * current = root;
	bool found = false;
	if(current == NULL)
	{
		cout<<"this BinaryTree is empty,not found."<<endl;
	}
	else
	{
		while(current != NULL && !found)
		{
			if(current->info == findnode)
			{
				//cout<<"the search one is in this BinaryTree."<<endl;
				found = true;
			}
			else if(current->info > findnode)
			{
				current = current->llink;
			}
			else if(current->info < findnode)
			{
				current = current->rlink;
			}
		}//end while
		if(found)
		{
			cout<<"is found"<<endl;
		}
		else
		{
			cout<<"no found"<<endl;
		}	
	}	
}
template<class T>
void Btree<T>::insert(T addnode)
{
	Bnode<T> * current = root;
	Bnode<T> * trailcurrent;
	Bnode<T> * newnode = new Bnode<T>;
	newnode->info = addnode;
	newnode->llink = NULL;
	newnode->rlink = NULL;
	bool found = false;
	if(current == NULL)
	{
		//cout<<"this BinaryTree is empty,not found."<<endl;
		root = newnode;
	}
	else
	{
		
		
		while(current != NULL && !found)
		{
			if(current->info == addnode)
			{
				//cout<<"the search one has existed,cant addin"<<endl;
				//return false;
				//found = true;
				found = true;
			}
			else if(current->info > addnode)
			{
				trailcurrent = current;
				current = current->llink;
			}
			else if(current->info < addnode)
			{
				trailcurrent = current;
				current = current->rlink;
			}
		}//end while
		if(found)
		{
			cout<<"has been in,cant addin"<<endl;
		}
		else
		{
			if(trailcurrent->info > addnode)
			{
				trailcurrent->llink = newnode;
			}
			else if(trailcurrent->info < addnode)
			{
				trailcurrent->rlink = newnode;
			}//end if
		}	
			
	}//end if
}
template<class T>
void Btree<T>::deletenode(T delnode)
{
	//cout<<"delete the"<<delnode<<endl;
	Bnode<T> * current = root;
	Bnode<T> * trailcurrent;
	Bnode<T> * newnode = new Bnode<T>;
	Bnode<T> * temp;
	Bnode<T> * now;
	//开始删除节点
	Bnode<T> * c2;
	Bnode<T> * t2;
	bool found = false;
	while(current != NULL && !found)
	{
		if(current->info == delnode)
		{
			//now = current;
			//cout<<"the searchone has existed"<<endl;
			
			//return false;
			found = true;
		}
		else if(current->info > delnode)
		{
			trailcurrent = current;
			current = current->llink;
		}
		else if(current->info < delnode)
		{
			trailcurrent = current;
			current = current->rlink;
		}
	}//end while
	
	if(found)
	{
		if(current == root)
		{
			now = root;
		}
		else
		{
			if(trailcurrent->info > delnode)
			{
				now = trailcurrent->llink;
			}
			else
			{
				now = trailcurrent->rlink;
			}	
		}
		/*
		问题在下面
		*/
		cout<<"delete address is"<<now->info<<endl;
		Bnode<T> * &p = now;
		Bnode<T> * &pre = trailcurrent;
		if(p->llink == NULL && p->rlink == NULL)
		{
		/*
		问题在下面 左右中有一个为空 或是连个都为空的情况下的删除节点出现问题
		*/
			cout<<"consition1"<<endl;
			pre->llink = NULL;
			temp = p;
			p =  NULL;
			delete temp;
		}
		else if(p->llink == NULL && p->rlink != NULL)
		{
			cout<<"consition2"<<endl;
			if(p == pre->llink)
			{
				temp = p;
				pre->llink = p->rlink;
				p = NULL;
				delete temp;
			}
			else
			{
				temp = p;
				pre->rlink = p->rlink;
				p = NULL;
				delete temp;
			}	
		
			
		}else if(p->llink != NULL && p->rlink == NULL)
		{
			cout<<"consition3"<<endl;
			if(p == pre->llink)
			{
				temp = p;
				pre->llink = p->llink;
				p = NULL;
				delete temp;
			}
			else
			{
				temp = p;
				pre->rlink = p->llink;
				p = NULL;
				delete temp;
			}
		}
		else
		{
			cout<<"consition4"<<endl;
			c2 = p->llink;
			t2 = NULL;
			while(c2->rlink != NULL)
			{
				t2 = c2;
				c2 = c2->rlink;
			}
			p->info = c2->info;
			//删除点的坐支，没有右枝，直接替换为坐支
			if(t2 == NULL)
			{
				p->llink = c2->llink;
			}
			else
			{
				t2->rlink = c2->llink;
			}	
		}	
			
	}
	else
	{
		cout<<"not exited,cant delete"<<endl;
	}	
}
//递归的实现 前序 中序 后序
template<class T>
void Btree<T>::preorder(Bnode<T>* & node)
{
	if(node != NULL)
	{
		cout<<node->info<<endl;
		preorder(node->llink);
		preorder(node->rlink);
	}
	
}
template<class T>
void Btree<T>::dopre()
{
	preorder(this->root);
}
int max(int a , int b)
{
	if(a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}	
}
int main()
{
	Btree<int> bt;
	bt.insert(10);
	bt.insert(5);
	bt.insert(11);
	bt.insert(4);
	bt.insert(6);
	bt.insert(3);
	bt.insert(15);
	bt.insert(16);
	bt.deletenode(4);
	bt.find(4);

	bt.dopre();
	//bt.
	//bt.insert(4);
	//bt.insert(4);
	//bt.insert(2);
	//bt.insert(3);
	//bt.insert(5);
	return 0;
}
