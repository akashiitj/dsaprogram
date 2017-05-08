
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

int level(node *root,int key,int pl)
{
    if(root==NULL)return -1;
    if(root->x==key)
        return pl;
    int l=level(root->l,key,pl+1);
    int r=level(root->r,key,pl+1);

    if(l==r&&l==-1)
        return -1;
    if(l==-1)return r;
    if(r==-1)return l;


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

    cout<<level(root,1,1)<<"\n";
   cout<<level(root,7,1);

}
