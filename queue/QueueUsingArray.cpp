#include<iostream>
using namespace std;
class Queue
{
public:

    int s;
    int f;
    int r;
    int *Q;
};
void create(Queue *q,int s)
{
    q->s=s;
    q->f=q->r=-1;
    q->Q=new int[s];
}
void enqueue(Queue *q,int x)
{
    if(q->r==q->s-1)
        cout<<"Queue is full\n";
    else{
    q->r++;
    q->Q[q->r]=x;}
}
int dequeue(Queue *q)
{
    int x=-1;
    if(q->r==q->f)
        cout<<"Queue is full\n";
    else
    {
        q->f++;
        x=q->Q[q->f];
    }
    return x;
}
void display(Queue q)
{
    for(int i=q.f+1;i<=q.r;i++)
    {
        cout<<q.Q[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    Queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,40);
    enqueue(&q,1);
    cout<<endl;
    display(q);
    cout<<dequeue(&q)<<endl;
    display(q);
}
