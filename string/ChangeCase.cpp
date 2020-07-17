
#include<iostream>
using namespace std;
int main()
{
    char A[]="WeLComE";
    int i;
    for(i=0;A[i]!='\0';i++)
        {
            if(A[i]>=65&&A[i]<=90)
                A[i]+=32;
            else
                A[i]-=32;
        }
    for(i=0;A[i]!='\0';i++)
        cout<<"\n"<<A[i];
    return 0;
}

