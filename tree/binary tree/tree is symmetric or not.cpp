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
void inorder(node *root,string &s)
{
    if(root==NULL)
        return ;
    inorder(root->l,s);

    string str2;
    {
        stringstream ss;
        ss << root->data;
        str2 = ss.str();
    }
    s=s+str2+" ";
    inorder(root->r,s);
   // cout<<s<<endl;
    // return s;
}
void rinorder(node *root,string &s)
{
    if(root==NULL)
        return ;
    inorder(root->r,s);

    string str2;
    {
        stringstream ss;
        ss << root->data;
        str2 = ss.str();
    }
    s=s+str2+" ";
    inorder(root->l,s);
   // cout<<s<<endl;
    // return s;
}
bool f(node *rootl,node *rootr)
{
    if(rootl==NULL||rootr==NULL)return(rootl==NULL&&rootr==NULL);
    return(f(rootl->l,rootr->r)&&f(rootl->r,rootr->l));
}
main()
{
    node *root=newnode(1);
    root->l=newnode(-22);
    root->r=newnode(-22);
    root->l->r=newnode(-5);
    root->l->l=newnode(-100);
    root->r->r=newnode(-100);
    root->r->l=newnode(-5);
    string s1="",s2="";
    cout<<f(root->l,root->r)<<endl;
    inorder(root->l,s1);
    rinorder(root->r,s2);
    if(s1==s2) cout<<"mirror";
    else cout<<"not";
    }

