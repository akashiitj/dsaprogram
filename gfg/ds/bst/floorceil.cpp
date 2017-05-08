#include<bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    node *l;
    node *r;
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

int srch(node* root,int key)
{
    if(root==NULL)
        return 0;
    if(root->x==key)
    {
        return 1;
    }
    if(key>root->x)
        return srch(root->r,key);
    return srch(root->l,key);
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->l);
        printf("%d ", root->x);
        inorder(root->r);
    }
}

node *pre=NULL,*suc=NULL;//pre means floor
void ps(node *root,int key)
{
    if(root==NULL)
        return;


    if(root->x==key)
    {
        pre=nn(key);
        suc=nn(key);
        return;
    }

    else if(root->x>key)
    {
        ps(root->l,key);
    }

    else ps(root->r,key);

    if(pre==NULL&&root->x<key)//sabse pahle jo return trip me milega
        pre=root;

    if(suc==NULL&&root->x>key)//sabse pahle jo return trip me milega
        suc=root;



}


main()
{
    node *root=NULL;
    if(root==NULL)root=insrt(root,50);
    insrt(root, 30);
    insrt(root, 20);
    insrt(root, 40);
    insrt(root, 70);
    insrt(root, 60);
    insrt(root, 80);

    ps(root,80);
    cout<<pre->x<<" "<<suc->x;

    //inorder(root);

}

