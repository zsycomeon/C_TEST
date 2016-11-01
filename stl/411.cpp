#include<string>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
//容器的数学算法
#include<numeric>
using namespace std;
typedef vector<int> v_int;
void print_e(char &a)
{
	cout<<a<<endl;
}
void print_int(int &a)
{
	cout<<a<<endl;
}
int main(int argc, char** argv[])
{
	int a[] = {1,2,3};
	char b[] = {'a','b','c'};
	//参数三函数的参数是每个指针指向的元素
	for_each(b,b+3,print_e);
	//如果没发现元素，返回end指针
	int *j = find(a,a+3,5);
	//a+3是最后一个元素后一位的指针，为end
	if(j == a+3)
	{
		cout<<"no found"<<endl;
	}
	else
	{
		cout<<j<<endl;
	}		
	v_int vec1(a,a+3);
	int nei = inner_product(vec1.begin(),vec1.end(),vec1.begin(),0);
	//0-(1+1)-(2+2)-(3+3)
	int rnei = inner_product(vec1.begin(),vec1.end(),vec1.begin(),0,minus<int>(),plus<int>());
	cout<<"nei ji is"<<nei<<endl;
	cout<<"ani nei ji is"<<rnei<<endl;
	map< char, int > m;
    m[ 'a' ] = 1;
    m[ 'b' ] = 2;
    m[ 'c' ] = 3;
    m[ 'd' ] = 4;
    m[ 'e' ] = 1;
    m[ 'f' ] = 2;
    m[ 'g' ] = 3;
    m[ 'h' ] = 4;
	//覆盖
    m[ 'a' ] = 0;   
    map< char, int >::iterator itor;
    for(itor = m.begin(); itor != m.end(); itor++)
		//first是键值 second是值
       cout << itor->first << " -- " << itor->second <<endl;
      
   ostream_iterator<int> out(cout, " ");
   //最后一位说明负
   //1 ,1+(-2),1+(-2)+(-3)
    partial_sum(vec1.begin(),vec1.end(),out,minus<int>());
	cout<<endl;
	 //1 ,1+(2),1+(2)+(3)
	partial_sum(vec1.begin(),vec1.end(),out);
	cout<<endl;
	//差值
	cout<<"dengcha";
	adjacent_difference(vec1.begin(),vec1.end(),out);
	cout<<endl;
	//pair , mismatch算法
	int ia[10] = {11,22,33,44,55,66,77,88,99,100};
	vector<int> as(ia+5,ia+7);
	vector<int> bs(ia+4,ia+7);
	//pair模板只有两个参数
	//模板声明中，只写的是类型名，而不是对象的形参或是对象的引用
	pair<vector<int>::iterator,vector<int>::iterator> pa;
	//
	pa = mismatch(as.begin(),as.end(),bs.begin());
	//如果不匹配,first返回第一个容器的首位指针， second返回最后一个收为指针
	if(pa.first == as.end() && pa.second == bs.end())
	{
		cout<<"totally the same"<<endl;
	}
	else
	{
		cout<<"mismatch"<<endl;
		cout<<*(pa.first)<<endl;
		cout<<*(pa.second)<<endl;
	}
	if(equal(as.begin(),as.end(),bs.begin()))
	{
		cout<<"is equal"<<endl;
	}
	else
	{
		cout<<"not equal"<<endl;
	}
	//填充
	cout<<"fill"<<" ";
	vector<int> vecf1(ia,ia+9);
	for_each(vecf1.begin(),vecf1.end(),print_int);
	fill(vecf1.begin(),vecf1.end(),9);
	for_each(vecf1.begin(),vecf1.end(),print_int);
	cout<<endl;
	//交换
	vector<int> vecf2(ia,ia+9);
	vector<int>::iterator ite1=vecf2.begin();  
    vector<int>::iterator ite2=ite1;  
	advance(ite2,3);//向前跳3个  
    iter_swap(ite1,ite2);//交换迭代器指向的元素 ,迭代器本身指针位置不变 
    for_each(vecf2.begin(),vecf2.end(),print_int);  
	swap(*ite1,*ite2);  
	for_each(vecf2.begin(),vecf2.end(),print_int);  
    return 0;
	
}
