#include <stdio.h>
#include <math.h>
int main(void)
{
	void arr_arg(void);
	void reverse(int * x, int y);
	void arr_add(void);
	void arr_arg2(void);
	void arr_avg(void);
	void search(float (*a)[4] , int n);
	int max(int ,int);
	int min(int ,int);
	int fun(int n,int a,int b,int (* p)(int , int));
	int xf(int,int);
	void str_pointer(void);
	void str_test(void);
	void struct_test(void);
	//整形数组测试
	//arrT();
	//arrT2();
	//排序算法
	//get_turn();
	//二维数组
	//get_tdem();
	//二维找出最大元素
	//get_max_from_darr();
	//擂台
	//get_max();
	//use_mulr();
	//递归测试
	/*
	int res = recursion(4);
	printf("%12d" , res);
	*/
	//二维数组测试
	//point();
	//arr_arg();
	//arr_add();
	//arr_arg2();
	//arr_avg();
	/*
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int i;
	//int b = 2;
	reverse(a , 3);
	for (i = 0;i<10 ; i++)
	{
		printf("%d \n",a[i]);
	}
	*/
	float a[3][4] = {{10,20,7,80},{99,99,99,99},{11,12,66,66}};
	//search(a,3);
	int res;
	res = fun(2,20,30,xf);
	//printf("%d \n", res);
	//str_pointer();
	//str_test();
	struct_test();
	return 0;
}
int arrT(void)
{
	int i,x,y,a[10];
	printf("请输入x,y\n");
	scanf("x=%d,y=%d",&x,&y);
	printf("x=%d,y=%d\n",x,y);
	for (i = 0; i<10 ; i++)
	{
		//printf("%d \n",a[i]);
		a[i] = i;
	}
	for (i=0; i<10; i++)
	{
		printf("%d \n",a[i]);
	}
}
int arrT2(void)
{
	int i;
	int f[20] = {1,1};
	for (i=2; i<20 ; i++)
	{
		f[i] = f[i-2] + f[i-1];
	}
	for (i=0; i<20; i++)
	{
		if(i%5 == 0)
		{
			printf("\n");
			
		}
		printf("%12d",f[i]);
	}
	printf("\n");
	return 0;
}
int get_turn(void)
{
	int n,i,temp;
	int a[10] = {11,1,4,6,5,33,12,32,1,10};
	//10个数气泡10次
	for(n=0; n<10; n++)
	{
		//刨除不存在的元素
		for (i=0; i<10; i++)
		{
			if(i+1 <= 9)
			{
				if(a[i] > a[i+1])
				{
					temp = a[i+1];
					a[i+1] = a[i];
					a[i] = temp;
				}
			}
		}
	}
	
	for( i=0; i<10; i++)
	{
		printf("%d \n",a[i]);
	}
	return 0;
}
int get_tdem(void)
{
	int a[2][3] = {{1,2,3},{4,5,6}};
	int b[3][2], i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			b[j][i] = a[i][j];
		}
	}
	for(i=0;i<3;i++)
	{
		
		for(j=0;j<2;j++)
		{
			
			printf("%d",b[i][j]);
			if(j == 1)
			{
				printf("\n");
			}
		}
	}
	return 0;
}
int get_max_from_darr(void)
{
	int a[3][4] = {{11,2,3,4},{53,16,127,81},{9,110,11,12}},b[]={},i,j,n=0,temp,x,y;
	//存入一维数组中
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++,n++)
		{
			b[n] = a[i][j];
		}
	}
	//查看存放数据的一维数组
	for(i=0;i<n;i++)
	{
		//printf("%d \n",b[i]);
	}
	//一维数组冒泡,最后一位是最大
	for(i=0;i<n;i++)
	{
		for(j=0 ; j<n ;j++)
		{
			if(j+1 < n)
			{
				if(b[j] > b[j+1])
				{
					temp = b[j];
					b[j] = b[j+1];
					b[j+1] = temp;
					
				}
			}
		}
	}
	//查看冒泡后的一维数组
	for(i=0;i<n;i++)
	{
		printf("%d \n",b[i]);
	}
	//比较最大值 得出行，列（下标加1）
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++,n++)
		{
			//b[n] = a[i][j];
			if(a[i][j] == b[11])
			{
				x=i+1;
				y=j+1;
			}
		}
	}
	printf("max:%d,x:%d,y:%d" , b[11],x,y);
	return 0;
}
//获取二维数组最大值（打擂台）
int get_max(void)
{
	int a[3][4] = {{11,2,3,4},{53,16,127,81},{9,110,11,12}},b[]={},i,j,n=0,temp=0,x,y;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[i][j] > temp)
			{
				temp = a[i][j];
				x = i+1;
				y = j+1;
			}
		}
	}
	printf("Max:%d , x:%d, y:%d",temp , x ,y);
	return 0;
}
int strTest(void)
{
	//字符数组表示字符串
	char a[] = {'a','b','c','d'};
	char b[] = {"a b c d"};
	char c[] = "vvbb";
	char d[] = "vvbb\0";
	return 0;
}
int use_mulr(void)
{
	int res = mulr();
	printf("%d \n" , res);
	return res;
}
int mulr(void)
{
	//执行第一个return
	return 1;
	return 2;
}
//递归测试
int recursion(int x)
{
	int res;
	if(x == 0)
	{
		res = 1;
	}
	else if(x == 1)
	{
		res = 1;
	}
	else
	{
		res = recursion(x-1) + recursion(x-2);
	}
	//printf("%12d" , res);
	return res;
}
//指针测试
int point(void)
{
	int i = 123;
	int a = 101;
	int b = 11;
	int * pointera;
	int * pointerb;
	pointera = &b;
	pointerb = &a;
	printf("a=%d,b=%d",a,b);
	printf("pa=%d,pb=%d",pointera,pointerb);
	//问题出现在这里 a的值存在&a , * pointera现在的值存在&b中，如此赋值就是&b中的内容覆盖了&a中的内容
	//a = * pointera;
	//b = * pointerb;
	printf("a=%d,b=%d",* pointera,* pointerb);
	
	/*
	
	int * p1,* p2, *p, a,b;
	a = 11;
	b = 101;
	p1 = &a;
	p2 = &b;
	if(1)
	{
		p = p1;
		p1 = p2;
		p2 = p;
	}
	printf("a=%d,b=%d \n",* p1,* p2);
	*/
	/*
	int * pointerb;
	int * add;
	add = &i;
	int * pointera = &a;
	* pointerb = b;
	printf("pointer=%d,num=%d,pointerb=%o" , pointera,* pointera,pointerb);
	//printf("i=%d", *add);
	*/
	return 0;
}
//数组 形参 实参
void arr_arg(void)
{
	int arr[10];
	int i;
	for(i=0; i<10; i++)
	{
		printf("%d \n",arr+i);
	}
}
//定义形参接收的就是指针变量，所以应该传指针
void reverse(int * x , int n)
{	
	//去余数
	printf("%d \n" ,3/2);
	int * p,temp,* i,* j,m=(n-1)/2;
	//起始地址
	i = x;
	//结束地址
	j = x+n-1;
	//中间地址
	p = x +m;
	for( ; i<=p; i++, j--)
	{
		temp = * i;
		* i = * j;
		* j = temp;
	}
	return;

}
//数组地址
void arr_add(void)
{	
	int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int * i = a[0];
	int n = 0;
	//printf("%d \n" ,a);
	//printf("%d \n" ,a[0]);
	//printf("%d , %d \n" , &a[0] , a[0]);
	for ( ; n<12; n++,i++)
	{
		if(n%4 == 0)
		{
			printf("\n");
		}
		printf("%d" , * i);
	}
	return;
}
void arr_arg2(void)
{
	int a[3][4] = {1,2,3,4,5,6,7,8,9,10};
	int b[4] = {1111,2,3,4};
	//定义指针变量p,指向一行包含4个元素的一维数组, 其实就是定义了一个数组
	int (* p)[4];
	int (* t)[4];
	p = a;// p = &a[0];
	t = &b;
	printf("%d \n" ,(* t)[0]);
	return;
}
void arr_avg(void)
{
	int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int sum = 0;
	int avg ,i;
	int * j;
	for (i = 0,j = a[0]; i<12 ; i++,j++ )
	{
		sum += * j;
	}
	printf("sum=%d , avg=%d" , sum, sum/12);
	return;
}
void search(float (*p)[4] , int n)
{
	int i=0 ,j, flag=0;
	for ( ; i<n ;i++)
	{
		for (j=0 ; j<4 ; j++)
		{
			if( *(*(p + i) + j) < 60)
			{
				flag ++;
			}
		}
		if(flag >1)
		{
			printf(" %d号没过,挂了%d科 \n",i+1,flag);
			printf(" No.%d was down ,there are %d shit in \n",i+1,flag);
		}
		flag = 0;
	}
	return;
}
int fun(int n,int a,int b,int (* p)(int , int))
{
	int max(int ,int);
	int min(int ,int);
	//p是指向一个函数的指针，所以可以对他进行赋值
	if(n ==1 )
	{
		p = max;
	}
	else if (n == 2)
	{
		p = min;
	}
	return (* p)(a,b);
}
int max(int a,int b)
{
	if(a > b)
	{
		return a;
	}
	else
	{
		return b;
	}	
}
int min(int a, int b)
{
	if(a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int xf(int a, int b)
{
	return a;
}
void str_pointer(void)
{
	char str1[10] = "i fuck you";
	char * str2 = "i u";
	printf("%c" , str2[0]);
	return;
}
void str_test(void)
{
	//输出字符串数组的时候直接需求地址
	int a[2][2] = {11,22,33,44};
	int b[3][3] = {1,2,3,4,5,6,7,8,9};
	/*
	int表示指向整数的指针，下面指针指向的是一维数组
	int * arr[] = {a , b};
	*/
	int * arr[] = {a[0] , b[0]};
	int ** loc;
	//保存指针的数组
	char * str[] = {"name","age","schoole"};
	//指向数组中的指针的指针
	char **p;
	int i;
	for (i = 0; i<3; i++)
	{
		p = str + i;
		printf("%s \n", *p);
	}
	for (i = 0; i<2 ; i++)
	{
		loc = arr + i;
		printf("%d \n", (* loc)[0]);
	}
	return;
}
//定义结构体
void struct_test()
{
	struct Sa 
	{
		int num;
		char name[20];
		
	};
	struct Sa a1,a2;
	a1.num = 1;
	(a1.name)[0] = 'z';
	(a1.name)[1] = 's';
	(a1.name)[2] = 'y';
	printf("%s" , a1.name);
	struct Sa aa[3] = {{1,"arrt1"},{2,"arrt2"},{3,"arrt3"}};
	//a3[0] = {1,"arrt1"};
	//a3[1] = {2,"arrt2"};
	//a3[2] = {3,"arrt3"};
	struct Sa * p ;
	printf("%d , %s \n" , (*(aa+1)).num , (*(aa+1)).name);
	for (p = aa ; p < aa + 2; p++)
	{
		//结构体数组, 地址->结构体下标
		printf("%d , %s \n", p->num , p->name);
	}
	return;
}
