#include<iostream>
using namespace std;
class Queue
{
public:
    int data;
    Queue *next;
}*f=NULL,*r=NULL;
void enqueue_rear(int x)
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
void enqueue_front(int x)
{
    Queue *t=new Queue;
    if(t==NULL)
    {
        cout<<"Queue is full\n";
        return;
    }
    t->data=x;
    t->next=f;
    if(r==NULL) f=r=t;
    else
    {
        f=t;
    }
}
int dequeue_front()
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
int dequeue_rear()
{
    Queue *p=f;
     Queue *q=f;
    if(r==NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    else
    {
        while(p->next){
            q=p;
            p=p->next;
        }
        q->next=NULL;
        int x=p->data;
        if(f==p)f=r=NULL;
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
    enqueue_rear(10);
    enqueue_rear(50);
    enqueue_front(100);
    enqueue_front(105);
    enqueue_rear(14);
    enqueue_front(104);
    enqueue_rear(105);
    display();
    cout<<endl<<dequeue_front();
    cout<<endl<<dequeue_rear();
    cout<<endl<<dequeue_rear();
    cout<<endl<<dequeue_rear()<<endl;
    display();
}
