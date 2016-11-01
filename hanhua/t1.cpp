#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
using namespace std;
class ZT
{
	public : 
		int a;
};
void test1()
{
	ofstream out("a.bin",ios::binary|ios::app|ios::ate);
	int num = 20;
	string str = "Hello world";
	/*
	out.write((char *)&num, sizeof(int));
	out.write(str.c_str(),sizeof(char) * (str.size()));
	out.close();
	FILE * fr;
	fr = fopen("a.bin","r");
	*/
	int num_char = sizeof(char);
	int num_int = sizeof(int);
	int num_uint = sizeof(unsigned int);
	int num_int_arr = sizeof(int[2]);
	int num_long = sizeof(long);
	int num_double = sizeof(double);
	int num_ZT = sizeof(ZT);
	cout<<"one char is"<<num_char<<"bytes"<<endl;
	cout<<"one int is"<<num_int<<"bytes"<<endl;
	cout<<"one int[2] is"<<num_int_arr<<"bytes"<<endl;
	cout<<"one unsigned int is"<<num_uint<<"bytes"<<endl;
	cout<<"one long is"<<num_long<<"bytes"<<endl;
	cout<<"one double is"<<num_double<<"bytes"<<endl;
	cout<<"one ZT is"<<num_ZT<<"bytes"<<endl;
	
	//
	int num_str = str.size();
	cout<<num_str<<endl;
}
void test2()
{
	//ifstream input;
	//input.open("./file/in.bin",ios::binary|ios::in);
	double num[4] = {1.11,2.22,3.33,4.44};
	ofstream output("./file/out.bin",ios::binary|ios::out);
	if(!output)
	{
		cerr<<"output file error"<<endl;
	}
	output.write((char *)&num,sizeof(num));
	output.close();
	//delete[] num;
	
	ifstream input("./file/input.bin",ios::binary|ios::in);
	input.read((char *)& num , sizeof(num));
	cout<<input.gcount()<<"bytes read\n"<<endl;
	input.close();
}
void test3()
{
	fstream f;
	f.open("./file/article.frm",ios::in|ios::binary);
	string s;
	if(!f.is_open())
	{
		cerr<<"open error"<<endl;
	}
	else
	{
		while(getline(f,s))
		{
			cout<<s<<endl;
		}
	}	
	
} 
int t4()
{
   char ch[20];
   cout<<"enter a sentence:"<<endl;
   cin>>ch;
   cout<<"The string read with cin is:"<<ch<<endl;
   //指针随着输出到的位置在移动
   cin.getline(ch,20,'/');  //读个字符或遇'/'结束
   cout<<"The second part is:"<<ch<<endl;
   cin.getline(ch,20);  //读个字符或遇'/n'结束
   cout<<"The third part is:"<<ch<<endl;
   return 0;
}
void t5()
{
   int a[10];
   int b[10];
   ofstream outfile("./file/f1.dat",ios::out);//定义文件流对象,打开磁盘文件"f1.dat"
   if(!outfile)                        //如果打开失败,outfile返回值
   {
      cerr<<"open error!"<<endl;
      exit(1);
   }
   cout<<"enter 10 integer numbers:"<<endl;
   for(int i=0;i<10;i++)
   {
      cin>>a[i];
      outfile<<a[i]<<" ";
   }            //向磁盘文件"f1.dat"输出数据
   outfile.close(); 
   int max,i,order;
   //定义输入文件流对象,以输入方式打开磁盘文件f1.dat
   ifstream infile("./file/f1.dat",ios::in);
   if(!infile)
   {
      cerr<<"open error!"<<endl;
      exit(1);
   }
   //测试从文件中输出，再输入到文件中
   ofstream output("./file/ot.dat");
   for(i=0;i<10;i++)
   {
      //此处的输入，到当前的文件流当中,cout或者fout都可以用这个内存中的数据输出
	  infile>>b[i];  //从磁盘文件读入10个整数,顺序存放在b数组中
      cout<<b[i]<<" ";  //在显示器上顺序显示10个数
	  output<<b[i]<<"\n ";
   }         
   cout<<endl;
   max=a[0];
   order=0;
   for(i=1;i<10;i++)
      if(a[i]>max)
      {
         max=a[i];  //将当前最大值放在max中
         order=i;  //将当前最大值的元素序号放在order中
      }
   cout<<"max="<<max<<endl<<"order="<<order<<endl;
   infile.close();
}

int main(int argc, char** argv[])
{
	
	//test1();
	//test2();
	//test3();
	//t4();
	//t5();

	return 0;
}
