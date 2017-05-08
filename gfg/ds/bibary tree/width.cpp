
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

int rw=0;
int lw=0;

void f(node *root,int w)
{
    if(root==NULL)
        return ;
    rw=max(rw,w);
    lw=min(lw,w);
    f(root->r,w+1);
    f(root->l,w-1);

}

queue<int > q[100];

void vot(node *root,int w)
{
    if(root==NULL)
        return;
    q[w].push(root->x);
    vot(root->l,w-1);
    vot(root->r,w+1);
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

    f(root,0);
    vot(root,(abs)(lw)+1);

    for(int i=1;i<=(abs)(lw)+1+rw;i++)
    {
        while(q[i].size()!=0)
        {
            cout<<q[i].front()<<" ";
            q[i].pop();
        }
        cout<<endl;
    }

    cout<<lw<<" "<<rw<<"\n";

}
