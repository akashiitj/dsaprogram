

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

void equalise(node *root,int inc)
{
    if(root->l!=NULL)
    {

        root->l->x+=inc;
        equalise(root->l,inc);
    }
    else if(root->r!=NULL)
    {
        root->r->x+=inc;
        equalise(root->r,inc);
    }
}


void f(node *root)
{
    if(root==NULL||(root->l==NULL&&root->r==NULL))
        return;
    f(root->l);
    f(root->r);
    int sum=0;
    if(root->l!=NULL)
    {
        sum=root->l->x;
    }
    if(root->r!=NULL)
    {
        sum+=root->r->x;
    }


    if(sum>root->x)
    {
        root->x=sum;

    }
    else if(sum<root->x) equalise(root,(root->x)-sum);
}


void printInorder(struct node* node)
{
  if (node == NULL)
    return;

  /* first recur on left child */
  printInorder(node->l);

  /* then print the data of node */
  printf("%d ", node->x);

  /* now recur on right child */
  printInorder(node->r);
}

main()
{
    struct node *root = nn(50);
    root->l        = nn(7);
    root->r       = nn(2);
    root->l->l  = nn(3);
    root->l->r = nn(5);
    root->r->l  = nn(1);
    root->r->r = nn(30);
    printInorder(root);
    cout<<"\n";
    f(root);
    printInorder(root);
}
