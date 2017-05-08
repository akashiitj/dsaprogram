#include<bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    node *l;
    node *r;
};

struct ans//strore information necessary for calculation at each step in post order fasion it fills information of each node
{
    int isbst;
    int sz;
    int mi;
    int mx;
};

node *nn(int key)
{
    node *n=new node;
    n->x=key;
    n->l=NULL;
    n->r=NULL;
    return n;
}

node* insrt(node *root,int key)
{
    if(root==NULL)
    {
        return nn(key);
    }
    if(key>=root->x)
        root->r=insrt(root->r,key);

    if(key<root->x)
        root->l=insrt(root->l,key);

    return root;//except inserted node whosever call root usko root return kar do
}

ans lbst(node *root)
{
    ans pn;
    if(root==NULL)
    return pn={1,0,INT_MAX,INT_MIN};//to get clear idea consider leaf node

    ans l=lbst(root->l);
    ans r=lbst(root->r);

    if(l.isbst==0||r.isbst==0||l.mx>root->x||r.mi<root->x)
    {
        pn.isbst=0;
        pn.sz=max(l.sz,r.sz);//size store abhi tak ke largest bst that is subtree of pn ki size
        return pn;
    }
    pn.isbst=1;
    pn.sz=1+l.sz+r.sz;
    pn.mi= root->l != NULL ? l.mi : root->x;
    pn.mx= root->r != NULL ? r.mx : root->x;

    return pn;

}


main()
{
    node *root=NULL;
    if(root==NULL)root=insrt(root,50);
    insrt(root, 30);
    root->r=nn(40);

    ans fa=lbst(root);
    cout<<fa.sz;
}

