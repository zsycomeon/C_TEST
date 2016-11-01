#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<string>
#include<list>
//assert 测试一个条件并可是程序终止
#include<assert.h>
using namespace std;
//非文件ifstream ,ofstream,的
void st_iterator()
{
	//定义存储int的vector的迭代器的简化类名
	typedef vector<int>::iterator It;
	int a[5] = {1,23,3,4,5};
	//两种初始化方法,开始指针，结束指针，个数，元素
	vector<int> vc1,vc2,vc3(a,a+5),vc4(2,5);
	
	
	for(int i = 0;i<5; ++i)
	{
		vc1.push_back(i);
		vc2.push_back(i*10);
	}
	//algorithm中的copy算法,参数一，头指针，参数二，尾指针，参数三，开始放入的复制的初始位置的指针.
	//copy(vc1.begin(),vc2.end(),vc2.end());
	vector<int>::iterator j = vc3.begin();
	for( ; j!=vc3.end();++j)
	{
		cout<<"vc3:"<<*j<<endl;
	}
	vector<int>::iterator jj = vc4.begin();
	for( ; jj!=vc4.end();++jj)
	{
		cout<<"vc4:"<<*jj<<endl;
	}
	
	/*
	贴出copy的源码你就知道错哪了。
	template<class InputIterator, class OutputIterator>
		OutputIterator copy ( InputIterator first, InputIterator last, OutputIterator result )
		{
			//用end()的话没有对象了，越界了
			while (first!=last) *result++ = *first++;  return result;
		}
 */
	
	copy(a,a+5,back_inserter(vc2));
	
	It j2 = vc2.begin();
	for(; j2!=vc2.end(); ++j2)
	{
		cout <<"new vc2:"<<* j2<<endl;
	}
	
	//cout<<"the return_value of vc2's back_inserter is"<<back_inserter(vc2)<<endl;
	//cout<<"the return_value of vc2's end() is"<<vc2.end()<<endl;
	vector<int> vc_s;
	//标准输入对象的迭代器
	istream_iterator<int> i_beg(cin);
	//标准谁对象迭代器末尾无对象即可
	istream_iterator<int> i_end;
	copy(i_beg, i_end,back_inserter(vc_s));
	
	cout << "Output : " << endl;  
	/*
	ostream_iterator<int> io(cout, " ");
	copy(vc_s.begin(), vc_s.end(), io);   
	*/
	//等于上面的直接生成对象，不赋值
	//copy(vc_s.begin(), vc_s.end(), ostream_iterator<int>(cout," ")); 
//输入直接copy到输出上	
	copy(i_beg, i_end, ostream_iterator<int>(cout," "));   
	cout << endl;
	
	vector<int>::iterator j3 = vc_s.begin();
	for(; j3!=vc_s.end(); ++j3)
	{
		cout<<"one of vc_s is"<<* j3<<endl;
	}
	
}
class rb
{
	public :
		void t1();

};
void rb::t1()
{
	
	typedef istream_iterator<int> It;
	typedef ostream_iterator<int> Ot;
	It ts(cin);
	//默认构造无参 不可加括号
	It te;
	//cout<<"begin"<<endl;
	//copy(ts,te,ostream_iterator<int>(cout," "));
	//cout<<" "<<endl;
	
	
	vector<int> vt1;
	list<int> lt1;
	//vector
	vt1.insert(vt1.begin(), 1);
	vt1.insert(vt1.end(), 11);
	vt1.insert(--vt1.end(), 1111);
	vt1.insert(vt1.end()-1, 1111);
	//list
	lt1.insert(lt1.begin(), 2);
	lt1.insert(--lt1.end(), 3);
	lt1.insert(lt1.end(), 4);
	// compile error lt1.insert(lt1.end()-1,5);
	list<int>::iterator j = lt1.begin();
	for(; j!=lt1.end(); ++j)
	{
		cout<<* j<<endl;
	}
	
}
//不区分大小写的string
void ci_s()
{
	int swt = 1;
	//断言assert
	cout<<"before"<<endl;
	//断言为真值继续执行,否则报错
	assert(1>2);
	cout<<"after"<<endl;

	
	
}

//转型构造函数
class Trans
{
	public :
		Trans(){};
		//允许隐式转化
		explicit Trans(char * a);
		friend ostream& operator<<(ostream& os,const Trans& a);
	private :
		int num;
		char * s;
};
ostream& operator<<(ostream& os,const Trans& a)
{
	os<<"Trans's output is "<<a.s<<" ";
	return os;
}
Trans::Trans(char * a)
{
	s = a;
}
//测试隐式转换 和 阻止隐式转化

void tra_t(Trans t)
{
	cout<<t<<endl;
}
int main(int argc, char * argv[])
{
	//st_iterator();
	rb rb1;
	//输入输出对象和迭代器
	//rb1.t1();
	//不区分大小写
	//ci_s();
	//转换构造测试
	Trans t;
	char * ts = "absd";
	//未用explicit , 允许隐式转化，参数类型对应了转型构造的参数类型，自动执行转型构造
	//用xelipcit,调用桩型函数就是调用func
	tra_t(Trans(ts));
	//转换的数据类型必须事先定义好,定义了int，转换char就报错 eg：int tt = 123;tra_t(123);
	return 0;
}
