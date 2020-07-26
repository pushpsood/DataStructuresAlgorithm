#include<iostream>
#include<stack>
using namespace std;
bool Check(string &s)
{
    stack<char> st;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='(') st.push('(');
        else
        {
            if(st.empty())
                return false;
            st.pop();
        }
    }
    return st.empty()?true:false;
}
int main()
{
    string s="(((())))";
    if(Check(s))cout<<"Matching";
    else cout<<"Not Matching";
}

