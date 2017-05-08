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

void f(node *root)
{
    if(root==NULL)
        return ;
    f(root->l);
    node* n=nn(root->x);
    n->l=root->l;
    root->l=n;
    f(root->r);

}

void printInorder(struct node* node)
{
  if (node == NULL)
    return;
  printInorder(node->l);
  printf("%d ", node->x);
  printInorder(node->r);
}

int main()
{

  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = nn(1);
  root->l       = nn(2);
  root->r       = nn(3);
  root->l->l  = nn(4);
  root->l->r = nn(5);

  printf("Inorder traversal of the original tree is \n");
  printInorder(root);

  f(root);

  printf("\n Inorder traversal of the double tree is \n");
  printInorder(root);

  getchar();
  return 0;
}
