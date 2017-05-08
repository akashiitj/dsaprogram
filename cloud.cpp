#include<bits/stdc++.h>
using namespace std;

struct node
{
    int param1;
    int param2;
    node *child1;
    node *child2;
    node *child3;
    node *child4;

};

node *nn(int param1,int param2)
{
    node *n=new node;
    n->param1=param1;
    n->param2=param2;
    n->child1=NULL;
    n->child2=NULL;
    n->child3=NULL;
    n->child4=NULL;
    return n;
}

node* insrt(node *root,int param1,int param2)
{
    if(root==NULL)
    {
        return nn(param1,param2);
    }
    if(param1<root->param1&&param2<root->param2)
        root->child1=insrt(root->child1,param1,param2);
    if(param1>root->param1&&param2<root->param2)
        root->child2=insrt(root->child2,param1,param2);
    if(param1<root->param1&&param2>root->param2)
        root->child3=insrt(root->child3,param1,param2);
    if(param1>root->param1&&param2>root->param2)
        root->child4=insrt(root->child4,param1,param2);


    return root;
}



node *suc=NULL;
void ps(node *root,int param1,int param2)
{
    if(root==NULL)
        return;


    if(root->param1==param1&&root->param2==param2)
    {
        suc=root;

    }

    if(param1<root->param1&&param2<root->param2)
        ps(root->child1,param1,param2);
    else if(param1>=root->param1&&param2<root->param2)
        ps(root->child2,param1,param2);
    else if(param1<root->param1&&param2>=root->param2)
        ps(root->child3,param1,param2);
    else if(param1>=root->param1&&param2>=root->param2)
        ps(root->child4,param1,param2);



    if(suc==NULL&&root->param1>=param1&&root->param2>=param2)//sabse pahle jo return trip me milega
        suc=root;



}


main()
{
    node *root=NULL;
    if(root==NULL)root=insrt(root,50,100);
    insrt(root, 30,40);
    insrt(root, 60,40);
    insrt(root, 30,105);
    insrt(root, 70,110);
    insrt(root, 60,105);
    insrt(root, 80,40);

    ps(root,60,41);
  if(suc!=NULL)  cout<<suc->param1<<" "<<suc->param2;

    //inorder(root);

}
