

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

    n->x=x1;

    return n;
}

int  lot(node *root)
{
    if(root==NULL)
        return 1;

    queue<node *> q1,q2;//first you are using queue
    q1.push(root);
    int flag=0;
    int c=0;
    while(!(q1.empty()!=0&&q2.empty()!=0))//when both are full or both are empty it doesnt work,it works when one of them is emptty
    {
        c++;

        while(q1.empty()!=1)
        {
            node *n=q1.front();
            q1.pop();

            if(flag==1)
            {
                if(!(n->l==NULL&&n->r==NULL))
                   {
                    cout<<c<<" "<<12<<"\n";
                    return 0;
                }
            }
            if(n->l!=NULL)  q2.push(n->l);//forgetting this
            if(n->r!=NULL) q2.push(n->r);
            if(n->l==NULL&&n->r!=NULL)
                {
                    cout<<c<<" "<<22<<"\n";
                    return 0;
                }
           if((n->l!=NULL&&n->r==NULL)||(n->l==NULL&&n->r==NULL))
                flag=1;
        }
        c++;


        while(q2.empty()!=1)
        {
            node *n=q2.front();
            q2.pop();

            if(flag==1)
            {
                if(!(n->l==NULL&&n->r==NULL))
                {
                    cout<<c<<" "<<1<<"\n";
                    return 0;
                }
            }
            if(n->l!=NULL)  q1.push(n->l);//forgetting this
            if(n->r!=NULL) q1.push(n->r);
            if(n->l==NULL&&n->r!=NULL)
            {
                    cout<<c<<" "<<2<<"\n";
                    return 0;
                }
            if((n->l!=NULL&&n->r==NULL)||(n->l==NULL&&n->r==NULL))
                flag=1;
        }
    }
    return 1;
}

main()
{
    struct node *root = nn(1);
    root->l        = nn(2);
    root->r       = nn(3);
    root->l->l  = nn(7);
  //  root->l->r = nn(6);
    root->l->r  = nn(5);

    root->r->l  = nn(7);
  //  root->l->r = nn(6);
    root->r->r  = nn(5);
    //root->l->l  = nn(17);
    root->l->l->r  = nn(71);



    node *n=root->l->l;

    //lot(root);

    cout<<lot(root);


}

