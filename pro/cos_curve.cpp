#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
enum A {a = 1, b = 1, c};
int main()
{
	void cos_cur();
	void cir_cur();
	void avg();
	//cos_cur();
	//cir_cur();
	avg();
	return 0;
}
//cos函数曲线
void cos_cur()
{
	double y;
	int x,m;
	for(y = 1.00;y >= -1.00;y -= 0.10)
	{
	m = acos(y)*10;
	//if for while 后面能接代码块的，无花括号，只影响后面的第一个语句
	for(x=1;x<m;x++) 
		printf(" ");printf("*");
	for(; x<62-m; x++) 
		printf(" ");printf("*\n");
	
	}
	return;
}
//空心圆
void cir_cur()
{
	//m是横坐标
	int x,m;
	double y;
	//m**2+y**2 = 100
	
	for(y=10;y>=-10;y--)
	{
		m = 2*sqrt(100-y*y);
		for(x = 1;x<30-m;x++)
		{
			printf(" ");
		}
		printf("*");
		for(; x<30+m; x++)
		{
			printf(" ");
		}
		printf("*\n");
	}
	
	return;
}
//平均分
void avg()
{
	time_t t;
	srand((unsigned) time(&t));
	int a[10];
	for(int i = 0;i<10 ; ++i)
	{
		a[i] = rand();
	};
	
	for(int n=0;n<10;++n)
	{
		for(int j = 0;j<10;j++)
		{
			if(a[j]>a[j+1])
			{
				if(j<9)
				{
					int temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
				
			}
		}
	}
	/*
	printf("---------\n");
	printf("---------");
	for(int i=0;i<10;++i)
	{
		printf("%d\n",a[i]);
	}
	*/
	a[0] = a[9] = 0;
	for(int i = 0;i<10; ++i)
	{
		temp += a[i];
	}
	return;
}
