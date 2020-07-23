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
int Sum(struct Node *p)
{
    if(p==NULL)
        return 0;
    return p->data+Sum(p->next);
}
int Count(struct Node *p)
{
    if(p==NULL)
        return 0;
    return Count(p->next)+1;
}
int Search(struct Node *p,int x)
{
    static int s=0;
    s++;
    if(p->data==x)
        return s;
    else if(p==NULL)
        return 0;
    Search(p->next,x);
}
int Min(struct Node *p)
{
    int x=0;
    if(p==NULL)
        return INT_MAX;
    x=Min(p->next);
    return x<p->data?x:p->data;
}
int Max(struct Node *p)
{
    int x=0;
    if(p==NULL)
        return INT_MIN;
    x=Max(p->next);
    return x>p->data?x:p->data;
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
    cout<<"Sum: "<<Sum(start)<<endl;
    cout<<"No of terms: "<<Count(start)<<endl;
    cout<<"Enter element to search"<<endl;
    int x;
    cin>>x;
    int p;
    if(p=Search(start,x))
    cout<<"Found at position "<<p;
    else
        cout<<"Not Found";
    cout<<endl;
    cout<<"Minimum: "<<Min(start)<<endl;
    cout<<"Minimum: "<<Max(start)<<endl;
}
