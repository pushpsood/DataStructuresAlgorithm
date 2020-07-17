#include<iostream>
using namespace std;
class Array
{
private:
    int *A;
    int sz;
    int length;
public:
    Array()
    {
        sz=10;
        A=new int[10];
        length=0;
    }
    Array(int s)
    {
        sz=s;
        A=new int[sz];
        length=0;
    }
    ~Array(){delete []A;}
    void Display();
    void Insert(int index,int x);
    void Delete(int index);
};
void Array::Display()
{
    cout<<"\n";
    for(int i=0;i<length;i++)
        cout<<A[i]<<" ";
}
void Array::Insert(int index,int x)
{
    if(index>=0 && index<=length)
    {
        for(int i=length-1;i>=index;i--)
            A[i+1]=A[i];
        A[index]=x;
    }
    length++;
}
void Array::Delete(int index)
{
    if(index>=0 && index<=length)
    {
        for(int i=index;i<length-1;i++)
            A[i]=A[i+1];
    }
    length--;

}
int main()
{
    Array arr(10);
    arr.Insert(0,5);
    arr.Insert(1,8);
    arr.Insert(2,44);
    arr.Insert(3,52);
    arr.Insert(4,90);
    arr.Delete(0);
    arr.Display();
    return 0;
}
