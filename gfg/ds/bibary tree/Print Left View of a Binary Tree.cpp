
#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *l;
    node *r;
    int x;
};

node *nn(int x1)//return new node
{
    node *n=new node;
    n->l=NULL;
    n->r=NULL;
    n->x=x1;

    return n;
}

int sizeoftree(node *root)
{
    if(root==NULL)
        return 0;
    return sizeoftree(root->l)+sizeoftree(root->r)+1;
}

int maxlreach=0;
void pleft(node *root,int l)
{
    if(root==NULL)
        return ;
    if(l>maxlreach)
    {
        cout<<root->x<<" ";
        maxlreach=l;
    }
    pleft(root->l,l+1);
    pleft(root->r,l+1);
}

main()
{
    struct node *root = nn(1);
    root->l        = nn(2);
    root->r       = nn(3);
    root->l->l  = nn(7);
    root->l->r = nn(6);
    root->r->l  = nn(5);
    root->r->r = nn(4);
    pleft(root,1);
}
