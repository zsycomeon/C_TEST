#include<iostream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
//�ַ��������
void inputsth()
{
	ofstream ost("./file/os.dat",ios::out);
	int a[] = {1,2,3,4};
	//����ֱ�Ӷ����޳��ȵ�����
	int b[10];
	for(int i = 0;i<4;++i)
	{
		cout<<a[i]<<endl;
		ost<<a[i]<<endl;
	}
	ost.close();
	ifstream ints("./file/os.dat",ios::in);
	cout<<"input from file"<<endl;
	for(int i = 0; i<4; ++i)
	{
		//����������ļ�����Ѷ��һ��������
		//�ļ�����������ʱloop��
		ints>>b[i];
		cout<<b[i]<<endl;
	}
	
}
//����
void chain()
{
	struct A 
	{
		int num;
		A * link;
	};
	A a;
	a.num = 2;
	a.link = &a;
	A * lk = a.link;
	cout<<(&a)<<endl;
	cout<<"link * is"<<lk->num<<endl;
	
	A * ab = new A;
	a.link = ab;
	ab->num = 123;
	
	A * temp;
	int i = 0;
	temp = &a;
	while(temp!=NULL)
	{
		++i;
		temp = temp->link;
	}
	cout<<"the number is"<<i<<endl;
	return;
}
int main()
{
	//inputsth();
	chain();
	return 0;
}
