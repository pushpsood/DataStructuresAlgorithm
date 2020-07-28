
#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public:
    int data;
    Node *right;
    Node *left;
}*root=NULL;
void create()
{
    Node *p,*t;
    int x;
    queue<Node *> q;
    cout<<"Enter root value";
    cin>>x;
    root=new Node;
    root->data=x;
    root->right=NULL;
    root->left=NULL;
    q.push(root);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        cout<<"Enter the left child of "<<p->data<<" (-1=NULL): ";
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->left=NULL;
            t->right=NULL;
            t->data=x;
            p->left=t;
            q.push(t);
        }
        cout<<"Enter the right child of "<<p->data<<" (-1=NULL): ";
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->left=NULL;
            t->right=NULL;
            t->data=x;
            p->right=t;
            q.push(t);
        }
    }
}
bool RBST(Node *p,int x)
{
    if(p==NULL)
        return false;
    if(p->data==x)
        return true;
    if(x<p->data)
        RBST(p->left,x);
    else
        RBST(p->right,x);
}

int main()
{
    int x;
    create();
    cout<<"Enter Element to Find";
    cin>>x;
    cout<<endl;
    if(RBST(root,x)) cout<<x<<" Found";
    else cout<<x<<" Not Found";
}
