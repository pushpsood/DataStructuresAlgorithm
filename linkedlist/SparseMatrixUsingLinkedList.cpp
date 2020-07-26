#include<iostream>
using namespace std;
struct Node
{
    int col;
    int val;
    Node *next;
};
int main()
{
    int m,n;
    cout<<"Enter the dimensions\n";
    cin>>m>>n;
    struct Node *A[m];
    for(int i=0;i<m;i++)
        {
            A[i]=new Node;
            A[i]=NULL;
        }
    int t;
    cout<<"No of elements you want to input";
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int p,q,d;
        cin>>p>>q>>d;
        struct Node *t=new Node;

        if(A[p]==NULL)
        {
        t->col=q;
        t->val=d;
        t->next=NULL;
        A[p]=t;
        }

        else{
         struct Node *k=A[p];
         while(k->next)k=k->next;
         t->val=d;
         t->col=q;
         t->next=NULL;
         k->next=t;
        }
    }
    for(int i=0;i<m;i++)
    {
        struct Node *k=A[i];
        for(int j=0;j<n;j++)
        {
            if(k==NULL)
                cout<<"0 ";
            else if(k->col==j)
            {
                cout<<k->val<<" ";
                k=k->next;
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}
