#include<iostream>
using namespace std;
class Array
{
public:
    Array(){length = 0; num = NULL;};
    Array(int * A, int n);
    Array(Array & a);
    Array & operator= (const Array & a);
    void setnum(int value, int index);
    int * getaddress();
    void display();
    int getlength(){return length;}
private:
    int length;
    int * num;
};
Array::Array(Array & a)
{
    if(a.num != NULL)
    {
        length = a.length;
        num = new int[length];
        for(int i=0; i<length; i++)
            num[i] = a.num[i];
    }
    else
    {
        length = 0;
        num = 0;
    }   
}
//重载赋值操作符
Array & Array::operator= (const Array & a)
{
    if( this != &a )
    {
        delete[] num;
        if(a.num != NULL)
        {
            length = a.length;
            num = new int[length];
            for(int i=0; i<length; i++)
                num[i] = a.num[i];
        }
        else
        {
            length = 0;
            num = 0;
        }           
    }
    return *this;
}
Array::Array(int *A, int n)
{
    num = new int[n];
    length = n;
    for(int i=0; i<n; i++)
        num[i] = A[i];
}
void Array::setnum(int value, int index)
{
    if(index < length)
        num[index] = value;
    else
        cout<<"index out of range!"<<endl;
}
void Array::display()
{
    for(int i=0; i<length; i++)
        cout<<num[i]<<" ";
    cout<<endl;
}
int * Array::getaddress()
{
    return num;
}
int main()
{
    int A[5] = {1,2,3,4,5};
    Array arr1(A, 5);
    arr1.display();
    Array arr2(arr1);
    arr2.display();
    arr2.setnum(8,2);
    arr1.display();
    arr2.display();
    cout<<arr1.getaddress()<<" "<<arr2.getaddress()<<endl;
    arr1 = arr2;
    arr1.display();
    arr2.display();
    arr2.setnum(9,3);
    arr1.display();
    arr2.display();
    cout<<arr1.getaddress()<<" "<<arr2.getaddress()<<endl;
    return 0;
}
