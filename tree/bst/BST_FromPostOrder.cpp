
#include<iostream>
#include<stack>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
}*root=NULL;

void inorder(Node *p)
{
    if(p)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}


void createBST(int pre[],int n)
{
    stack<Node *> st;
    Node *t,*p;
    int i=0;
    root=new Node;
    root->data=pre[i++];
    root->left=NULL;
    root->right=NULL;
    p=root;
    while(i<n)
    {
        cout<<"done";
        if(pre[i]<p->data)
        {
            t=new Node;
            t->data=pre[i++];
            t->right=NULL;
            t->left-NULL;
            p->left=t;
            st.push(p);
            p=t;
        }
        else
        {
            if((pre[i]>p->data&&pre[i]<(st.top())->data))
            {
                t=new Node;
                t->data=pre[i++];
                t->left=NULL;
                t->right=NULL;
                p->right=t;
                p=t;
            }
            else
            {
                p=st.top();
                st.pop();
            }
        }
        cout<<p->data<<" ";
    }
}
int main()
{
    int A[]={4,1,1022,7,8,54,40,64};
    createBST(A,8);
    inorder(root);
}




