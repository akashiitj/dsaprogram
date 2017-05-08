
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

void level_print(node *root,int cur,int target)
{
    if(root==NULL)
        return ;
    if(cur==target)
    {
        cout<< root->x<<" ";
    }

    level_print(root->l,cur+1,target);
    level_print(root->r,cur+1,target);

}

void lot1(node *root)
{
    if(root==NULL)
        return;
    deque<node *> q;
    q.push_back(root);
    int cur=1;
    int child;
    int ln=0;
    while(q.empty()!=1)
    {
        ln++;
        cout<<ln<<" ln    number of element "<<cur<<"\n";
        child=0;
        while(cur!=0)
        {
            node *n=q.front();
            q.pop_front();
            cout<<n->x<<" ";
            cur--;
            if(n->l!=NULL)
            {
              child++;
              q.push_back(n->l);
            }
            if(n->r!=NULL)
            {
              child++;
              q.push_back(n->r);
            }
        }
        cout<<endl;
        cur=child;
    }
}

void lot2(node *root)
{
    if(root==NULL)return;
    int ln=0;
    deque<node *> qfuture,qcur;
    qcur.push_back(root);
    while(qcur.empty()!=1)
    {
        ln++;
        cout<<ln<<" ln "<<qcur.size()<<"\n";
        qfuture.clear();
        while(qcur.empty()!=1)
        {
            cout<<qcur.front()->x<<" ";
           if(qcur.front()->l!=NULL) qfuture.push_back(qcur.front()->l);
           if(qcur.front()->r!=NULL) qfuture.push_back(qcur.front()->r);
            qcur.pop_front();
        }
        cout<<"\n";
        qcur=qfuture;
       // break;
    }
}

main()
{
    node *root=nn(1);
    root->l=nn(2);
    root->r=nn(3);
    root->l->l=nn(4);
    lot2(root);

}
