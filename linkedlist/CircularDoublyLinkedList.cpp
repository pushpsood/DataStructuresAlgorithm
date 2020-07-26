#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
}*head=NULL;
void Create()
{
    Node *p=head,*t;
    int z;
    cout<<"How many elements\n";
    cin>>z;
    for(int i=0;i<z;i++)
    {
        int val;
        cin>>val;
        t=new Node;
        t->data=val;
        t->next=NULL;
        if(head==NULL)
        {
            head=t;
            t->prev=NULL;
        }
        else
        {
            t->prev=p;
            p->next=t;
        }
        p=t;
    }
    p->next=head;
    head->prev=p;
}
void Display()
{
    Node *p=head;
    if(p==NULL)
        return;
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}
int main()
{
    Create();
    Display();
}
