#include<iostream>
#include<stack>
using namespace std;
string enqueue(stack<int> &s,int x)
{
    s.push(x);
    return "done";
}
int dequeue(stack<int> &s1,stack<int> &s2)
{
    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        if(s2.empty())
            return -1;
    }
    int x=s2.top();
    s2.pop();
    return x;
}
int main()
{
    stack<int> s1;
    stack<int> s2;
    cout<<enqueue(s1,10)<<endl;
    cout<<enqueue(s1,12)<<endl;
    cout<<enqueue(s1,18)<<endl;
    cout<<enqueue(s1,19)<<endl;

    cout<<dequeue(s1,s2)<<endl;
    cout<<dequeue(s1,s2)<<endl;
    cout<<dequeue(s1,s2)<<endl;
    cout<<dequeue(s1,s2)<<endl;
    cout<<dequeue(s1,s2)<<endl;
    cout<<dequeue(s1,s2)<<endl;

    cout<<enqueue(s1,14)<<endl;
    cout<<enqueue(s1,15)<<endl;
    cout<<enqueue(s1,14)<<endl;
    cout<<dequeue(s1,s2)<<endl;
}
