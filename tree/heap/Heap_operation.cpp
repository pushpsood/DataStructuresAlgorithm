#include<iostream>
using namespace std;
void Insert(int A[],int n)
{
    int i=n,temp=A[n];
    while(i>1&&temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
void HeapSort(int A[],int n)
{
    for(int k=n;k>=1;k--)
    {

    int i,j,x;
    int val=A[1];
    x=A[1];
    A[1]=A[k];
    A[k]=val;
    i=1;j=2*i;
    while(j<k-1)
    {
        if(A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j])
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        else
            break;
    }
    }
}
int del(int A[],int n)
{
    int i,j,x;
    int val=A[1];
    x=A[1];
    A[1]=A[n];
    A[n]=val;
    i=1;j=2*i;
    while(j<n-1)
    {
        if(A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j])
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        else
            break;
    }
    return val;
}
int main()
{
    int A[]={0,10,20,30,25,5,40,35};
    //40,25,35,10,5,20,30
    for(int i=2;i<=7;i++)
    Insert(A,i);

    cout<<del(A,7);

    cout<<endl;

    for(int i=1;i<=7;i++)
        cout<<A[i]<<" ";
 cout<<endl;
    HeapSort(A,6);
    for(int i=1;i<=7;i++)
        cout<<A[i]<<" ";

}
