
#include<iostream>
using namespace std;
template<class T>
class Node
{
public:
    T data;
    Node *next;
};
template<class T>
class LinkedList
{
    Node<T> *first;
public:
    LinkedList()
    {
        first=NULL;
    }
    LinkedList(T A[],int n);
    ~LinkedList();
    void Display();
    void Insert(int index,int x);
    int Length();
};
template<class T>
LinkedList<T>::LinkedList(T a[],int s)
{
    first=new Node<T>();
    first->data=a[0];
    first->next=NULL;
    Node<T> *t,*p=first;
    for(int i=1;i<s;i++)
    {
        t=new Node<T>();
        t->next=NULL;
        t->data=a[i];
        p->next=t;
        p=t;
    }
}
template<class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}
template<class T>
void LinkedList<T>::Display()
{
    Node<T> *p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
template<class T>
int LinkedList<T>::Length()
{
    Node<T> *p=first;
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}
template<class T>
void LinkedList<T>::Insert(int index,int x)
{
    Node<T> *t,*p=first;
    if(index<0&&Length()<=index)
        return;
    t=new Node<T>;
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

    char A[]={1,56,85,96,4,23,10};
    LinkedList<char> l(A,7);
    l.Insert(7,10);
    l.Display();
    cout<<l.Length();
}
