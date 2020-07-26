
#include<iostream>
using namespace std;
class Stack
{
public:
    int sz;
    int top;
    int *s;
};
void Display(Stack st)
{
    for(int i=st.top;i>=0;i--)
        cout<<st.s[i]<<" ";
    cout<<endl;
}
void push(Stack *st,int x)
{
    if(st->top==st->sz-1)
        cout<<"OverFlow"<<endl;
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}
int pop(Stack *st)
{
    int x=-1;
    if(st->top==-1)
        cout<<"UnderFlow"<<endl;
    else
    {
        x=st->s[st->top--];
    }
    return x;
}
int peek(Stack st,int index)
{
    if(st.top-index+1<0) cout<<"Invalid Index";
    else return st.s[st.top-index+1];
    return -1;
}
int isEmpty(Stack st)
{
    if(st.top==-1)
        return 1;
        return 0;
}
int isFull(Stack st)
{
    return st.top==st.sz;
}
int Top(Stack st)
{
    if(st.top==-1)
        return -1;
    return st.s[st.top];
}
int main()
{
    Stack st;
    int a;
    cout<<"Enter Size of Stack";
    cin>>a;
    st.sz=a;
    st.top=-1;
    st.s=new int[a];
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);
    push(&st,5);
    push(&st,6);
    Display(st);
    cout<<endl<<pop(&st);
    cout<<endl<<pop(&st);
    cout<<endl<<pop(&st)<<endl;
    Display(st);
    cout<<Top(st);
}
