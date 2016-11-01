#include<iostream>
#include<fstream>
using namespace std;
class cop
{
	public :
		cop::cop();
		cop(int inum,char * iname);
		cop(const cop& a);
		cop& operator=(const cop& a);
		void show();
	private :
		int num;
		char * name;
};
cop::cop()
{
	num = 0;
	name = 0;
}
cop::cop(int inum, char * iname)
{
	this->num = inum;
	//直接复制指针，导致元数据改变，对象中的数据改变，应该为对象的数据开辟新的空间
	this->name = new char[num];
	//this->name = iname;
	for(int i=0; i<num; ++i)
	{
		name[i] = iname[i];
	}
}
cop::cop(const cop& a)
{
	if(a.num != 0)
	{
		this->num = a.num;
		//如果不预先分配空间，导致不确定错误
		name = new char[num];
		for(int i=0; i<num; ++i)
		{
			name[i] = (a.name)[i];
		}
	}
	else
	{
		this->num = 0;
		this->name = 0;
	}	
}
cop& cop::operator=(const cop& a)
{
	if(this != &a)
	{
		if(a.name != 0)
		{
			delete[] name;
			//delete和delete[]是回收内存空间，所以需要重新开辟空间，否则出现不确定错误，指针不确定
			name = new char[a.num];
			for(int i=0; i<a.num;++i)
			{
				name[i] = a.name[i];
			}
		}
		num = a.num;
	}	
}
void cop::show()
{
	for(int i=0;i<num;++i)
	{
		cout<<name[i]<<endl;
	}
	cout<<"the num is"<<num<<endl;
}
int main(int argc, char ** argv[])
{
	
	int num = 5;
	char * a = "abcde"; 
	char b[5] = {'f','g','h','i','j'};
	
	cop c1(5,a);
	cop c2(c1);
	cop c3(5,b);
	cop c4;
	c2.show();
	//c3.show();
	c4 = c3;
	c4.show();
	return 0;
}
