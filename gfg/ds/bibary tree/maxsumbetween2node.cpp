
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

int summ(node *root,int &sum)
{
    if(root==NULL)
        return 0;
    int ls=summ(root->l,sum);
    int rs=summ(root->r,sum);
    sum=max(sum,ls+rs+root->x);
    return (max(ls,rs)+root->x);
}

main()
{
    struct node *root = nn(5);
    root->l        = nn(2);
    root->r       = nn(3);
    root->l->l  = nn(7);
    root->l->r = nn(6);
    root->r->l  = nn(5);
    root->r->r = nn(4);
    int ans=0;
    summ(root,ans);
    cout<<ans;
}

