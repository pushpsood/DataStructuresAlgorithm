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
    if(p==NULL)
        cout<<"Empty";
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

struct Node *Delete(struct Node *p,int pos)
{

    struct Node *start=p;
    struct Node *q=p;
    if(p==NULL)
        return NULL;
    while(p&&pos-1)
    {
        pos--;
        q=p;
        p=p->next;
    }
    if(pos-1)
        return start;
    if(start==p)
    {
        start=NULL;
        if(p->next)
        start=p->next;
        delete p;
        return start;
    }
    if(p){
    q->next=p->next;
    delete p;
    return start;}
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
    start=Delete(start,5);
    start=Delete(start,7);
    start=Delete(start,1);
    start=Delete(start,100);
    start=Delete(start,-1);
    display(start);
}
