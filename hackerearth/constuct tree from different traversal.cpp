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

int find_inorder_index(int l,int r,int inorder[],int val)
{
    for(int i=l;i<=r;i++)
    {
        if(val==inorder[i])
        {
            return i;
        }
    }
}

node * build(int &pre_index,int l,int r,int pre[],int inorder[])//from inorder and preorder
{
    node * n = nn(pre[pre_index++]);
    if (l==r)
        return n;
    int inorder_index = find_inorder_index(l,r,inorder,n->x);
    n->l=build(pre_index,l,inorder_index-1,pre,inorder);
    n->r=build(pre_index,inorder_index+1,r,pre,inorder);
    return n;

}

node * build1(int &post_index,int l,int r,int post[],int inorder[])//from inorder and preorder
{
    node * n = nn(post[post_index--]);
    if (l==r)
        return n;
    int inorder_index = find_inorder_index(l,r,inorder,n->x);
    n->r=build1(post_index,inorder_index+1,r,post,inorder);
    n->l=build1(post_index,l,inorder_index-1,post,inorder);
    return n;

}

int find_post_index(int l,int r,int inorder[],int val)
{
    for(int i=l;i<=r;i++)
    {
        if(val==inorder[i])
        {
            return i;
        }
    }
}


node * build2(int &pre_index,int l,int r,int post[],int pre[])//from postorder and preorder full tree
{
    node * n = nn(pre[pre_index++]);
    if (l==r)
        return n;
    if(pre_index>=5)
        return NULL;
    int post_index = find_post_index(l,r,post,pre[pre_index]);
    n->l=build2(pre_index,l,post_index,post,pre);
    n->r=build2(pre_index,post_index+1,r-1,post,pre);
    return n;

}


void po(node *root)
{
    if(root==NULL)
        return;
    cout<<root->x<<" ";
    po(root->l);
    po(root->r);
}

main()
{
    struct node *root  = nn(10);
    root->l        = nn(8);
    root->r        = nn(2);
    root->l->l   = nn(3);
    root->l->r  = nn(5);
    root->r->r = nn(2);
    int start=0;
    int pre[] = {1 ,2, 3, 4 ,5 };
    int inorder[] = {3,2,4,1,6,5,7};
    int post[] = {3,4,2,5,1};
    po(build2(start,0,4,post,pre));
}
//https://math.stackexchange.com/questions/1531727/why-is-tree-not-uniquely-possible-with-given-preorder-and-postorder-traversal
//
