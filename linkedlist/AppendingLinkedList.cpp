
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
struct Node *Reverse(struct Node *p)
{
    struct Node *start=p;
    struct Node *r=NULL;
    struct Node *q=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    start=q;
    return start;
}
struct Node *Append(struct Node *p,struct Node *q)
{
    if(p==NULL)
        return q;
    struct Node *start=p;
    while(p->next)
        p=p->next;
    p->next=q;
    return start;
};
int main()
{
    struct Node *start=NULL;
    start=create(start,89);
    start=create(start,74);
    start=create(start,32);
    start=create(start,45);
    start=create(start,65);
    start=create(start,26);
    start=create(start,127);
    start=create(start,48);
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
    start=Append(start,start1);
    cout<<"1+2: ";
    display(start);
}
