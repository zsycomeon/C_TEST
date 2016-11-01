#include<string>
#include<vector>
#include<assert.h>
#include<iostream>
using namespace std;
//引用和取地址符
void add_refe()
{
	int a = 1;
	/*
	*1.区分求地址和引用，引用是为变量取的别名，不产生新的占用，名字是未用过的。&符后连接的变量是存在的话，就是取地址符
	*
	*
	*
	*
	*/
	int &as = a;
	int * p = &a;
	cout<<"as is "<<as<<endl;
	cout<<"&as is "<<&as<<endl;
}
int main(int argc ,char * argv[])
{
	add_refe();
	return 0;
}
