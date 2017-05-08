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

node *suc(node *root)
{
    if(root->l==NULL)
        return root;
    return suc(root->l);
}

node *dlt(node * root,int key)
{
    if(root==NULL)
        return root;
    if(key<root->x)
        root->l=dlt(root->l,key);//return root at bottom is necessary for this
    else if(key>root->x)
        root->r=dlt(root->r,key);
    else
    {   //if root have less than 2 child
        if(root->l==NULL)
        {
            node *t=root->r;
            free(root);
            return t;
        }

        else if(root->r==NULL)
        {
            node *t=root->l;
            free(root);
            return t;
        }
        // if root have 2 child
        else
        {
            node *t=suc(root->r);
            root->x=t->x;//put sucssesor in root
            root->r=dlt(root->r,t->x);//you forgot root->right
        }
    }
    return root;//inportant step ,cover various case like if root is itself deleted
}

void modify(node *root,int &sum)
{
    if(root==NULL)
        return;
    modify(root->r,sum);
    sum+=root->x;
    root->x=sum;
    modify(root->l,sum);

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
    root=dlt(root,80);
    int sum=0;
    inorder(root);
    cout<<"\n";

    modify(root,sum);

    inorder(root);

}

