
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
int main()
{
    struct Node *start=NULL;
    start=create(start,1);
    start=create(start,2);
    start=create(start,3);
    start=create(start,4);
    start=create(start,5);
    start=create(start,6);
    start=create(start,7);
    start=create(start,8);
    display(start);
    start=Reverse(start);
    display(start);
}
