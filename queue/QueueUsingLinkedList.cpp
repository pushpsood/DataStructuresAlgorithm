//new
#include<iostream>
using namespace std;
class Queue
{
public:
    int data;
    Queue *next;
}*f=NULL,*r=NULL;
void enqueue(int x)
{
    Queue *t=new Queue;
    if(t==NULL)
    {
        cout<<"Queue is full\n";
        return;
    }
    t->data=x;
    t->next=NULL;
    if(f==NULL) f=r=t;
    else
    {
        r->next=t;
        r=t;
    }
}
int dequeue()
{
    Queue *p=f;
    if(f==NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else
    {
        f=f->next;
        int x=p->data;
        delete p;
        return x;
    }

}
void display()
{
    Queue *p=f;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    enqueue(10);
    enqueue(50);
    enqueue(100);
    enqueue(105);
    enqueue(14);
    enqueue(104);
    enqueue(105);
    display();
    cout<<endl<<dequeue();
    cout<<endl<<dequeue();
    cout<<endl<<dequeue();
    cout<<endl<<dequeue()<<endl;
    display();
}
