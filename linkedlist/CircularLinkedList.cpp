#include<iostream>
using namespace std;
class Node
{
public:
   int data;
   Node *next;
};
class Circular
{
    Node *head;
public:
    Circular(int A[],int x);
    void Display();
    void Insert(int pos,int x);
    int Delete(int pos);
};
Circular::Circular(int A[],int x)
{
    head=new Node;
    head->data=A[0];
    head->next=head;
    Node *ptr=head;
    Node *t;
    for(int i=1;i<x;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=head;
        ptr->next=t;
        ptr=t;
    }
}
void Circular::Display()
{
    if(head==NULL) return;
    if(head->next==head)
    {
        cout<<head->data<<" "<<endl;
        return;
    }
    Node *p=head;
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}
int Length(Node *p)
{
    Node *z=p;
    int len=0;
    do
    {
        p=p->next;
        len++;
    }while(p!=z);
    return len;
}
void Circular::Insert(int index,int x)
{
    struct Node *p=head;
    struct Node *t;
    int i;
    if(index==0)
    {
        t=new Node;
        t->data=x;
        if(head==NULL)
        {
            head=t;
            t->next=head;
        }
        else
        {
            while(p->next!=head)p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }
        return;
    }
    if(index<=0||index>Length(head))
        return;

        for(int i=0;i<index-1;i++)p=p->next;
        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
}
int Circular::Delete(int pos)
{
    int x;
    if(pos<0||pos>Length(head))
        return -1;

    Node *p=head;
    if(pos==1)
    {
        while(p->next!=head)p=p->next;
        x=head->data;
        if(p==head)
        {
            delete head;
            head=NULL;
            return x;
        }
        p->next=head->next;
        delete head;
        head=p->next;
        return x;
    }
    else{
    for(int i=0;i<pos-2;i++)p=p->next;
    Node *q=p->next;
    x=q->data;
    p->next=q->next;
    delete q;
    return x;}
}
int main()
{
    int A[]={1,5,9,88,785,4598};
    Circular c(A,6);
    c.Display();
    c.Insert(0,233);
    cout<<endl;
    c.Display();
    c.Insert(7,233);
    cout<<endl;
    c.Display();
    c.Insert(4,239);
    cout<<endl;
    c.Display();
    cout<<endl<<c.Delete(9);
    cout<<endl;
    c.Display();
}
