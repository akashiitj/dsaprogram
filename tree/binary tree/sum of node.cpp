#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct node
{
    int data;
    node *l;
    node *r;
};
node *newnode(int data)
{
    node *temp=new node();
    temp->data=data;
    temp->l=NULL;
    temp->r=NULL;
    return temp;
}
int  maxsum(node *root,int & x)
{
    if(root==NULL)return 0;
    if(root->l==NULL&&root->r==NULL)
        return root->data;
    int ls= maxsum(root->l,x);
    int rs= maxsum(root->r,x);
    root->data=root->data+ls+rs;
    if(root->data>x)x=root->data;

    return root->data;
    //if(root->data>x)x=root->data;


}

main()
{
    node *root=newnode(1);
    root->l=newnode(-22);
    root->r=newnode(3);
    root->l->r=newnode(-5);
    root->l->l=newnode(0);
    root->r->r=newnode(7);
    root->r->l=newnode(2);
    int x=-100;
    cout<<maxsum(root,x)<<endl;
    cout<<x<<endl;
}

