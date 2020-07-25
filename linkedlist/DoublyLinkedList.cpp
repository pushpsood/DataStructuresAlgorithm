#include<iostream>
using namespace std;
class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};
class Doubly
{
    Node *head;
public:
    Node * ret()
    {
        return head;
    }
    Doubly()
    {
        head=NULL;
    }
    Doubly(int A[],int s);
    void Display();
    void Insert(int,int);
};
Doubly::Doubly(int A[],int s)
{
    Node *t=new Node;
    t->data=A[0];
    t->prev=NULL;
    t->next=NULL;
    head=t;
    for(int i=1;i<s;i++)
    {
        Node *p=new Node;
        p->data=A[i];
        p->next=NULL;
        p->prev=t;
        t->next=p;
        t=p;
    }
}
void Doubly::Display()
{
    Node *p=head;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int Length(Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}
void Doubly::Insert(int index,int x)
{
    Node *p=head;
    Node *t;
    if(index<0||index>Length(p))return;
    if(index==0)
    {
        t=new Node;
        t->data=x;
        t->next=p;
        t->prev=NULL;
        p->prev=t;
        head=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)p=p->next;
        t=new Node;
        t->data=x;
        t->next=p->next;
        if(p->next)p->next->prev=t;
        p->next=t;
    }
}
int main()
{
    int A[]={12,46,13,46,61,46,6,64};
    Doubly d(A,8);
    d.Display();
    d.Insert(8,7);
    d.Display();
    d.Insert(0,5);
    d.Display();
    d.Insert(1,76);
    d.Display();
}
