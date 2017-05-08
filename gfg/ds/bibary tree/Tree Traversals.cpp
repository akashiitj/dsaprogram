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

void preo(node *root)
{
    if(root==NULL)
        return;
    cout<<root->x<<" ";
    preo(root->l);
    preo(root->r);
}

void ino(node *root)
{
    if(root==NULL)
        return;
    ino(root->l);
    cout<<root->x<<" ";
    ino(root->r);
}

void psto(node *root)
{
    if(root==NULL)
        return;
    psto(root->l);
    psto(root->r);
    cout<<root->x<<" ";
}

main()
{
    node *root=nn(1);
    root->l=nn(2);
    root->r=nn(3);
    root->l->l=nn(4);
    preo(root);
    cout<<"\n";
    ino(root);
    cout<<"\n";
    psto(root);
    cout<<"\n";

    // cout<<root->x<<" "<<root->l->x<<" "<<root->l->l->x;
}
