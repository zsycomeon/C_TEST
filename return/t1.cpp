#include <stdio.h>
using namespace std;
namespace S1{
	int flag;
	class Item{
		public :
			bool flag;
	}
}
namespace S2{
	bool flag;
	class Item{
		public :
			int flag;
	}
}
struct S{
		char * name;
		int age;
		float score;
	};
class B{
	public :
		char * name;
		int age;
		float score;
	public :
		void say();
};

int main(){
	
	struct S stu1;
	stu1.name = "小明";
	stu1.age = 12;
	S1::flag = 1;
	S2::flag = true;
	return 0;
}
