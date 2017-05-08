
#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *l;
    node *r;
    int x;
    int h;
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
    return root->h=(max(hgt(root->l),hgt(root->r))+1);
}

int ans=1;

int f(node *root)
{
    if(root==NULL)
        return 0;
    int h1=f(root->l);
    int h2=f(root->r);

    ans=max(ans,h1+h2+1);

    return max(h1,h2)+1;
}

main()
{
    struct node *root = nn(1);
    root->l        = nn(2);
    root->r       = nn(3);
    root->l->l  = nn(7);
    root->l->r = nn(6);
    root->l->l->l = nn(6);
      root->l->r->r = nn(6);
     root->r->l  = nn(5);
    root->r->l->r = nn(4);
    f(root);
    cout<<ans<<"\n";



}
