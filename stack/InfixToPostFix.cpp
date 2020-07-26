#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
int isOperand(char s)
{
    if(s=='+'||s=='-'||s=='*'||s=='/')
        return 0;
    return 1;
}
int pre(char c)
{
    if(c=='+'||c=='+')
        return 1;
    if(c=='*'||c=='/')
        return 2;
}
char *Convert(char *s)
{
    stack<char> st;
    int len=strlen(s);
    char *c=new char[len+1];
    int i=0,j=0;
    while(s[i]!='\0')
    {
        if(isOperand(s[i]))
            c[j++]=s[i++];
        else
        {
            if(st.empty())
                st.push(s[i++]);
            else if(pre(s[i])>pre(st.top()))
                st.push(s[i++]);
            else
            {
                c[j++]=st.top();
                st.pop();
            }
        }
    }
    while(!st.empty())
    {
        c[j++]=st.top();
        st.pop();
    }
    c[j]='\0';
    return c;
}
int main()
{
    char *s="a+b+b/a*b+a+b";
    s=Convert(s);
    cout<<s;
}
