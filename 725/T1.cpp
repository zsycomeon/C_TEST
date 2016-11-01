#include <iostream>
using namespace std;
//基类
class Base{
private:
    int *a;
	
public:
void say(){cout<<"come on"<<endl;}
    Base();
    ~Base(){ cout<<"Base destructor"<<endl; }
};
Base::Base(){
    a = new int[100];
    cout<<"Base constructor"<<endl;
}
//派生类
class Derived: public Base{
private:
    int *b;
public:
    Derived();
    ~Derived( ){ cout<<"Derived destructor"<<endl; }
};
Derived::Derived(){
    b = new int[100];
    cout<<"Derived constructor"<<endl;
}
int main( ){
   Base *p = new Derived;
   p->say();
   delete p;
   return 0;
}
