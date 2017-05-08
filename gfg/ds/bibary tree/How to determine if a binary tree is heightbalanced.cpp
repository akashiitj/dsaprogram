
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

int ifb(node *root,int *h)
{
    if(root==NULL)
    {
        *h=0;
        return 1;
    }

    int lh=0,rh=0;
    int isl=ifb(root->l,&lh);
    int isr=ifb(root->r,&rh);
    *h=max(lh+1,rh+1);
    if(abs(lh-rh)>=2)return 0;
    return (isl&&isr);
}

main()
{
    struct node *root = nn(1);
    root->l        = nn(2);
    root->r       = nn(3);
    root->l->l  = nn(7);
    root->l->r = nn(6);
    root->r->r  = nn(5);
    root->r->l = nn(4);
    int h;
  cout<<ifb(root,&h);
}
