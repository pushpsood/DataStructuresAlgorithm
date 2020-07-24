

#include<iostream>
#include<vector>
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

struct Node *Merge(struct Node *p,struct Node *q)
{
    struct Node *start=NULL,*r=NULL;
    if(p==NULL)return q;
    if(q==NULL)return p;
    if(p->data<q->data)
    {
        start=r=p;
        p=p->next;
        r->next=NULL;
    }
    else
    {
        start=r=q;
        q=q->next;
        r->next=NULL;
    }
    while(p&&q)
    {
        if(p->data<q->data)
        {
            r->next=p;
            r=p;
            p=p->next;
            r->next=NULL;
        }
        else
        {
            r->next=q;
            r=q;
            q=q->next;
            r->next=NULL;
        }
    }
    if(q)r->next=q;
    if(p)r->next=p;
    return start;
};

int main()
{
    struct Node *start=NULL;
    start=create(start,1);
    start=create(start,2);
    start=create(start,3);
    start=create(start,5);
    start=create(start,5);
    start=create(start,6);
    start=create(start,7);
    start=create(start,8);
    cout<<"1 : ";
    display(start);
    struct Node *start1=NULL;
    start1=create(start1,1);
    start1=create(start1,2);
    start1=create(start1,3);
    start1=create(start1,4);
    start1=create(start1,5);
    start1=create(start1,6);
    start1=create(start1,7);
    start1=create(start1,8);
    cout<<"2 : ";
    display(start1);
    start=Merge(start,start1);
    cout<<"1M2: ";
    display(start);
}
