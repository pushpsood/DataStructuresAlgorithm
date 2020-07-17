#include<iostream>
using namespace std;

class Array{
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
    int Find();
    void Display();
    void Insert(int index,int x);
};

void Array::Display()
{
    cout<<"\n";
    for(int i=0;i<length;i++)
        cout<<A[i]<<" ";
}
int Array::Find()
{
    int dif=A[0];
    for(int i=0;i<length;i++)
    {
        if(A[i]-i!=dif)
            return i+dif;
    }
    return -1;
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

int main()
{
    Array arr;
    arr.Insert(0,5);
    arr.Insert(1,6);
    arr.Insert(2,7);
    arr.Insert(3,8);
    arr.Insert(4,9);
    arr.Insert(5,11);
    arr.Insert(6,12);
    arr.Display();

    int s=arr.Find();
    if(s==-1)
        cout<<"\nNo Element Missing";
    else
        cout<<"\nElement "<<s<<"  Missing";
}
