#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *create(struct Node *start,int x)
{
    if(start==NULL)
        {
            struct Node *n=new struct Node();
            n->data=x;
            n->next=NULL;
            start=n;
            return start;
        }
    struct Node *s=start;
    while(s->next!=NULL)
        s=s->next;
    struct Node *n=new struct Node();
    n->data=x;
    n->next=NULL;
    s->next=n;
    return start;
}
void display(struct Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void RDup(struct Node *p)
{
    struct Node *q=p->next;
    while(q)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=q->next;
        }
    }
}
int main()
{
    struct Node *start=NULL;
    start=create(start,1);
    start=create(start,1);
    start=create(start,2);
    start=create(start,2);
    start=create(start,2);
    start=create(start,2);
    start=create(start,7);
    start=create(start,7);
    cout<<"Before: ";
    display(start);
    RDup(start);
    cout<<"After: ";
    display(start);
}
