#include<iostream>
#include<queue>
#include<stack>
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
    stack<Node *> st;
    while(!st.empty()||p!=NULL)
    {
        if(p)
        {
            cout<<p->data<<" ";
            st.push(p);
            p=p->left;
        }
        else
        {
            p=st.top();
            st.pop();
            p=p->right;
        }
    }
}
void postorder(Node *p)
{
   stack<Node *> st;
   long int temp;
    while(!st.empty()||p!=NULL)
    {
        if(p)
        {
            st.push(p);
            p=p->left;
        }
        else
        {
           Node *k=st.top();
           temp=(int)k;
            st.pop();
            if(temp>0){
            st.push((Node *)-temp);
            p=((Node *)temp)->right;
            }
            else
            {
                cout<<((Node *)-temp)->data<<" ";
                p=NULL;
            }
        }
    }
}
void inorder(Node *p)
{
    stack<Node *> st;
    while(!st.empty()||p!=NULL)
    {
        if(p)
        {
            st.push(p);
            p=p->left;
        }
        else
        {
            p=st.top();
            st.pop();
            cout<<p->data<<" ";
            p=p->right;
        }
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
