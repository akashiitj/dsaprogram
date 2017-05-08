
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
 int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
int prei=0;

node *bld(int l,int r)//node that is return from here represent l to r subtree in postorder
{
    if(l>r)return NULL;

    node *n=nn(pre[prei]);
    int x=-1;
    prei++;
    for(int i=l;i<r;i++)
    {
        if(post[i]==pre[prei])
        {
            x=i;
            break;
        }
    }
    if(x==-1)
        return n;
    n->l=bld(l,x);//it is due to full binary tree property that nxt subtree is left
    n->r=bld(x+1,r-1);
    return n;
}
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->l);
    printf("%d ", node->x);
    printInorder(node->r);
}

main()
{
    struct node *root = bld(0,8);

    printInorder(root);


}
