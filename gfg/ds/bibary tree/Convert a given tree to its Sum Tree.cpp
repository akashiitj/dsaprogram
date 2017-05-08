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

int sum(node *root)
{
    if(root==NULL)
        return 0;
    int old=root->x;

    root->x=sum(root->l)+sum(root->r);

    return root->x+old;
}

void printInorder(struct node* node)
{
     if (node == NULL)
          return;
     printInorder(node->l);
     printf("%d ", node->x);
     printInorder(node->r);
}

main()
{
   node *root = nn(10);
  root->l = nn(-2);
  root->r = nn(6);
  root->l->l = nn(8);
  root->l->r = nn(-4);
  root->r->l = nn(7);
  root->r->r = nn(5);

  sum(root);
  printInorder(root);

}
