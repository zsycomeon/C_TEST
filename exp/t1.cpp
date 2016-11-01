#include<iostream>
#include<string>
#include<time.h>
#include<vector>
#include<list>
#include<map>
//copy,find等容器算法
#include<algorithm>
//输入输出流
#include<iostream>
#include<fstream>
//内存数据流
#include<sstream>

using namespace std;
//宏定义数据类型
typedef char * PCHAR;
/*
*ofstream ob("" , "")
*参数2
*	　文件打开方式选项：
　　　　ios::in　　　　= 0x01,　//供读，文件不存在则创建(ifstream默认的打开方式)
　　　　ios::out　　　 = 0x02,　//供写，文件不存在则创建，若文件已存在则清空原内容(ofstream默认的打开方式)
　　　　ios::ate　　　 = 0x04,　//文件打开时，指针在文件最后。可改变指针的位置，常和in、out联合使用
　　　　ios::app　　　 = 0x08,　//供写，文件不存在则创建，若文件已存在则在原文件内容后写入新的内容，指针位置总在最后
　　　　ios::trunc　　 = 0x10,　//在读写前先将文件长度截断为0（默认）
　　　　ios::nocreate　= 0x20,　//文件不存在时产生错误，常和in或app联合使用
　　　　ios::noreplace = 0x40,　//文件存在时产生错误，常和out联合使用
　　　　ios::binary　　= 0x80　 //二进制格式文件
*/




/*
size()指 目前存在的元素数。            元素个数
capacity()指 容器能存储 数据的个数      容器 容量
reserve()指定 容器 能存储数据的个数
resize()  重新 指定 有效元素的个数 ，区别与reserve()指定 容量的大小

*/
//测试容器的元素的个数，重新分配容器容量
//输入内存的是in，内存想外out
void size_test()
{
	//调用宏定义的新数据类型
	PCHAR c1 = "ascvffg";
	vector<int> vc;
	vc.push_back(1);
	//未分配空间
	cout<<"size is:"<<vc.size()<<endl;
	cout<<"capacity is:"<<vc.capacity()<<endl;
	//分配元素空间
	//resize分配了空间，做了实例化,一些重载的函数个操作符有效
	vc.reserve(20);
	vc.resize(22);
	cout<<"size is:"<<vc.size()<<endl;
	cout<<"capacity is:"<<vc.capacity()<<endl;
	//字符数组，字符串，对首位的指针的读取的方式，指针后移，打印所有字符，知道指针指向NULL；
	cout<<"new datatype from micro PCHAR c1="<<c1<<endl;
	cout<<"new datatype from micro PCHAR &c1="<<&c1<<endl;
	vc[15] = 15;
	return;
}
//istream_iterator ostream_iterator back_iterator back_insert_iterator,copy
//数据流迭代测试
void st_iterator()
{
	vector<int> vc1,vc2;
	for(int i = 0;i<5; ++i)
	{
		vc1.push_back(i);
		vc2.push_back(i*10);
	}
	//algorithm中的copy算法,参数一，头指针，参数二，尾指针，参数三，开始放入的复制的初始位置的指针.
	copy(vc1.begin(),vc2.end(),vc2.end());
	vector<int>::iterator j = vc2.begin();
	for( ; j!=vc2.end();++j)
	{
		cout<<"new vc2:"<<*j<<endl;
	}
}
void file_io()
{	
	int A[3][10];
	static int num = 0;
	//读取文件
	string filename;
	string line;
	for (int i = 0;i<3;++i,++num)
	{
		for(int j = 9;j>=0;--j,++num)
		{
			A[i][j] = num;
		}
	}
	//输入输出流对象
	ifstream input("./file/source.txt",ios::in);
	ofstream output("./file/dosth.txt",ios::app);
	//从文件输入数据
	if(!input)
	{
		cerr<<"open input error!!"<<endl;
		exit(-1);
	}
	else
	{
		//从文件逐行读取
		while(getline(input,line))
		{
			//output<<line<<endl;
		}
		//一次性读取
		//内存中的字符串
		ostringstream temp;
		temp<<input.rdbuf();
		string file = temp.str();
		output<<file<<endl;
	}	
	
	if(!output)
	{
		cerr<<"open output error!"<<endl;
		exit(-1);
	}

	for(int i = 0;i<3 ; ++i)
	{
		for (int j = 9;j>=0 ;--j )
		{
			//fstream的方法
			cout << A[i][j];
		}	
	}
	for(int i = 0;i<3 ; ++i)
	{
		for (int j = 9;j>=0 ;--j )
		{
			//fstream的方法
			output << A[i][j] <<" ";
		}
		output << "\r\n";
	}
	input.close();
	output.close();
}






class time_test
{
	public :
		void t1();
};
void time_test::t1()
{
	const time_t t = time(NULL);
	cout<<t<<endl;
	
}
int main(int argc , char * argv[])
{
	time_test t;
	//逐行读取文件数据并逐行写入
	//t.t1();file_io();
	//容器容量测试 size_test();
	//流测试
	st_iterator();
	return 0;
}

