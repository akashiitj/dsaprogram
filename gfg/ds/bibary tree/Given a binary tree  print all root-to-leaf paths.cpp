
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
vector<int> v;

void f(node *root)
{
    if(root==NULL)
        return;
    v.push_back(root->x);
    if(root->l==NULL&&root->r==NULL)
    {
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<"\n";
        v.pop_back();
        return;
    }
    f(root->l);
    f(root->r);
    v.pop_back();

}

main()
{
    struct node *root = nn(1);
    root->l        = nn(2);
    root->r       = nn(3);
    root->l->l  = nn(7);
    root->l->r = nn(6);
    root->r->l  = nn(5);
    root->r->r = nn(4);
    f(root);
}
