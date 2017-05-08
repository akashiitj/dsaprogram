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

int check(node *root)
{
    if(root==NULL||(root->l==NULL&&root->r==NULL))
        return 1;
    int sum=0;
    if(root->l!=NULL)
        sum=sum+root->l->x;
    if(root->r!=NULL)
        sum=sum+root->r->x;
    if(sum==root->x&&check(root->l)&&check(root->r))
        return 1;
    return 0;

}

main()
{
    struct node *root  = nn(10);
    root->l        = nn(8);
    root->r        = nn(2);
    root->l->l   = nn(3);
    root->l->r  = nn(5);
    root->r->r = nn(2);
    cout<<check(root);
}
