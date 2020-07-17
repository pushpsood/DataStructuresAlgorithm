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
    int Find(int,int);
    void Display();
    void Insert(int index,int x);
    int Min();
    int Max();
};
int Array::Max()
{
    int m=-1;
    for(int i=0;i<length;i++)
    {
        if(A[i]>m)
            m=A[i];
    }
    return m;
}
int Array::Min()
{
    int m=100000;
    for(int i=0;i<length;i++)
    {
        if(A[i]<m)
            m=A[i];
    }
    return m;
}

void Array::Display()
{
    cout<<"\n";
    for(int i=0;i<length;i++)
        cout<<A[i]<<" ";
}
int Array::Find(int l,int h)
{
    int done=-1;
    int newl=h-l+1;
    int *ptr=new int[newl];
    for(int i=0;i<h-l+1;i++)
        ptr[i]=0;
    for(int i=0;i<length;i++)
        ptr[A[i]-l]++;
    for(int i=0;i<h-l+1;i++)
    {
        if(ptr[i]==0){
            done=0;
            cout<<"\nElement "<<i+l<<" Missing";
    }}
    delete []ptr;
    return done;
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
    arr.Insert(2,19);
    arr.Insert(3,22);
    arr.Insert(4,23);
    arr.Insert(5,24);
    arr.Insert(6,25);
    arr.Display();
    int l=arr.Min();
    int h=arr.Max();
    int s=arr.Find(l,h);
    if(s==-1)
        cout<<"\nNo Element Missing";
}
