#include<iostream>
#include<stack>
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
void InterSect(struct Node *p,struct Node *q)
{
    while(p->next)
        p=p->next;
    while(q->next)
        q=q->next;
    q->next=p;
}
struct Node *FindIntersect(struct Node *p,struct Node *q)
{
    stack<struct Node *> s1;
    stack<struct Node *> s2;
    while(p)
    {
        s1.push(p);
        p=p->next;
    }
    while(q)
    {
        s2.push(q);
        q=q->next;
    }
    struct Node *last;
    while(s1.top()==s2.top())
    {
        last=s1.top();
        s1.pop();
        s2.pop();
        if(s1.empty()||s2.empty())
            return NULL;
    }
    return last;
}
int main()
{
    struct Node *start=NULL;
    struct Node *start2=NULL;
    start2=create(start2,52);
    start2=create(start2,45);
    start2=create(start2,20);
    start2=create(start2,40);
    start2=create(start2,55);
    start=create(start,1);
    start=create(start,2);
    start=create(start,3);
    start=create(start,4);

    InterSect(start,start2);

    start=create(start,5);
    start=create(start,6);
    start=create(start,7);
    start=create(start,8);
    display(start);
    display(start2);
    struct Node *i=FindIntersect(start,start2);
    cout<<endl<<endl<<"Common Element: "<<i->data<<"\nLocation: "<<i;

}
