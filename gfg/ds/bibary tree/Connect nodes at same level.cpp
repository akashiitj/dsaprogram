

#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *l;
    node *r;
    node *nxt;
    int x;
};

node *nn(int x1)//return new node
{
    node *n=new node;
    n->l=NULL;
    n->r=NULL;
    n->nxt=NULL;
    n->x=x1;

    return n;
}

void lot(node *root)
{
    if(root==NULL)
        return;

    queue<node *> q1,q2;//first you are using queue
    q1.push(root);

    while(!(q1.empty()!=0&&q2.empty()!=0))//when both are full or both are empty it doesnt work,it works when one of them is emptty
    {
        while(q1.empty()!=1)
        {
            node *n=q1.front();
            q1.pop();
            if(q1.empty()!=1)
            {
                n->nxt=q1.front();
            }
            if(n->l!=NULL)  q2.push(n->l);//forgetting this
            if(n->r!=NULL) q2.push(n->r);
        }

        while(q2.empty()!=1)
        {
            node *n=q2.front();
            q2.pop();
            if(q2.empty()!=1)
            {
                n->nxt=q2.front();
            }
            if(n->l!=NULL)  q1.push(n->l);
            if(n->r!=NULL) q1.push(n->r);
        }
    }
}

main()
{
    struct node *root = nn(1);
    root->l        = nn(2);
    root->r       = nn(3);
    root->l->l  = nn(7);
    root->l->r = nn(6);
    root->r->l  = nn(5);
    node *n=root->l->l;

    lot(root);

    node *n1=root->l->l;

    while(n1!=NULL)
    {
        cout<<n1->x<<" ";
        n1=n1->nxt;
    }


}
