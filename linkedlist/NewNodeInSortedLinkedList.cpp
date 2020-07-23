
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
struct Node *InsertS(struct Node *p,int x)
{
    struct Node *t=new struct Node();
    if(p==NULL)
    {
        t->next=NULL;
        t->data=x;
        return t;
    }
    struct Node *start=p;
    struct Node *q;
    while(p&&p->data<x)
    {
        q=p;
        p=p->next;
    }
    if(p==start)
    {
        t->data=x;
        t->next=p;
        return t;
    }
    t->data=x;
    t->next=p;
    q->next=t;
    return start;
};
int main()
{
    struct Node *start=NULL;
    start=create(start,1);

    start=create(start,3);
    start=create(start,4);
    start=create(start,5);
    start=create(start,6);
    start=create(start,7);
    start=create(start,8);
    start=InsertS(start,0);
    start=InsertS(start,100);
    display(start);
}
