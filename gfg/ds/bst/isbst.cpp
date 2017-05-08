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

struct ans
{
    int isbst;
    int mi;
    int mx;
};

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



node *pre=NULL;

//int isbst(node *root)
//{
//    if(root==NULL)
//        return 1;
//    if(isbst(root->l)==0)
//        return 0;
//    if(pre!=NULL&&pre->x>root->x)
//        return 0;
//    pre=root;//tricky if you have to print something you print here so for nxt printinh we want previos one so usko print karao and then store it for nxt;
//    if(isbst(root->r)==0)
//        return 0;
//    return 1;
//
//}

int isbst1(node *root,int mi,int mx)
{
    if(root==NULL)
        return 1;
    if(!(root->x>mi &&root->x<=mx))
        return 0;

    return (isbst1(root->l,mi,root->x-1)&&isbst1(root->r,root->x,mx));


}

ans isbst2(node *root)
{
    ans pni;
    if(root==NULL)
    {
        pni.isbst=1;
        pni.mi=INT_MAX;
        pni.mx=INT_MIN;
        return pni;
    }

    ans l=isbst2(root->l);
    ans r=isbst2(root->r);

    if(l.isbst==0||r.isbst==0||l.mx>root->x||r.mi<root->x)
        pni.isbst=0;
    else pni.isbst=1;

    pni.mi= root->l != NULL ? l.mi : root->x;
    pni.mx= root->r != NULL ? r.mx : root->x;

   // cout<<pni.isbst<<" "<<root->x<<"\n";
    return pni;

}

main()
{
    node *root=NULL;
    if(root==NULL)root=insrt(root,50);
    insrt(root, 30);
    //root->r=nn(40);

    ans fa=isbst2(root);

    cout<<fa.isbst;
}

