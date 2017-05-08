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

int hgt(node *root)
{
    if(root==NULL)
        return 0;
    int lh=hgt(root->l);
    int rh=hgt(root->r);

    return max(lh,rh)+1;
;}

main()
{
    node *root=nn(1);
    root->l=nn(2);
    root->r=nn(3);
    root->l->l=nn(4);
    cout<<hgt(root);
   // cout<<root->x<<" "<<root->l->x<<" "<<root->l->l->x;
}
