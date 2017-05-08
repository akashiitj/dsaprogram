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

vector<int> v;

void f(node *root,int key)
{
    if(root==NULL)return;
    v.push_back(root->x);
    if(root->x==key)
    {
         for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
        cout<<"\n";
    }

    f(root->l,key);
    f(root->r,key);
    v.pop_back();

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
   f(root,6);
}

/*


int f(TreeNode* a, int val1,vector<int> &v1)
{

    if(val1==a->val)
{
    v1.push_back(a->val);
    return 1;
}
    int iff=0;
    if(a->left!=NULL) iff=f(a->left,val1,v1);
    if(a->right!=NULL) iff=iff|f(a->right,val1,v1);

    if(iff==1)
    v1.push_back(a->val);

    return iff;


}

int f1(TreeNode* a, int val2,vector<int> &v2)
{
    //v2.push_back(a->val);
    if(val2==a->val)
    {

    v2.push_back(a->val);
    return 1;
    }
    int iff=0;
    if(a->left!=NULL) iff=f(a->left,val2,v2);
    if(a->right!=NULL) iff=iff|f(a->right,val2,v2);

    if(iff==1)
    v2.push_back(a->val);

    return iff;



}

int Solution::lca(TreeNode* A, int val1, int val2) {
    vector<int> v1,v2;
    v1.clear();
    v2.clear();
    f(A,val1,v1);
    f1(A,val2,v2);

    int i=0;

    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());

    while(i<min(v1.size(),v2.size())&&v1[i]==v2[i])
    {
        i++;
    }



    if(v1.size()==0||v2.size()==0)return -1;
    if(i==0)return val1;
    return v1[i-1];
}
*/
