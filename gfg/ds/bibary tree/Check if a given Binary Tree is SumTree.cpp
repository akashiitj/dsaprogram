
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

int isleaf(node* root)
{
    if(root==NULL)return 0;
    if(root->l==NULL&&root->r==NULL)
        return 1;
    return 0;

}

int issumtree(node* root)
{
    if(root==NULL||isleaf(root))return 1;
    if(issumtree(root->l)&&issumtree(root->r))
    {
        int ls;
        if(root->l==NULL) ls=0;
        else if(isleaf(root->l))ls=root->l->x;
        else ls=2*root->l->x;

        int rs;
        if(root->r==NULL) rs=0;
        else if(isleaf(root->r))rs=root->r->x;
        else rs=2*root->r->x;

        return ls+rs==root->x;

    }
    return 0;
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
    cout<<issumtree(root);
}
