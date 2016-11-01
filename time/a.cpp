#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
int main()
{
	time_t rawtime;
 ctime(&rawtime); 
 std::string timeme = ctime(&rawtime) ;
 std::cout<<"time is "<<timeme<<std::endl;
 
	time_t t;
	t=time(0);
	char now[64];
	struct tm *ttime;
	ttime = localtime(&t);
	strftime(now,64,"%Y%m%d%H%M%S",ttime);
	//char * 转成string
	std::string s(now);
	//输出格式化的字符串
	std::cout<<"time is "<<s<<std::endl;
	return 0;
}