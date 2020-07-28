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
void preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(Node *p)
{
    if(p)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<" ";
    }
}
void inorder(Node *p)
{
    if(p)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}
int main()
{
    create();
    cout<<"PreOrder\n";
    preorder(root);
    cout<<"\nPostOrder\n";
    postorder(root);
    cout<<"\nInOrder\n";
    inorder(root);
}
