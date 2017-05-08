
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

int sum;
int haspath(node *root,int psum)
{
    if(root==NULL)
        return 0;
    psum=psum+root->x;
    if(root->l==NULL&&root->r==NULL)
    {
        if(psum==sum)
            return 1;
        return 0;
    }
    return haspath(root->l,psum)||haspath(root->r,psum);

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
    cin>>sum;
    cout<<haspath(root,0);
}
