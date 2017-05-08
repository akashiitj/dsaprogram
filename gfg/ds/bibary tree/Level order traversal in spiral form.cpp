
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

void lotspiral(node *root)
{
    if(root==NULL)
        return;
    int ln=0;
    deque<node *> s1,s2;
    s1.push_back(root);
    while(s1.empty()!=1||s2.empty()!=1)//remember this condition
    {
        //cout<<"1\n";
        while(s1.empty()!=1)
        {
            //cout<<"12\n";
            node *n=s1.back();
            cout<<n->x<<" ";

            if(n->r!=NULL)
                s2.push_back(n->r);

            if(n->l!=NULL)
                s2.push_back(n->l);

            s1.pop_back();
        }
        cout<<"\n";
       // break;
        while(s2.empty()!=1)
        {
         //   cout<<"13\n";
            node *n=s2.back();
            cout<<n->x<<" ";
            if(n->l!=NULL)
                s1.push_back(n->l);

            if(n->l!=NULL)
                s1.push_back(n->r);

            s2.pop_back();
        }
        cout<<"\n";

    }
}
void lot1spiral(node* root)
{
    if (root==NULL)
        return;
    int oe = 0;
    vector<node*> v,fut;
    v.push_back(root);
    while(v.size()!=0)
    {
        fut.clear();
        for(int i=0;i<v.size();i++)
        {
            if(oe==0)
            {
                node *n = v[i];
                cout<<n->x<<" ";
                if (n->l != NULL) fut.push_back(n->l);
                if (n->r != NULL) fut.push_back(n->r);

            }
            else
            {
                node *n = v[i];
                cout<<n->x<<" ";
                if (n->r != NULL) fut.push_back(n->r);
                if (n->l != NULL) fut.push_back(n->l);

            }
        }
        cout<<"\n";
        reverse(fut.begin(),fut.end());
        v=fut;
        oe = (oe+1)%2;
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
    root->r->r = nn(4);
    lot1spiral(root);
}
