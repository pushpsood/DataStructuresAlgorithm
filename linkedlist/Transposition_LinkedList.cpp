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
struct Node *LSearch(struct Node *p,int key)
{
    struct Node *q;
    while(p!=NULL)
    {
        if(key==p->data)
          {
             q->next=p->next;
             return p;
          }
        q=p;
        p=p->next;
    }
    return NULL;
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
    int n=0;
    display(start);
    cout<<"\nHow many elements you want to search"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
     {
         int ele;
         cin>>ele;
         struct Node *p=LSearch(start,ele);
         if(p)
            {
                cout<<"Found\n";
                p->next=start;
                start=p;
            }
         else
         cout<<"Not Found\n";
     }
    display(start);
}

