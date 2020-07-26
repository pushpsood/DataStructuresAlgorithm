#include<iostream>
using namespace std;
class Stack
{
public:
    int data;
    Stack *next;
}*head=NULL;

void Display()
{
    Stack *p=head;
    while(p)
        {cout<<p->data<<" ";
        p=p->next;}
    cout<<endl;
}
void push(int x)
{
    Stack *t=new Stack;
    if(t==NULL)
        return;
    t->data=x;
    t->next=head;
    head=t;
}
int pop()
{
    Stack *p=head;
    if(head==NULL)
        return -1;
    else
    {
        head=p->next;
        int x=p->data;
        delete p;
        return x;
    }
}
int peek(int index)
{
    Stack *p=head;
    for(int i=0;p!=NULL&&i<index-1;i++)
        p=p->next;
    if(p)
    {
        return p->data;
    }
    return -1;
}
int isEmpty()
{
    if(head)
        return 0;
    return 1;
}
int isFull()
{
    Stack *t=new Stack;
    if(t==NULL)
        return 1;
    delete t;
    return 0;
}
int Top()
{
    if(head)
        return head->data;
    return -1;
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    Display();
    cout<<endl<<pop();
    cout<<endl<<pop();
    cout<<endl<<pop()<<endl;
    Display();
    cout<<Top();
    cout<<endl<<peek(2);
    cout<<endl<<pop();
    cout<<endl<<pop();
    cout<<endl<<isFull()<<endl;
    cout<<isEmpty();
}
