
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
void BST(Node *p,int x)
{
    Node *r=NULL;
    while(p)
    {
    if(p->data==x)
        return;
    if(x<p->data){
        r=p;
        p=p->left;
    }
    else{
        r=p;
        p=p->right;
    }
    }
    Node *t=new Node;
    t->data=x;
    t->left=NULL;
    t->right=NULL;
    if(x<r->data)r->left=t;
    else r->right=t;
}
void levelorder(Node *p)
{
    queue<Node *> q;
    q.push(p);
    cout<<p->data<<" ";
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        if(p->left)
        {
            cout<<p->left->data<<" ";
            q.push(p->left);
        }
        if(p->right)
        {
            cout<<p->right->data<<" ";
            q.push(p->right);
        }
    }
}
int main()
{
    int x;
    create();
    cout<<"Enter Element to Insert";
    cin>>x;
    cout<<endl;
    BST(root,x);
    cout<<endl;
    levelorder(root);
}
