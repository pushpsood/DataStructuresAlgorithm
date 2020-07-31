 #include<iostream>
 using namespace std;
 class Node
 {
 public:

     int data;
     Node *next;
 };

Node * SortedInsert(Node *p,int x)
{
    if(p==NULL)
    {
        Node *t=new Node;
        t->data=x;
        t->next=NULL;
        p=t;
        return p;
    }
    Node *a=p;
    Node *q;
    while(p&&(p->data)<x)
    {
        q=p;
        p=p->next;
    }
    Node *t=new Node;
    t->data=x;
    t->next=q->next;
    q->next=t;
    return a;
}

Insert(Node *A[],int data)
{
    int adr=data%10;
    A[adr]=SortedInsert(A[adr],data);
}

int main()
{
    Node *A[10];
    for(int i=0;i<10;i++)
        A[i]=NULL;
    Insert(A,10);
    Insert(A,78);
    Insert(A,15);
    Insert(A,12);
    Insert(A,102);
    Insert(A,102);
    Insert(A,102);
    Insert(A,50);
    Insert(A,150);
    Insert(A,70);
    Insert(A,30);

    for(int i=0;i<10;i++)
    {
        Node *p=A[i];
        while(p)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}
