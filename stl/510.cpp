#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;
class Mysorta
{
	public :
		 int * InsertSorta(int * a, int n);  
		
};
int * Mysorta::InsertSorta(int * a , int n)
{  
	for(int i = 1;i < n; ++i)
	{
		if(a[i-1] > a[i])
		{
			int temp = a[i];
			int j = i;
			while(j > 0 && a[j-1] > temp)
			{
				a[j] = a[j-1];
				--j;
			}//end while
			a[j] = temp;
		}
	}
	return a;
      
}
int change2(char* &name){
    name="alter";
    return 1;
}
int main(int argc, char ** argv[])
{
	Mysorta s1;
	int a[8] = {2,3,1,5,8,6,7,4};
	char b[2] = {'a','b'};
	//非数组形式的可以
	char* string="original!";
	change2(string);
	//
	int * c = s1.InsertSorta(a,8);
	for(int i = 0;i < 8 ; ++i)
	{
		cout<<c[i]<<endl;
	}
	return 0;
}
