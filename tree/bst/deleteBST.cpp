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

int height(Node *p)
{
    if(p)
    {
     return max(height(p->left),height(p->right))+1;
    }
    return 0;
}

Node *inpre(Node *p)
{
    while(p&&p->right!=NULL)
        p=p->right;
    return p;
}

Node *insucc(Node *p)
{
    while(p&&p->left!=NULL)
        p=p->left;
    return p;
}


Node *del(Node *p,int key)
{
    Node *q;
    if(p==NULL)
        return NULL;
    if(p->left==NULL&&p->right==NULL&&p->data==key)
    {
        if(p==root)
            root=NULL;
        delete p;
        return NULL;
    }
    if(key<p->data) p->left=del(p->left,key);
    else if(key>p->data) p->right=del(p->right,key);
    else
    {
        if(height(p->left)>height(p->right))
        {
            q=inpre(p->left);
            p->data=q->data;
           p->left=del(p->left,p->data);
        }
        else
        {
            q=insucc(p->right);
            p->data=q->data;
            p->right=del(p->right,p->data);

        }
    }
    return p;
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
    inorder(root);
    del(root,1022);
    cout<<endl;
    inorder(root);
}
