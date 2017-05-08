
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

void po(node *root)
{
    if(root==NULL)
        return;

    po(root->l);
    cout<<root->x<<" ";
    po(root->r);
}

int pi=0;
int sz=5;
int a[5]={2 ,1 ,3 ,4 ,5};

node *f(int mi,int mx)
{
    if(pi>=sz)
        return NULL;
    node *root=NULL;
    if(a[pi]>=mi&&a[pi]<=mx)
    {
        root=nn(a[pi]);
        pi++;
        root->l=f(mi,a[pi]-1);
        root->r=f(a[pi],mx);
    }
    if(root==NULL)return NULL;
    return root;
}

main()
{


    struct node *root =f(INT_MIN,INT_MAX);
    po(root);
}
