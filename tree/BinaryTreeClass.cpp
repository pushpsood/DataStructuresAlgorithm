#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public:
    int data;
    Node *right;
    Node *left;
};
class Tree
{
public:
    Node *root;
    Tree(){root=NULL;}
    void create();
    void preorder(Node *);
    void postorder(Node *);
    void inorder(Node *);
    void levelorder(Node *);
    int height(Node *);
};
void Tree::create()
{
    Node *p,*t;
    int x;
    queue<Node *> q;
    cout<<"Enter root value: ";
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
void Tree::preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}
void Tree::postorder(Node *p)
{
    if(p)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<" ";
    }
}
void Tree::inorder(Node *p)
{
    if(p)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}
int Tree::height(Node *p)
{
    int x=0,y=0;
    if(p==NULL)
        return -1;
    x=1+height(p->left);
    y=1+height(p->right);
    return max(x,y);
}
void Tree::levelorder(Node *p)
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
    Tree t;
    t.create();
    cout<<endl<<"Height: "<<t.height(t.root)<<endl;
    cout<<"PreOrder\n";
    t.preorder(t.root);
    cout<<"\nPostOrder\n";
    t.postorder(t.root);
    cout<<"\nInOrder\n";
    t.inorder(t.root);
    cout<<"\nLevelOrder\n";
    t.levelorder(t.root);
}
