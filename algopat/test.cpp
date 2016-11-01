#include<string>
#include<vector>
#include<iostream>
using namespace std;




void printL(int * a , int num)
{
	for(int i = 0; i <num; i++)
	{
		cout<<a[i]<<endl;
	}
}
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
void basicsort(int (&data)[S] , int n)
{
	int d = maxbit(data , n);
	//除数，得到当前位数 
	int *tmp = new int[n];
	int *count = new int[10];
	int i , j , k;
	int radix = 1;
	//循环最高位数次 , radix每次乘10，向前推进位置.
	for(i = 1; i <= d; i++)
	{
		//清空计数数组
		for(j= 0; j < 10; j++)
		{
			count[j] = 0;
		}
		//每个桶中的数量 , 从radix位1开始，就是从各位开始
		for(j = 0; j < n ; j++)
		{
			k = (data[j]/radix) % 10;
			count[k]++;
		}
		
		for(j = 1; j < 10; j++)
		{
			count[j] = count[j-1] + count[j];
		}
		//根据list中每个数的本位数的位置，放入temp中
		for(j = n - 1; j >= 0; j--)
		{
			k = (data[j]/radix)%10;
			//经过上一个循环的处理cout[k]已经代表k所代表的数在temp中的位置
			tmp[count[k] - 1] = data[j];
			//如果有重复的k值，其位置会向前移一位
			count[k]--;
		}
		//将temp中的数据重新灌会list中
		for(j = 0; j < n ; j++)
		{
			data[j] = tmp[j];
		}
		radix = radix * 10;
		//delete []temp;
	}
	delete []tmp;
    delete []count;	
}

int main()
{
	int f[5] = {5232,3323,133,24,1};
	cout<<"---radixt sort test---test"<<endl;
	basicsort<5>(f,5);
	printL(f, 5);
	return 0;
}
