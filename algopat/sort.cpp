#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<math.h>
#include<algorithm>
using namespace std;
class Mysorta
{
	public :
		//插入排序
		int * InsertSorta(int * a, int n); 
		int * InsertSortb(int * a,int n);
		//希尔排序
		int * Shellsort(int * a,int num);
		int * Shelltest(int * a , int num);
		//选择排序-简单选择排序
		int * simpleSelectSort(int * list , int num);
		//简单选择改进 二元选择
		void binarySelectSort();
		//堆排列 满二叉树，叶节点在最下层,完全二叉树，根据满二叉树而来
		/*
		*建堆，调整堆，堆排序
		*i 2*i + 1 , 2* i +2 i = 0时候特殊
		*/
		void heapSort();
		//快速排序
		void quickSort(int  (&a)[11] , int left , int right);
		//快速排序测试
		void quickSort_t(int (&a)[11] , int left , int right);
		
};
//快速排序
void Mysorta::quickSort(int  (&a)[11] , int left,int right)
{
	if(left < right)
	{
		int key = a[left];
		int low = left;
		int high = right;
		//这个循环是关键，把中间的液循环进来了。
		while ( low < high )
		{
			//从末尾开始
			while( low < high && a[high] > key)
			{
				high--;
			}
			a[low] = a[high];
			while( low < high && a[low] < key)
			{
				low++;
			}
			a[high] = a[low];
		}
		a[low] = key;
		quickSort(a , left, low-1);
		quickSort(a , low+1, right);
	}
}
//快速排序测试
void Mysorta::quickSort_t(int (&a)[11] , int left , int right)
{
	if(left < right)
	{
		int low = left;
		int high = right;
		int key = a[low];
		while(low < high)
		{
			while(low < high && a[high] > key)
			{
				high--;
			}
			a[low] = a[high];
			while(low < high && a[low] < key)
			{
				low++;
			}
			a[high] = a[low];
		}
		a[low] = key;
		quickSort_t(a , left , low-1);
		quickSort_t(a , low+1 , right);
	}
	
}
void mergearray(int (&a)[11], int first, int mid, int last, int temp[])  
{  
    int i = first, j = mid + 1;  
    int m = mid,   n = last;  
    int k = 0;  
      
    while (i <= m && j <= n)  
    {  
        if (a[i] <= a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }  
    cout<<"phase 1: k is "<<k<<endl;  
    while (i <= m)  
        temp[k++] = a[i++];  
    cout<<"phase 2: k is "<<k<<endl;   
    while (j <= n)  
        temp[k++] = a[j++];  
    cout<<"phase 3: k is "<<k<<endl;   
    for (i = 0; i < k; i++)  
        a[first + i] = temp[i];  
}
void mergesort(int (&a)[11], int first, int last, int temp[])  
{  
    if (first < last)  
    {  
        int mid = (first + last) / 2;  
        mergesort(a, first, mid, temp);    //左边有序  
        mergesort(a, mid + 1, last, temp); //右边有序  
        mergearray(a, first, mid, last, temp); //再将二个有序数列合并  
    }  
}
//简单选择排序
int * Mysorta::simpleSelectSort(int * list , int num)
{
	for(int i = 0 ; i < num ; ++i)
	{
		//index保存最小项下标
		int index = i;
		//寻找从i开始的最小项
		for( int j = i + 1; j < num ; ++j)
		{
			if(list[index] > list[j])
			{
				index  = j;
			}
		}
		//找出了从i开始往后最小项，与i交换位置
		int temp = list[i];
		list[i] = list[index];
		list[index] = temp;
		//++i 继续找
	}
	return list;
}
int * Mysorta::InsertSorta(int * a , int n)
{  
	for(int i = 1;i < n; ++i)
	{
		//从第二位开始
		
		if(a[i-1] > a[i])
		{
			//当前值
			int temp = a[i];
			//当前下标
			int j = i;
			//挤位置
			//第一个位置一定动了
			//移动一个j和j-1同值了 
			//当什么时候当前值大于哨兵时停止
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
int * Mysorta::InsertSortb(int * a,int len)
{
	for (int i = 1; i < len; ++i)
	{
		if(a[i-1] > a[i])
		{
			//哨兵变量
			int j = i;
			int temp = a[i];
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
//shell sort
int * Mysorta::Shellsort(int * a,int num)
{
	//gap步数
	int j,gap;
	for( gap = num/2 ; gap > 0 ; gap /= 2)
	{
		//同一个步数下的循环
		for (j = gap ; j < num ;  j++)
		{
			//挤位置
			if(a[j] < a[j-gap])
			{
				//哨兵
				int temp = a[j];
				int k = j;
				while(k > 0 && a[k] > temp)
				{
					a[k] = a[k-gap];
					k = k-gap;
				}//end while
				a[k] = temp;
			}
			
		}
	}
	return a;
}
//Shelltest
int * Mysorta::Shelltest(int * a , int num)
{
	int gap;
	for (gap = num / 2 ; gap > 0 ; gap /= 2)
	{
		//归结为分块的插入排序
		int j; 
		int temp;
		for(int i = gap ; i < num ; i++)
		{
			//if( a[])
				j = i ; 
				temp = a[j];
				if(a[j] < a[j-gap])
				{
					while(j > 0 && a[j-gap] > temp)
					{
						a[j] = a[j-gap];
						j -= gap;
					}//end while
					a[j] = temp;
				}
		}
	}// end final for
	return a;
}
int change2(char* &name){
    name="alter";
    return 1;
}
//十进制转2进制
//某处的形参有默认值 后面的必须有
void htob(int &wei , int &b, int &h)
{
	if(h > 0)
	{
		//得数
		int m = h / 2;
		//余数
		int l = h%2;
		//float转int +0.5不失精度
		b = b + l * int(pow(10,wei)+0.5);
		wei++;
		h = m;
		htob(wei , b , h);
	}
	
	
}

//堆排序
void heapRebuild(int arr[],int root,int size)  
{  
    int child=2*root+1;  
    if(child<=size-1)  
    {  
        int rightChild=child+1;  
        if(rightChild<=size-1)  
            if(arr[child]<arr[rightChild])  
                child=rightChild;  
        if(arr[root]<arr[child])  
        {  
            int temp=arr[child];  
            arr[child]=arr[root];  
            arr[root]=temp;  
            heapRebuild(arr,child,size);  
        }  
    }  
}
int * heapSort(int arr[],int size)  
{  
    for(int i=size-1;i>=0;i--)  
    {  
        heapRebuild(arr,i,size);  
    }  
    int last=size-1;  
    for(int i=1;i<=size;i++,last--)  
    {  
        int temp=arr[0];  
        arr[0]=arr[last];  
        arr[last]=temp;  
        heapRebuild(arr,0,last);  
          
    }  
	return arr;
  
}
//打印向量
void priVec(vector<int> vec)
{
	for(vector<int>::iterator j = vec.begin(); j != vec.end(); ++j)
	{
		cout<<* j<<endl;
	}
	return;
}
 
//stl heap实现堆排序和建立堆
void stl_heap(int * list , int num)
{
	/*
	make_heap(list , &list[num-1]);
	sort_heap(list , &list[num-1]);
	*/
	vector<int> * vec = new vector<int>(11);
	vec->assign(list , &list[num-1]);
	//建堆,不建堆的话，可能在push和pop之后，再去sort的话出现错误排序
	make_heap(vec->begin() , vec->end());
	//先在容器中加入数据，再在堆中加入(调整堆)
	vec->push_back(5555);
	push_heap(vec->begin() , vec->end());
	cout<<"after push"<<endl;
	priVec(* vec);
	sort_heap(vec->begin() , vec->end());
	cout<<"after sort"<<endl;
	priVec(* vec);
	//删除数据
	pop_heap(vec->begin() , vec->end());
	vec->pop_back();
	sort_heap(vec->begin() , vec->end());
	cout<<"after pop and sort"<<endl;
	priVec(* vec);
	return;
}
/******索引查找*******/
//索引项
struct IndexItem
{
	public :
	//索引项其实关键字 , 根据自己规定的索引规则得出来的值
		int index;
		int start;
		int length;
		IndexItem(){index = 0;};
		IndexItem(int index , int start , int length){this->index = index;this->start = start;this->length = length;};
};
//索引类
class Index
{
	public :
		//主表
		int * main_tab;
		
		//索引表
		IndexItem ** IndexItemList;
		//查找
		Index(int a[] , int num);
		int IndexSearch (int key);
		
};
Index::Index(int a[] , int num)
{
	for(int i = 0; i < num ; ++i)
	{
		this->main_tab[i] = a[i];
	}
	//this->main_tab;
	//int temp_main[] = {101,102,103,104,105,0,0,0,0,0,201,202,203,204,0,0,0,0,0,0,301,302,303,0,0,0,0,0,0,0};
	//this->main_tab = temp_main;
	//cout<<"main_tab in index() "<<this->main_tab<<endl;
	IndexItem * temp_index[] = { new IndexItem(1,0,5) , new IndexItem(2,10,4) , new IndexItem(3,20,3)};
	this->IndexItemList = temp_index;
	
}
int Index::IndexSearch(int key)
{
	//cout<<"main_tab in search is"<<this->main_tab<<endl;
	IndexItem * item;
	int value = key/100;
	//给出索引列表长度
	for(int i = 0; i < 3 ; ++i)
	{
		if(IndexItemList[i]->index == value)
		{
			item = IndexItemList[i];
		}
	}
	
	if ( item->index == 0 )
	{
		return -1;
	}	
		
	//cout<<item->start<<" "<<item->start + item->length<<endl;
	//cout<<"haha2"<<this->main_tab[0]<<endl;
	//cout<<key<<endl;
	//cout<<"haha22"<<this->main_tab[11]<<endl;
	//cout<<"hahafffffff"<<this->main_tab[2]<<endl;
	//cout<<"key is "<<key<<"this->main_tab[12] is"<<this->main_tab[12]<<endl;
	int res;
	for( int j = item->start ; j < item->start + item->length ; ++j )
	{
		//如果不是结果的值在前面的话，最先弹出的就是-2，跳出循环，无法抓到正确值了
		if(this->main_tab[j] == key)
		{
			//cout<<"j"<<j<<endl;
			//return j;
			res = j;
			break;
		}
		else
		{
			//return -2;
			res = -2;
			//break;
		} 
		
			
	}
	return res;
		
		
}



int main(int argc, char ** argv[])
{
	Mysorta s1;
	int a[11] = {2,3,1,5,8,6,7,4,11,33,44};
	int bb[11] = {11,22,55,44,111,33,66,99,77,444,222};
	int cc[11] = {563,1,2,11,3,4,5,6,1111,45,1233};
	int dd[11] = {22,33,44,11,2,3,4,8,99,23,1};
	int ee[11] = {1,3,11,2,5,4,435,333,123,54,44};
	char b[2] = {'a','b'};
	//非数组形式的可以
	char* string="original!";
	change2(string);
	//
	int * c = s1.InsertSortb(a,11);
	int * d = s1.Shellsort(a , 11);
	int * e = s1.Shelltest(a , 11);
	
	for(int i = 0;i < 11 ; ++i)
	{
		cout<<e[i]<<endl;
	}
	cout<<"hex to binay"<<endl;
	int hex = 3;
	int wei = 0;
	int bin = 0;
	htob(wei , bin , hex);
	cout<<"h"<<hex<<endl;
	cout<<"b"<<bin<<endl;
	
	cout<<"this is simple "<<endl;
	int * f = s1.simpleSelectSort(a , 11);
	for(int i = 0;i < 11 ; ++i)
	{
		cout<<f[i]<<endl;
	}
	cout<<"heap is simple "<<endl;
	int * g = heapSort(bb , 11);
	for(int i = 0;i < 11 ; ++i)
	{
		cout<<g[i]<<endl;
	}
	cout<<"stl_heap is here "<<endl;
	stl_heap(cc , 11);
	
	cout<<"this is quick testa"<<endl;
	s1.quickSort_t(dd , 0 , 10);
	for(int i = 0;i < 11 ; ++i)
	{
		cout<<dd[i]<<endl;
	}
	cout<<"This is merge "<<endl;
	int temp[11];
	mergesort(ee , 0 , 10 ,temp);
	for(int i = 0;i < 11 ; ++i)
	{
		cout<<ee[i]<<endl;
	}
	
	cout<<"------This is index search------"<<endl;
	
	int isa[] = {101,102,103,104,105,0,0,0,0,0,201,202,203,204,0,0,0,0,0,0,301,302,303,0,0,0,0,0,0,0};
	Index index(isa , 30);
	//cout<<"main_tab is "<<index.main_tab[0]<<endl;
	int res = index.IndexSearch(203);
	//cout<<"main_tab is "<<index.main_tab[0]<<endl;
	if(1)
	{
		
		cout<<"index is "<<res<<endl;
		cout<<"main_tab is "<<index.main_tab<<endl;
	}
	return 0;
}
