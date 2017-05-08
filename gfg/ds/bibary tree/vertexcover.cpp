
#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *l;
    node *r;
    int x;
    int dp;
};

node *nn(int x1)//return new node
{
    node *n=new node;
    n->l=NULL;
    n->r=NULL;
    n->x=x1;
    n->dp=-1;

    return n;
}

int sizeoftree(node *root)
{
    if(root==NULL)
        return 0;
    return sizeoftree(root->l)+sizeoftree(root->r)+1;
}

int vc(node *root)
{
    if(root==NULL ||(root->l==NULL&&root->r==NULL))//leaf node is never part of vertex cover
        return 0;
    if(root->dp!=-1)return root->dp;


    int ans=1+vc(root->l)+vc(root->r);
    int ans1=0;
    if(root->l!=NULL)ans1=1+vc(root->l->l)+vc(root->l->r);
    if(root->r!=NULL)ans1+=1+vc(root->r->l)+vc(root->r->r);

    return root->dp=min(ans,ans1);



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

    cout<<vc(root);

}
