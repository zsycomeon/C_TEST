#include<string>
#include<iostream>
#include "tree.h"
using namespace std;
int main(int arga, char ** argc[])
{
	tree<int> tr1(1);
	tr1.insert(2);
	tr1.insert(3);
	tr1.showpre();
	tr1.showin(addevr);
	
	cout<<"after showin the addevr......"<<endl;
	tr1.showpre();
	tree<int> tr2(tr1);
	cout<<"this is tr2"<<endl;
	tr2.showpre();
	tree<int> tr3(11);
	tree<int> tr4(1);
	tr3.insert(22);
	tr3.insert(33);
	tr3.insert(44);
	tr3.insert(55);
	cout<<"this is tr3"<<endl;
	tr4 = tr3;
	tr3.showpre();
	tr3 = tr2;
	cout<<"this is tr3 = tr2"<<endl;
	tr3.showpre();
	cout<<"this is search"<<endl;
	if(tr4.search(244))
	{
		cout<<"it is in it"<<endl;
	}
	else
	{
		cout<<"is not in is"<<endl;
	}	
	
	int tar = 2223;
	tr4.dosearchN(tar);
	int tar2 = 22;
	tr4.dosearchN(tar2);
	cout<<"after deleting..."<<endl;
	tr4.deleteItem(33);
	tr4.showpre();
	return 0;
}
