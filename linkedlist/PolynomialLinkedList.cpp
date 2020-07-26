#include<iostream>
#include<math.h>
using namespace std;
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
}*poly=NULL;
void Create()
{
    struct Node *t,*p;
    int num,i;
    cout<<"No of terms";
    cin>>num;
    cout<<"Enter Coeff, Exp\n";
    for(int i=0;i<num;i++)
    {
        int c,e;
        cin>>c>>e;
        t=new Node;
        t->coeff=c;
        t->exp=e;
        t->next=NULL;
        if(poly==NULL){
        poly=t;
        p=poly;
        p->next=NULL;
        }
        else
        {
            p->next=t;
            p=t;
        }
    }
}
void Display()
{
    struct Node *p=poly;
    while(p)
    {
        cout<<p->coeff<<".x^"<<p->exp<<" + ";
        p=p->next;
    }
    cout<<"0"<<endl;
}
long Eval(int x)
{
    long sum=0.0;
    struct Node *p=poly;
    while(p)
    {
        sum+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return sum;
}
int main()
{
    Create();
    Display();
    int x;
    cin>>x;
    cout<<Eval(x);
}
