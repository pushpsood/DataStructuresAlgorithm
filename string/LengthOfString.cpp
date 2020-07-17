#include<iostream>
using namespace std;
int main()
{
    char *ptr="Welcome";
    int i;
    for(i=0;ptr[i]!='\0';i++);
    cout<<i;
    return 0;
}
