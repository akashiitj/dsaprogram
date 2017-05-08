#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *l;
    node *r;
    node *rndm;
    int x;
};

node *nn(int x1)//return new node
{
    node *n=new node;
    n->l=NULL;
    n->r=NULL;
    n->rndm=NULL;
    n->x=x1;

    return n;
}

node *maptree(node *root,map<node *,node *> &m)
{
    if(root==NULL )
        return NULL;
    node *n=nn(root->x);
    m[root]=n;

    n->l=maptree(root->l,m);
    n->r=maptree(root->r,m);

    return n;
}

void randomp(node *root,node *clone,map<node *,node *> m)
{
    if(root==NULL)return;
    if(root->rndm!=NULL)
        clone->rndm=m[root->rndm];//m[root->rndm] is pointing to the new node that we have created
    randomp(root->l,clone->l,m);
    randomp(root->r,clone->r,m);
}

node *f(node *root)
{
    map<node *,node *> m;
    node *clone= maptree(root,m);
    randomp(root,clone,m);
    return clone;
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


    node *clone=f(root);

    while(clone!=NULL)
    {
        cout<<clone->x<<" ";
        clone=clone->l;
    }

}
