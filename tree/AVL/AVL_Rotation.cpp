#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    int h;
    Node *left;
}*root=NULL;

int NodeHeight(Node *p)
{
    int hl,hr;
    hl=p&&p->left?p->left->h:0;
    hr=p&&p->right?p->right->h:0;
    return max(hl,hr)+1;
}

int BalanceFactor(Node *p)
{
    int hl,hr;
    hl=p&&p->left?p->left->h:0;
    hr=p&&p->right?p->right->h:0;
    return hl-hr;
}


Node *RRRotation(Node *p)
{
    Node *pr=p->right;
    Node *prr=pr->right;

    p->right=pr->left;
    pr->left=p;

    p->h=NodeHeight(p);
    pr->h=NodeHeight(pr);

    if(p==root)
        root=pr;
    return pr;
}

Node *LLRotation(Node *p)
{
    Node *pl=p->left;
    Node *plr=pl->right;

    pl->right=p;
    p->left=plr;

    p->h=NodeHeight(p);
    pl->h=NodeHeight(pl);

    if(p==root)
        root=pl;
    return pl;
}


Node *RLRotation(Node *p)
{
    Node *pr=p->right;
    Node *prl=pr->left;

    pr->left=prl->right;
    p->right=prl->left;

    prl->left=p;
    prl->right=pr;

    pr->h=NodeHeight(pr);
    p->h=NodeHeight(p);
    prl->h=NodeHeight(prl);

    if(p==root)
        root=prl;
    return prl;
}


Node *LRRotation(Node *p)
{
    Node *pl=p->left;
    Node *plr=pl->right;

    pl->right=plr->left;
    p->left=plr->right;

    plr->left=pl;
    plr->right=p;

    pl->h=NodeHeight(pl);
    p->h=NodeHeight(p);
    plr->h=NodeHeight(plr);


    if(p==root)
        root=plr;
    return plr;
}


Node *RInsert(Node *p,int key)
{
    if(p==NULL)
    {
        Node *t=new Node;
        t->data=key;
        t->h=1;
        t->left=NULL;
        t->right=NULL;
        return t;
    }
    if(key<p->data) p->left=RInsert(p->left,key);
    else if(key>p->data) p->right=RInsert(p->right,key);
    p->h=NodeHeight(p);

    if(BalanceFactor(p)==2&&BalanceFactor(p->left)==1)
        return LLRotation(p);
    if(BalanceFactor(p)==2&&BalanceFactor(p->left)==-1)
        return LRRotation(p);
    if(BalanceFactor(p)==-2&&BalanceFactor(p->right)==-1)
        return RRRotation(p);
    if(BalanceFactor(p)==-2&&BalanceFactor(p->right)==1)
        return RLRotation(p);

    return p;
}

void Preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Preorder(p->left);
        Preorder(p->right);
    }
}

int main()
{
    root=RInsert(root,10);
    RInsert(root,20);
    RInsert(root,30);
    RInsert(root,25);
    RInsert(root,28);
    RInsert(root,27);
    RInsert(root,5);

    Preorder(root);

}
