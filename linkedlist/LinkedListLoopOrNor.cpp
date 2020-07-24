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
void Reverse(struct Node *p)
{
    struct Node *start=p;
    vector<int> v;
    while(p)
    {
        v.push_back(p->data);
        p=p->next;
    }
    p=start;
    int i=v.size()-1;
    while(p)
    {
        p->data=v[i--];
        v.pop_back();
        p=p->next;
    }
}
bool isLoop(struct Node *p)
{
    struct Node *q=p;
    do{
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL;
    }while(q&&p&&p!=q);
    if(p==q)
        return true;
    return false;
}
void MakeLoop(struct Node *p)
{
    struct Node *temp=p;
    for(int i=0;i<2;i++)
    {
        p=p->next;
    }
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=p;
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
    MakeLoop(start);
    if(isLoop(start))cout<<"Loop";
    else cout<<"No Loop";

}
