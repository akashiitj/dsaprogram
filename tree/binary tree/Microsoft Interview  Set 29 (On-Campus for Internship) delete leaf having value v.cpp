//#include<bits/stdc++.h>
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

node* postorder(node *root,int value)
{
    if(root==NULL)
        return NULL;
    node *n1=postorder(root->l,value);
    node *n2= postorder(root->r,value);
    if(n1==NULL)root->l=NULL;
    if(n2==NULL)root->r=NULL;

    if(root->data==value&&n1==NULL&&n2==NULL)
    {
        delete(root);
        return NULL;
    }
    return root;//just for formality

}
void show(node *root, stack<node *> s)//no chage in stack that is passed
{
    s.push(root);
    while(!s.empty())
    {
        node* n=s.top();
        cout<<n->data<<endl;
        s.pop();
        if(n->l!=NULL)
            s.push(n->l);
        if(n->r!=NULL)
            s.push(n->r);
    }
}
void show1(node *root)//no chage in stack that is passed
{


    cout<<root->data<<endl;

    if(root->l!=NULL)
    {
        //cout<<root->data<<endl;
        show1(root->l);
    }
    if(root->r!=NULL)
    {
        //cout<<root->data<<endl;
        show1(root->r);
    }
    else return;

}
void lot(node *root)
{
    queue<node *> q;
    if(root)q.push(root);
    while(!q.empty())
    {
        node *tn=q.front();
        q.pop();
        cout<<tn->data<<" ";
        if(tn->l!=NULL)
            q.push(tn->l);
        if(tn->r!=NULL)
            q.push(tn->r);
    }
}
int t=-290;
void lotc(node *n)//level order tracversal
{
    queue<node *> q;//it store element
    if(n!=NULL)
    {
        int c=0,c1=1;
        int rv=1,i=0;
        q.push(n);
        while(!q.empty())
        {
            cout<<i++<<" level no,element "<<c1<<endl;

            while(c1>0)

            {
                node *hp=q.front();
                node *hp1=q.back();
                q.pop();
                cout<<hp->data<<" ";//for printing r view

                if(hp->l !=NULL)
                {
                    q.push(hp->l);
                    c++;
                }
                if(hp->r !=NULL)
                {
                    q.push(hp->r);
                    c++;
                }

                c1--;
            }
            cout<<endl;
            // cout<<c<<"  let"<<endl;
            c1=c;
            rv=c;
            c=0;
        }
    }

}
int height(node *root)
{
    if(root==NULL)
        return 0;
    int lsh=height(root->l);
    int rsh=height(root->r);
    if(lsh>rsh)return lsh+1;
    else return rsh+1;
}
void printnodeatgivenlevel(node *root,int l)
{
    if(root==NULL)
        return;
    if(l==0)
    {
        cout<<root->data<<" ";
        return;
    }
    printnodeatgivenlevel(root->l,l-1);
    printnodeatgivenlevel(root->r,l-1);
}
int isbst(node *root,int *r)//to keep record
{
    if(root==NULL)
        return 1 ;

    isbst(root->l,r);
    if(t>root->data)
    {
        *r=1;
        return 0;
    }

    else t=root->data;
    //  cout<<root->data<<endl;
    isbst(root->r,r);

}
main()
{
    node *root=newnode(1);
    root->l=newnode(-22);
    root->r=newnode(7);
    root->l->r=newnode(-5);
    root->l->l=newnode(-100);
    root->r->r=newnode(7);
    root->r->l=newnode(7);
    /*   stack<node *> s;
     //  show(root,s);
       inorder(root);
      // cout<<endl;
       preorder(root);
       cout<<endl;

       cout<<endl;
       lotc(root);
           cout<<endl;
        cout<<height(root);
          cout<<endl;
          printnodeatgivenlevel(root,2);*/
    //  lotc(root);
    //int r=0;
    // char c[1];
    //   sprintf(c,"%d",r);
    // int i=isbst(root,&r);
    //     cout<<c<<endl;
    lotc(root);
    postorder(root,7);
    cout<<endl;
    lotc(root);
}
