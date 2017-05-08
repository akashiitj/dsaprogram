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

int path[10];

void print(node *root,int pl)
{
    if(root==NULL)
        return;
    path[pl]=root->x;
    print(root->l,pl+1);
    print(root->r,pl+1);

    if(root->l==NULL&&root->r==NULL)
    {
        for(int i=0;i<=pl;i++)
            cout<<path[i]<<" ";
        cout<<"\n";
    }

}

main()
{
    node *root=nn(1);
    root->l=nn(2);
    root->r=nn(3);
    root->l->l=nn(4);
    print(root,0);
}
