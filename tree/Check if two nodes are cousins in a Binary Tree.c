#include<stdio.h>
struct node
{
    int x;
    struct node *l;
    struct node *r;
};
struct node* newNode(int x)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->x=x;
    n->l=NULL;
    n->r=NULL;
    return n;
}
int level(struct node *root,struct node *n,int l1)
{
    if(root==NULL)
        return -1;
    if(root==n)return l1;
    int l=level(root->l,n,l1+1);
    if(l!=-1)return l;
    else return level(root->r,n,l1+1);
}
int sibling(struct node *root,struct node *n1,struct node *n2)
{
    if(root==NULL)return 0;
    return(root->l==n1&&root->r==n2||root->r==n1&&root->l==n2||sibling(root->l,n1,n2)||sibling(root->r,n1,n2));
}
int cousin(struct node *root,struct node *n1,struct node *n2)
{
    if((level(root,n1,0)==level(root,n2,0))&&(sibling(root,n1,n2)==0))
        return 1;
    else return 0;
}
int main()
{
    struct node *root = newNode(1);
    root->l = newNode(2);
    root->r = newNode(3);
    root->l->l = newNode(4);
    root->l->r = newNode(5);
    root->l->r->r = newNode(15);
    root->r->l = newNode(6);
    root->r->r = newNode(7);
    root->r->l->r = newNode(8);

    struct node *Node1,*Node2;
    Node1 = root;
    Node2 = root->r->r;

    cousin(root,Node1,Node2)? puts("Yes"): puts("No");
}
