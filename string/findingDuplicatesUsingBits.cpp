#include<iostream>
using namespace std;
int main()
{
    char s[]="iwrotethis";
    long int h=0,x=0;
    for(int i=0;s[i]!='\0';i++)
    {
        x=1;
        x=(x<<s[i]-97);

        if((h&x)>1)
            cout<<s[i];
        else
            h=x|h;
    }
}
