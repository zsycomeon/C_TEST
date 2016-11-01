#include<string>
#include<iostream>

#include "linkedstack.h"
using namespace std;
int main(int argv, char** argc[])
{
	linkedstack<int> lk;
	lk.push(22);
	lk.push(1);
	lk.push(33);
	lk.push(5);
	lk.push(2);
	lk.showstack();
	lk.upturn();
	cout<<"after upturning......"<<endl;
	lk.showstack();
	lk.height = lk.getHei(lk.getTop());
	//lk.getHei(lk.getTop());
	cout<<"height is"<<lk.height<<endl;
	return 0;
}
