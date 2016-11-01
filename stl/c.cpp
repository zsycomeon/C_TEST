#include <iostream>
#include <string>

//using std::cout;
//using std::endl;
using namespace std;

template<class T,int R>
class tempa
{
	public :
		T & operator[](int x);
		tempa(T * a); 
		tempa(const T * b);
		
		
	private	:
		int num;
		T * arr;
}; 
template<class T,int R>
tempa<T,R>::tempa(const T * b)
{
	num = R;
	arr = b;
}
template<class T,int R>
tempa<T,R>::tempa(T * a)
{
	this->arr = a;
	this->num = R;
}
template<class T,int R >
T & tempa<T,R>::operator[](int x)
{
	if(0<=x && x<=this->num)
	{
		return arr[x];
	}
	else
	{
		cerr<<"subscript is out of bounds";
	}	
}
//operater顶层对象函数

template<class T,int R>
ostream & operator<<(ostream & os,const tempa<T,R> & a)
{
	for(int i = 0;i<a.num; ++i)
	{
		os<<a[i]<<" ";
	}
	
	return os;
}
//重载<<,输出单个字符指针，不是从指针开始往下输出
/*
ostream & operator<<(ostream & os,char * s)
{
	os<<s<<" ";
	return os;
}
*/
class book
{
	public :
		char * info;
		char * book_s;
		int aa;
		void test();
		char * te;
		void t2();
		virtual void t3();
	protected :
		book();
		book(char * a);
	private :
		char * a;
};

//protected继承的问题，protected方法，是类内和子类内调用
class codebook:public book
{
	public :
	
		char * book_s;
		char * c_info;
		codebook();
		codebook(char * a);
		void test();
		int aa;
		char *te;
		void t2(int);
		void t3();
	protected : 
		
	
};
void book::t3()
{
	cout<<"book t3 vitual"<<endl;
}
void codebook::t3()
{
	cout<<"codebook t3 non-virtual"<<endl;
}
void book::t2()
{
	cout<<"no args"<<endl;
}
void codebook::t2(int a)
{
	cout<<"bing args"<<endl;
}
void book::test()
{
	cout<<1<<endl;
}
void codebook::test()
{
	cout<<2<<endl;
}
book::book()
{
	book_s = "i am class book";
	aa = 123;
}
codebook::codebook()
{
	book_s = "i am class codebook";
	aa = 333444;
}
book::book(char * a)
{
	//c_info = a;
	te = a;
}
codebook::codebook(char * a)
{
	//c_info = a;
	te = a;
}
int main()
{
	int cs = 2;
	if( cs == 1)
	{
		int * l;
		int a[2] = {1,2};
		char * s = "abcdefg";
		char s2[2] = {'h','e'};
		string s3[2] = {"fu","ck"};
		string s4 = "you";
		tempa<string ,2> t(s3);
		const char * s5 = s4.c_str();
		if(typeid(int *) == typeid(l))
		{
			cout<<"yes"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}
		//cout输出字符数组和string指针下移，输出整个字符串或者数组，整数数组只输出指针
		cout<<t[0]<<endl;	
		cout<<s<<endl;
		cout<<s2<<endl;
		cout<<a<<endl;
	}
	else if(cs == 2)
	{
		/*
		*
		*继承遮蔽:基类的默认构造函数会执行。如果想改变基类的继承来的属性的保护类型，用using改变
		*覆盖：相同签名，继承关系，virtual;
		 遮蔽：同名无需同签名,有无参数都被遮蔽
		 签名：fnnc，args，都相同，无需return相同
		*/
		
		codebook cb;
		cout<<cb.aa<<endl;
		cout<<cb.book_s<<endl;
		cout<<cb.book::book_s<<endl;
		codebook cb2("aabbccdd");
		cout<<cb2.te<<endl;
		cout<<cb2.book::te<<endl;
		//同名被遮蔽
		cb.t2(2);
		//由于派生类中的同名函数不是vir函数，构不成覆盖，是遮蔽 ，所以可调用基类中的函数
		book * p;
		p = new codebook();
		p->t3();
		//调用基类中的函数
		(*p).book::t3();
	}	
	
	
	return 0;
}
