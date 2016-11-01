#include<string>
#include<vector>
#include<iostream>
using namespace std;
//简单选择排序()
int * simpleSelectTurn(int * list , int num)
{
	int index;
	for(int i = 0; i < num ; i++)
	{
		index = i;
		for(int j = i + 1; j <num ; j++)
		{
			if(list[index] > list[j])
			{
				index = j;
			}
		}
		int temp = list[i];
		list[i] = list[index];
		list[index] = temp;
	}
	return list;
}
void printL(int * a , int num)
{
	for(int i = 0; i <num; i++)
	{
		cout<<a[i]<<endl;
	}
}
int * insertSort(int * a , int num)
{
	int temp;
	for(int i = 1; i < num ; ++i)
	{
		if(a[i-1] > a[i])
		{
			temp = a[i];
			int j = i;
			while(j > 0 && a[j-1] > temp)
			{
				a[j] = a[j-1];
				--j;
			}
			a[j] = temp;
		}
	}
	return a;
} 
int * shell(int * list , int num)
{
	for(int gap = num/2; gap > 0; gap /= 2)
	{
		for(int i = gap ; i < num; ++i)
		{
			//判断后面大于前面的，否则算法不启动
			if(list[i] < list[i-gap])
			{
				int temp = list[i];
				int j = i;
				while(j > 0 && list[j] > temp)
				{
					list[j] = list[j-gap];
					j -= gap;
					
				}
				list[j] = temp;
			}
			
		}
	}
	return list;
}
template<int S>
void quicksort(int  (&a)[S] , int left , int right)
{
	int low = left;
	int high = right;
	if(low < high)
	{
		int key = a[low];
		while(low < high)
		{
			
			while(low < high && a[high] > key)
			{
				--high;
			}
			a[low] = a[high];
			while(low < high && a[low] < key)
			{
				++low;
			}
			a[high] = a[low];
		}
		a[low] = key;
		quicksort(a , left , low-1);
		quicksort(a , low+1 , right);
	}
}
//基数
int maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
    int maxData = data[0];		///< 最大数
    /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
    for (int i = 1; i < n; ++i)
    {
        if (maxData < data[i])
            maxData = data[i];
    }
    int d = 1;
    int p = 10;
    while (maxData >= p)
    {
        //p *= 10; // Maybe overflow
        maxData /= 10;
        ++d;
    }
    return d;
/*    int d = 1; //保存最大的位数
    int p = 10;
    for(int i = 0; i < n; ++i)
    {
        while(data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;*/
}
int maxm(int * list , int num)
{
	int max;
	int d = 1;
	for( int i = 0; i < num; ++i)
	{
		if(list[i] > max)
		{
			max = list[i];
		}
	}
	for(int rad = 10; max >= 10 ; rad *= 10)
	{
		max /= 10;
		d++;
	}
	return d;
	
}
template<int S>
void radixsort(int (&data)[S], int n) //基数排序
{
    int d = maxbit(data, n);
    int *tmp = new int[n];
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete []tmp;
    delete []count;
}

template<int S>
void basicsort(int (&data)[S] , int n)
{
	int d = maxbit(data , n);
	//除数，得到当前位数 
	int radix = 1;
	int i , j , k;
	//1到9的桶的计数数组
	int * count = new int[10];
	//每一位排序后存储的临时数组
	int * temp = new int[n];
	//循环最高位数次 , radix每次乘10，向前推进位置.
	for(i = 1; i <= d; ++i)
	{
		//清空计数数组
		for(j = 0; j < 10; j++)
		{
			count[j] = 0;
		}
		//每个桶中的数量 , 从radix位1开始，就是从各位开始
		for(j = 0; j < n ; j++)
		{
			k = (data[j]/radix)%10;
			count[k]++;
		}
		//本位数下（个位/十位...）,data中的数，在该位数下时，在temp中的位置
		//count[i-1] + count[i] 是本位数下，到这个数一共是几个了,直接减1得出在temp中的下标位置,此时就已经根据大小进行了排序
		for(j = 1; j < 10; j++)
		{
			count[j] = count[j-1] + count[j];
		}
		//根据data中每个数的本位数的位置，放入temp中
		for(j = 0; j<n; j++)
		{
			k = (data[j]/radix)%10;
			//经过上一个循环的处理cout[k]已经代表k所代表的数在temp中的位置
			temp[count[k]-1] = data[j];
			//如果有重复的k值，其位置会向前移一位
			count[k]--;
		}
		//将temp中的数据重新灌会data中
		for(j = 0; j < n ; j++)
		{
			data[j] = temp[j];
		}
		radix = radix * 10;
		//delete []temp;
	}
	//最终清理内存
	delete []temp;
    delete []count;	
}
int main()
{
	int a[3] = {3,2,1};
	int b[3] = {33,22,11};
	int c[3] = {333,222,111};
	int d[4] = {555,333,43,54};
	int e[4] = {532,3323,13,24};
	int f[5] = {5232,3323,133,24,1};
	int * aa = simpleSelectTurn(a , 3);
	int * bb = insertSort(b , 3);
	int * cc = shell(c , 3);
	quicksort<4>(d , 0 , 3);
	//cout<<cc[0]<<endl;
	printL(aa , 3);
	printL(bb , 3);
	printL(cc , 3);
	cout<<"for quick"<<endl;
	printL(d , 4);
	cout<<"radix sort"<<endl;
	radixsort<4>(e , 4);
	printL(e , 4);
	cout<<"radixt sort"<<endl;
	int rad = maxm(e , 4);
	cout<<rad<<endl;
	
	cout<<"---radixt sort test---"<<endl;
	basicsort<5>(f,5);
	printL(f, 5);
	return 0;
}
