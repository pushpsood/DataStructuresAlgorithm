
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
    int pt=0;
    int dif=A[0];
    for(int i=0;i<length;i++)
    {
        if(A[i]-i!=dif)
            {
                for(int j=dif;j<A[i]-i;j++)
                {
                    pt=1;
                    cout<<"\nMissing Element: "<<dif+i;
                    dif++;
                }
            }
    }
    if(pt==0)
    return -1;
    return 0;
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
    arr.Insert(3,10);
    arr.Insert(4,11);
    arr.Insert(5,13);
    arr.Insert(6,15);
    arr.Display();

    int s=arr.Find();
    if(s==-1)
        cout<<"\nNo Element Missing";

}
