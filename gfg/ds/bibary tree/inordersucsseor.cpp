

#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *l;
    node *r;
    node *nxt;
    int x;
};

node *nn(int x1)//return new node
{
    node *n=new node;
    n->l=NULL;
    n->r=NULL;
    n->nxt=NULL;
    n->x=x1;

    return n;
}

node *pre=NULL;

void in(node *root)
{
    if(root==NULL)
        return;
    in(root->l);
    if(pre!=NULL)
        pre->nxt=root;
    pre=root;

    in(root->r);
}


main()
{
    struct node *root = nn(1);
    root->l        = nn(2);
    root->r       = nn(3);
    root->l->l  = nn(7);
    root->l->r = nn(6);
    root->r->l  = nn(5);
    node *n=root->l->l;

    in(root);

    node*  n1= root->l->l ;

    while(n1!=NULL)
    {
        cout<<n1->x<<" ";
        n1=n1->nxt;
    }


}

