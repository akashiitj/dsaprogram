
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

int fold(node *l1,node *r1)
{
    if(l1==NULL&&r1==NULL)
        return 1;
    if(l1==NULL||r1==NULL)
        return 0;
    return fold(l1->l,r1->r)&&fold(l1->r,r1->l);
}

main()
{
    struct node *root = nn(1);
    root->l        = nn(2);
    root->r       = nn(3);
    root->l->l  = nn(7);
    root->l->r = nn(6);
    root->r->l  = nn(5);
   // root->r->r = nn(4);
    cout<<fold(root->l,root->r);
}
