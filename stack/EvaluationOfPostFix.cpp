#include<iostream>
#include<stack>
using namespace std;

int isOperand(char s)
{
    if(s=='+'||s=='-'||s=='*'||s=='/')
        return 0;
    return 1;
}

int Eval(char *s)
{
    stack<int> st;
    for(int i=0;s[i]!='\0';i++)
    {
        if(isOperand(s[i]))
            st.push(s[i]-'0');
        else
        {
            int x,y;
            switch(s[i])
            {
                case '+':{
                x=st.top();
                st.pop();
                y=st.top();
                st.pop();
                st.push(x+y);
                break;
                }
                case '-':{
                x=st.top();
                st.pop();
                y=st.top();
                st.pop();
                st.push(y-x);
                break;
                }
                case '*':{
                x=st.top();
                st.pop();
                y=st.top();
                st.pop();
                st.push(x*y);
                break;
                }
                case '/':{
                x=st.top();
                st.pop();
                y=st.top();
                st.pop();
                st.push(y/x);
                break;
                }
            }
        }
    }
    return st.top();
}
int main()
{
    char *s="12+45/7*+8-8+";
    cout<<Eval(s);
}
