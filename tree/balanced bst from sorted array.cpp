#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    node *l;
    node *r;
};
void preorder(node *n)
{
    if(n==NULL)return ;
    preorder(n->l);
    cout<<n->x;
    preorder(n->r);
}
node *f(int a[],int i,int j)
{
    if(i>j)return NULL;
    node *n=new node;
    int x=(i+j)/2;
    n->x=a[x];
    n->l=f(a,i,x-1);
    n->r=f(a,x+1,j);
    return n;
}
main()
{
    int a[6]={1,2,3,4,5,6};
    node *root=f(a,0,5);
    preorder(root);
}
