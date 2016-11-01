#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
/*
*算法 数据额结构 cpp的实现
*1 递归
*
*
*
*
*
*
*/

using namespace std;
typedef vector<int> VI;
//递归测试
template<class T>
T find_lg(const T a[],T lower,T upper)
{
	T max;
	//递归，首先应该找到一个结果规律
	if(lower == upper)
	{
		
		max = a[lower];
		return max;
	}	
	else
	{
		max = find_lg(a , lower+1 , upper);
		if(a[lower] > max)
		{
			max = a[lower];
			return max;
		}
		else
		{
			return max;
		}	
	}	
}
int find_lg_ite(int * a,int upper)
{
	int max = 0;
	for (int i = 0; i<=upper; ++i)
	{
		if(a[max] < a[i])
		{
			max = i;
		}
	}
	return a[max];
}
int fib(const int a)
{
	int res;
	if(a == 0 || a == 1)
	{
		res = 1;
	}
	else
	{
		res = fib(a-1) + fib(a-2);
	}	
	return res;
}
//2进制数 转10进制数
//数值传参，引用传参，地址传参
//引用传参，地址传参有相同之处。数值传参纯粹传值，对对象本身没有改变。
void bintodec(int &binaryNumber, int& decimal ,int& weight)
{
	int bit;
	if(binaryNumber > 0)
	{
		//最右侧位的值
		bit = binaryNumber%10;
		//转换为int的模板函数，更换类名就可以转为其他了
		decimal = decimal + bit*static_cast<int>(pow(2,weight)+0.5);
		
		//向左缩进
		binaryNumber = binaryNumber/10;
		//权重自增
		++weight;
		//递归
		bintodec(binaryNumber,decimal,weight);
	}
}
void dectobin(int& decimal,int &binary,int & weight)
{
	int bit;
	if(decimal > 0)
	{
		bit = decimal%2;
		//cout<<"bit---"<<bit<<endl;
		decimal = decimal/2;
		//cout<<"before---"<<binary<<endl;
		//double tem = pow(10,weight);
		//cout<<"temp---"<<tem<<endl;
		/*
		*double转换成int 的精度问题 方法一 int (double+0.5)
		*
		*/
		
		binary = binary + bit*int(pow(10,weight)+0.5);
		//cout<<bit*static_cast<int>(pow(10,weight))<endl;
		//cout<<"after---"<<binary<<endl;
		++weight;
		dectobin(decimal , binary ,weight);
	}
}
//测试double转为int
int main(int argv,char ** argc[])
{
	int a[] = {1,2,44,55,2,33};
	//由于数组未指定长度，越界赋值出现不确定错误，程序崩溃
	//a[3] = 3;
	int arrsize = sizeof(a)/sizeof(int) ; 
	cout<<arrsize<<endl;
	//算法弹性，参数2在不越界的情况下可调整
	int max = find_lg(a,0,3);
	int max2 = find_lg_ite(a,2);
	cout<<"largest one is"<<max<<endl;
	cout<<"largest_loop is"<<max2<<endl;
	//fib
	int res = fib(4);
	cout<<"fib res is"<<res<<endl;
	
	//二进制转换为十进制
	int bin = 100110;
	int decimal = 0;
	int weight = 0;
	bintodec(bin , decimal , weight);
	cout<<"decimal is"<<decimal<<endl;
	cout<<"at last bin is"<<bin<<endl;
	
	//十进制转二进制
	int dec2 = 777;
	int bin2 = 0;
	int weight2 = 0;
	dectobin(dec2,bin2,weight2);
	cout<<"bin2 is"<<bin2<<endl;
	return 0;
}

