#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
    Node *first;
public:
    LinkedList()
    {
        first=NULL;
    }
    LinkedList(int A[],int n);
    ~LinkedList();
    void Display();
    void Insert(int index,int x);
    int Length();
};
LinkedList::LinkedList(int a[],int s)
{
    first=new Node();
    first->data=a[0];
    first->next=NULL;
    Node *t,*p=first;
    for(int i=1;i<s;i++)
    {
        t=new Node();
        t->next=NULL;
        t->data=a[i];
        p->next=t;
        p=t;
    }
}
LinkedList::~LinkedList()
{
    Node *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}
void LinkedList::Display()
{
    Node *p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int LinkedList::Length()
{
    Node *p=first;
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}
void LinkedList::Insert(int index,int x)
{
    Node *t,*p=first;
    if(index<0&&Length()<=index)
        return;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(index==0)
        {
            if(first==NULL)
            first=t;
            else
            {
                t->next=first;
                first=t;
            }
            return;
        }
    else{
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

int main()
{
    int A[]={1,915,85,96,4,23,10};
    LinkedList l(A,7);
    l.Insert(7,10);
    l.Display();
    cout<<l.Length();
}
