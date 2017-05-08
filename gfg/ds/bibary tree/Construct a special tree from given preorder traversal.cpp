
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

int a[100]={1,2,3,4,5};
int b[100]={1,1,0,0,0};
int prei=0;

node *f()
{
    node *n=nn(a[prei]);
    prei++;
    if(b[prei-1]==1)
    {   prei++;
        n->l=f();
        n->r=f();
    }
    else prei++;

    return n;

}
void pr(node *n)
{
    if(n==NULL)
        return;
    cout<<n->x<<" ";
    pr(n->l);
    pr(n->r);

}

main()
{
    struct node *root =f();
    pr(root);
}
