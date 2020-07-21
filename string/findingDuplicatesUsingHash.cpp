#include<iostream>
using namespace std;
int main()
{
    char s[]="iwrotethis";
    int val[26];
    for(int i=0;i<26;i++)
        val[i]=0;
    for(int i=0;s[i]!='\0';i++)
    {
        val[s[i]-97]+=1;
    }
    for(int i=0;i<26;i++)
    {
        if(val[i]>1)
            printf("%c ",i+97);
    }
}
