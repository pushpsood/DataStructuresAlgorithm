

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
    int lastD=-1;
    int counter=0;
    for(int i=0;i<length-1;i++)
    {
        if(A[i]==A[i+1]&&A[i]!=lastD)
        {
            counter++;
            lastD=A[i];
            cout<<"\nElement "<<A[i]<<" is Duplicate";
        }
    }
    return counter;
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
    arr.Insert(1,5);
    arr.Insert(2,5);
    arr.Insert(3,12);
    arr.Insert(4,12);
    arr.Insert(5,13);
    arr.Insert(6,15);
    arr.Display();

    int s=arr.Find();
    if(s>0)
        cout<<"\n"<<s<<" Element Duplicate";

}
