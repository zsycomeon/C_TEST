#include <iostream>
/*
**	赋值符重载 拷贝构造
*/
using namespace std;
class Array
{
	public :
		//拷贝构造函数
		
		Array(){this->arr = NULL; this->num = 0;};
		Array(Array& a);
		//传参构造
		Array(int * arr,int num);
		//Array& operator=(const Array& a) ;
		Array & operator= (const Array & a);
		//重载【】操作符，重载操作符，如果是成员函数的话，对于类本身非常方便，顶层函数重载操作符，需要考虑传入的类型
		//同名 const非const是两个函数 返回的对象不可改
		const int& operator[](int) const;
		//返回的对象可操作
		int& operator[](int);
		~Array();
		void showInfo();
	private : 
		int * arr;
		int num;
};
Array::Array(int * arr, int num)
{
	this->num = num;
	this->arr = arr;
}
Array::Array(Array& a)
{
	//如果a.num != num warning
	if(a.arr != NULL)
	{
		
		arr = new int[a.num];
		int i;
		for(i=0; i<a.num; i++)
		{
			arr[i] = a.arr[i];
			//cout<<arr[i]<<endl;
		}
		num = a.num;
	}
	else
	{
		num = 0;
		arr = 0;
	}	
}

const int& Array::operator[](int i) const
{
	if(i<0 || i>((this->num)-1))
	{
		cout<<"out of bounds"<<endl;
	}
	return (this->arr)[i];
}

int& Array::operator[](int i)
{
	if(i<0 || i>((this->num)-1))
	{
		cout<<"out of bounds"<<endl;
	}
	return (this->arr)[i];
}

Array::~Array()
{
	delete[] this->arr;
	cout<<"Array destructor"<<endl;
}
//形参之前的const就是防止 参数在函数内部被改变，其实无意义 因为本身是形参
//深层拷贝，只复制数据结构，数据指针不相同
Array& Array::operator=(const Array& a) 
{	
	//赋值和深度克隆是相同的，赋值数据结构和数据的值，数据内的指针不同
	if(this != &a)
	{
		//此处 空构造0 和NULL 不能混用
		if(a.arr != NULL)
		{
			//浅克隆版
			/*
			*this->arr = a.arr;
			*&(this->num) = &(a.num);
			*
			*/
			delete[] this->arr;
			this->arr = new int[a.num];
			this->num = a.num;
			int i;
			for (i=0; i<a.num; i++)
			{
				(this->arr)[i] = a.arr[i];
			}
		}
		else
		{
			this->arr = 0;
			this->num = 0;
		}
		
	}
	return * this;
		
}
/*
Array & Array::operator= (const Array & a)
{
    if( this != &a )
    {
        delete[] num;
        if(a.num != NULL)
        {
            length = a.length;
            num = new int[length];
            for(int i=0; i<length; i++)
                num[i] = a.num[i];
        }
        else
        {
            length = 0;
            num = 0;
        }           
    }
    return *this;
}
*/
void Array::showInfo()
{
	int i = 0;
	for (; i<this->num ; i++)
	{
		cout<<(this->arr)[i]<<"\n"<<endl;
	}
	cout<<"num is"<<this->num<<endl;
}
int main()
{
	//继承C 数组为{}
	int a[5] = {1,2,3,4,5};
	int b[5] = {11,22,33,44,55};
	Array a1(a,5);
	//不能对一个对象 构造两次
	Array a2(a1);
	Array a3(b,5);
	//无参构造时 不能用空括号
	Array a4;
	a1 = a3;
	a4 = a2;
	
	/*
	a1.showInfo();
	a2.showInfo();
	a3.showInfo();
	a4.showInfo();
	*/
	//重载后，可将对象向数组对象一样调用
	int x1 =a1[1];
	int x2 =a1[6];
	x1 = 123;
	cout<<x1<<endl;
	cout<<x2<<endl;
	//但是非const成员函数不能处理const对象
	//亲测缺少const成员函数 无法操作cosnt Array
	const Array c(a,5);
	int x3 = c[1];
	cout<<x3<<endl;
	return 0;
}
