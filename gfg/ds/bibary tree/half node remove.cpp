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

node *f(node* root)
{
    if(root->l==NULL&&root->r==NULL)
        return root;
    if(root->l==NULL)
    {
        return f(root->r);
    }
    else if(root->r==NULL)
        return f(root->l);
    root->l=f(root->l);
    root->r=f(root->r);

    return root;
}

void po(node *root)
{
    if(root==NULL)
        return;
    cout<<root->x<<" ";
    po(root->l);
    po(root->r);
}

main()
{
    struct node *root = nn(1);
    root->l        = nn(2);
    root->r       = nn(3);
    //root->l->l  = nn(7);
    root->l->r = nn(6);
    root->r->l  = nn(5);
   // root->r->r = nn(4);

    root=f(root);
    po(root);

}

