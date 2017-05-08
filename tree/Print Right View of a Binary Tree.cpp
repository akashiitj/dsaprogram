#include<bits/stdc++.h>
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
void printnodeatgivenlevel(node *root,int l,int &maxl)//left view
{
    if(root==NULL)
        return;
    if(maxl<l)
    {
        cout<<root->data<<" ";
        maxl=l;
    }
    printnodeatgivenlevel(root->l,l+1,maxl);
    printnodeatgivenlevel(root->r,l+1,maxl);
}
void lotc(node *n)//level order tracversal
{
    queue<node *> q;//it store element
    if(n!=NULL)
    {
        int c=0,c1=1;
        int i=0,rv=1;
        q.push(n);
        while(!q.empty())
        {
           // cout<<i<<" level no,element "<<c1<<endl;
            i++;
            while(c1>0)

            {
                node *hp=q.front();
                node *hp1=q.back();
                q.pop();
                //cout<<hp->data<<" ";//for printing r view
                if(rv==c1)cout<<hp->data<<endl;
               // if(c1==1)cout<<hp->data<<endl;
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

main()
{
    node *root=newnode(1);
    root->l=newnode(-22);
    root->r=newnode(3);
    root->l->r=newnode(-5);
    root->l->l=newnode(4);
    root->r->r=newnode(7);
    root->r->l=newnode(2);
    int i=1,l=0;
    printnodeatgivenlevel(root,i,l);
    //lotc(root);
}
