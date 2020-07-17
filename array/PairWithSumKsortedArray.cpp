

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
    int Find(int);
    void Display();
    void Insert(int index,int x);
};

void Array::Display()
{
    cout<<"\n";
    for(int i=0;i<length;i++)
        cout<<A[i]<<" ";
}
int Array::Find(int k)
{
    int chk=0;
    int i=0;
    int j=length-1;
    while(i<j)
    {
        if(A[i]+A[j]==k){
                chk=1;
            cout<<"\n Pair is ("<<A[i]<<","<<A[j]<<")";
            i++;j--;
        }
        else if(A[i]+A[j]>k){
            j--;
        }
        else if(A[i]+A[j]<k){
            i++;
        }
    }
    return chk;
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
    arr.Insert(0,1);
    arr.Insert(1,4);
    arr.Insert(2,6);
    arr.Insert(3,9);
    arr.Insert(4,10);
    arr.Insert(5,22);
    arr.Insert(6,44);
    arr.Display();

    int s=arr.Find(10);
    if(s==0)
        cout<<"\n"<<s<<" No pair Found";

}
