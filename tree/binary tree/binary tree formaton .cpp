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
void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->l);
    cout<<root->data<<" ";
    inorder(root->r);
}
void preorder(node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->l);
    preorder(root->r);
}
void postorder(node *root)
{
    if(root==NULL)
        return;
    postorder(root->l);
    postorder(root->r);
    cout<<root->data<<" ";

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
        int i=0;
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
            // rv=c;
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
    // if((lsh-rsh)>1)return 0;
    if(lsh>rsh)return lsh+1;
    else return rsh+1;
}
int height1(node *root)
{
    if(root==NULL)
        return 0;
    return (1+max(height(root->l),height(root->r)));
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

    if(isbst(root->l,r)==0)return 0;
    if(*r>root->data)
    {
        *r=1;
        return 0;
    }

    else *r=root->data;
    //  cout<<root->data<<endl;
    if(isbst(root->r,r)==0)return 0;
    return 1;
}
main()
{ float a1=5.99999;
cout<<float(32)+a1;
    node *root=newnode(1);
    root->l=newnode(-22);
    root->r=newnode(3);
    root->l->r=newnode(-5);
    root->l->l=newnode(4);
    root->r->r=newnode(7);
    root->r->l=newnode(2);
    /*   stack<node *> s;
     //  show(root,s);
       inorder(root);
      // cout<<endl;
       preorder(root);
       cout<<endl;
       postorder(root);
       cout<<endl;

           cout<<endl;

          cout<<endl;
          printnodeatgivenlevel(root,2);*/
    //  lotc(root);
    int r=0;
    // char c[1];
    //   sprintf(c,"%d",r);
    //
    //     cout<<c<<endl;
    cout<<isbst(root,&r)<<endl;
    lotc(root);
    cout<<endl;
    cout<<height1(root)<<endl;
    int a = 13;
    string str2;
    {
        stringstream ss;
        ss << a;
        str2 = ss.str();
    }
    cout<<str2;
}
