#include<iostream>
#include<queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
}*root=NULL;
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
Node *Insert(Node *p,int x)
{
    if(p==NULL)
    {
        Node *t=new Node;
        t->data=x;
        t->left=NULL;
        t->right=NULL;
        return t;
    }
    else if(x>p->data)
    {
        p->right=Insert(p->right,x);
    }
    else
    {
        p->left=Insert(p->left,x);
    }
    return p;

}
void inorder(Node *p)
{
    if(p)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
    return;
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
int main()
{
    root=Insert(root,4);
    Insert(root,1);Insert(root,1022);
    Insert(root,7);Insert(root,8);
    Insert(root,54);Insert(root,64);
    Insert(root,40);
    levelorder(root);
    cout<<endl;
    inorder(root);cout<<endl;
    preorder(root);


}
