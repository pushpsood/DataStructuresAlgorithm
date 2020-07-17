
#include<iostream>
using namespace std;

int main()
{
    char A[]="WeLComE14=5Goa";
    int s;
    int i,j;
    for(s=0;A[s]!='\0';s++);
    for(i=0;A[i]!='\0';i++)
        cout<<A[i]<<" ";
    cout<<endl;
    int pal=1;

    for(i=0,j=s-1;i<=j;i++,j--)
    {
        int temp;
        if(A[i]!=A[j])
            pal=0;
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;

    }
    for(i=0;A[i]!='\0';i++)
        cout<<A[i]<<" ";
    if(pal==0)
        cout<<"\nNot Palindrome";
    else
        cout<<"\nPalindrome";
}

