
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

void mirror(node *root)
{
    if(root==NULL)
        return;
    mirror(root->l);
    mirror(root->r);

    node *n=root->l;
    root->l=root->r;
    root->r=n;
}
main()
{
    node *root=nn(1);
    root->l=nn(2);
    root->r=nn(3);
    root->l->l=nn(4);
    mirror(root);
    //cout<<root->x<<" "<<root->r->x<<" "<<root->r->r->x;
}
