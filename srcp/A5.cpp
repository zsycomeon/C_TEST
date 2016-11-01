#include <iostream>
using namespace std;
class remend
{
public:
    remend(){hour = min = ap = 0;}
    remend(int h, int m, int ap);
    operator int();
private:
    int hour;
    int min;
    int ap;  // 0表示am, 1表示pm
};
remend::remend(int h, int m, int ap)
{
    hour = h;
    min = m;
    this->ap = ap;
}
//转型操作符重载函数
remend::operator int()
{
    int time = hour;
    if(time == 12)
        time = 0;
    if(ap == 1)
        time += 12;
    time *= 100;
    time += min;
    return time;
}
int main()
{
    remend c(5,7,1);
    int time = c;
    cout<<time<<endl;
    return 0;
}
