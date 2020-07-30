#include<iostream>
using namespace std;

Heapify(int A[],int n)
{
    int i=n;
    while(i>0)
    {
        int k=i;
        int j=2*i;
        if(j>n){}
        else
        {
            j=2*k;
            while(j<=n)
            {
            if(A[j+1]>A[j]&&j+1<n)
            {
                j=j+1;
            }
            if(A[k]<A[j])
            {
                int temp=A[j];
                A[j]=A[k];
                A[k]=temp;
                k=j;
            }
            else break;
            j=2*k;
            }
        }
        i--;
    }
}


int main()
{
    int A[]={0,10,40,20,15,100,400,320,350,600,188,7845,451};
    Heapify(A,13);

    for(int i=1;i<=12;i++)
        cout<<A[i]<<" ";
}
