
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

int isidentical(node *r1,node *r2)
{
    if(r1==NULL&&r2==NULL)
        return 1;
     if(r1!=NULL&&r2!=NULL)//you are forgeting it
     {
         return (r1->x==r2->x&&isidentical(r1->l,r2->l)&&isidentical(r1->r,r2->r));
     }
     return 0;
}

main()
{
    node *root=nn(1);
    root->l=nn(2);
    root->r=nn(3);
    root->l->l=nn(4);

    node *root1=nn(1);
    root1->l=nn(2);
    root1->r=nn(3);
    //root1->l->l=nn(4);

    cout<<isidentical(root,root1);
   //cout<<sizeoftree(root);
   // cout<<root->x<<" "<<root->l->x<<" "<<root->l->l->x;
}
