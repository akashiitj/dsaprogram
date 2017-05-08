
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

map<int ,int> m;

int ml=0;int mr=0;
void tw(node *n,int w)
{
    if(n==NULL)
        return;
    if(-(w)>ml)
    {
        m[w]=n->x;
        ml=-(w);
    }
    if(w>mr)
    {
        m[w]=n->x;
        mr=w;
    }
    tw(n->l,w-1);
    tw(n->r,w+1);
}


void bw(node *n,int w)
{
    if(n==NULL)
        return;

    m[w]=n->x;

    bw(n->l,w-1);
    bw(n->r,w+1);
}

#define loop(i,a,b)      for(int i=a;i<b;i++)

main()
{
    struct node *root = nn(1);
    root->l        = nn(2);
    root->r       = nn(3);
    root->l->l  = nn(7);
    root->l->r = nn(6);
    root->r->l  = nn(5);
    root->r->r = nn(4);

    m[0]=root->x;
   // bw(root,0);
    tw(root,0);
    cout<<ml<<" "<<mr<<"\n";

    loop(i,-ml,mr+1)
    {
        cout<<m[i]<<" ";
    }
}
