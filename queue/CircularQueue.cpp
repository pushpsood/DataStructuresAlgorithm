//new
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
    q->f=q->r=0;
    q->Q=new int[s];
}

void enqueue(Queue *q,int x)
{
    if((q->r+1)%q->s==q->f)
        cout<<"Queue is full\n";
    else{
            q->r=(q->r+1)%q->s;
    q->Q[q->r]=x;}
}
int dequeue(Queue *q)
{
    int x=-1;
    if(q->r==q->f)
        cout<<"Queue is Empty\n";
    else
    {
        x=q->Q[q->f];
        q->f=(q->f+1)%q->s;
    }
    return x;
}
void display(Queue q)
{
    if(q.r==q.f)
        return;
    int i=(q.f+1)%q.s;
    do{
        cout<<q.Q[i]<<" ";
        i=(i+1)%q.s;
    }while(i!=((q.r+1)%q.s));
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
    cout<<dequeue(&q)<<endl;
    cout<<dequeue(&q)<<endl;
    cout<<dequeue(&q)<<endl;
    display(q);
}
