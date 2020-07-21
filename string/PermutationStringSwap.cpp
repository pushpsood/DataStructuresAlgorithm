#include<iostream>
using namespace std;
Swap(char &c,char &p)
{

    char t=c;
    c=p;
    p=t;

}
int perm(string s,int l,int h)
{

    if(l==h){
        cout<<s<<endl;
    }
    else{
    for(int i=l;i<=h;i++)
    {
        Swap(s[i],s[l]);
        perm(s,l+1,h);
        Swap(s[i],s[l]);
    }
    }
}
int main()
{
    perm("abcd",0,3);
}
