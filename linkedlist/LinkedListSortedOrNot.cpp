
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
int IsSort(struct Node *p,int x)
{
    if(p==NULL)
        return 1;
    if(p->data>=x)
        return IsSort(p->next,p->data);
    return 0;

}
int main()
{
    struct Node *start=NULL;
    start=create(start,20);
    start=create(start,2);
    start=create(start,3);
    start=create(start,4);
    start=create(start,5);
    start=create(start,6);
    start=create(start,7);
    start=create(start,10);
    if(IsSort(start,INT_MIN))cout<<"Sorted"<<endl;
    else cout<<"Not Sorted"<<endl;
    display(start);
}
