#include <iostream>
using namespace std;
class complex
{
public:
    complex();
    complex(double a);
    complex(double a, double b);
    friend complex operator+(const complex & A, const complex & B);
    friend complex operator-(const complex & A, const complex & B);
    friend complex operator*(const complex & A, const complex & B);
    friend complex operator/(const complex & A, const complex & B);
    friend istream & operator>>(istream & in, complex & A);
    friend ostream & operator<<(ostream & out, complex & A);
    void display()const;
private:
    double real;   //复数的实部
    double imag;   //复数的虚部
};
complex::complex()
{
    real = 0.0;
    imag = 0.0;
}
complex::complex(double a)
{
    real = a;
    imag = 0.0;
}
complex::complex(double a, double b)
{
    real = a;
    imag = b;
}
//打印复数
void complex::display()const
{
    cout<<real<<" + "<<imag<<" i ";
}
//重载加法操作符
complex operator+(const complex & A, const complex &B)
{
    complex C;
    C.real = A.real + B.real;
    C.imag = A.imag + B.imag;
    return C;
}
//重载减法操作符
complex operator-(const complex & A, const complex &B)
{
    complex C;
    C.real = A.real - B.real;
    C.imag = A.imag - B.imag;
    return C;
}
//重载乘法操作符
complex operator*(const complex & A, const complex &B)
{
    complex C;
    C.real = A.real * B.real - A.imag * B.imag;
    C.imag = A.imag * B.real + A.real * B.imag;
    return C;
}
//重载除法操作符
complex operator/(const complex & A, const complex & B)
{
    complex C;
    double square = A.real * A.real + A.imag * A.imag;
    C.real = (A.real * B.real + A.imag * B.imag)/square;
    C.imag = (A.imag * B.real - A.real * B.imag)/square;
    return C;
}
//重载输入操作符
istream & operator>>(istream & in, complex & A)
{
    in >> A.real >> A.imag;
    return in;
}
//重载输出操作符
ostream & operator<<(ostream & out, complex & A)
{
    out << A.real <<" + "<< A.imag <<" i ";;
    return out;
}
int main()
{
    complex c1(4.3, -5.8);
    complex c2(8.4, 6.7);
    complex c3;
   
    c3 = c1 + c2;
    cout<<"c1 + c2 = "<<c3<<endl;
    c3 = c1 - c2;
    cout<<"c1 - c2 = "<<c3<<endl;
    c3 = c1 * c2;
    cout<<"c1 * c2 = "<<c3<<endl;
    c3 = c1 / c2;
    cout<<"c1 / c2 = "<<c3<<endl;
    return 0;
}
