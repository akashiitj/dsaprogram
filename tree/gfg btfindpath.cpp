#include<iostream>
#include<vector>
using namespace std;
// A Bianry Tree node
struct Node
{
    int key;
     Node *left, *right;
};

// Utility function creates a new binary tree node with given key
Node * newNode(int k)
{
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

class bt
{ public:
  bool findpath(Node *p,vector<int> &sp,int k)
  {    if (p == NULL) return false;
      sp.push_back(p->key);
      if(p->key==k)
        return true;
           if ( (p->left && findpath(p->left, sp, k)) ||(p->right && findpath(p->right, sp, k)) )
        return true;
         sp.pop_back();
    return false;

  }

};
int lca(vector<int> &v1,vector<int> &v2)
{   int i=0;    while(1)
    {
        if(v1[i]==v2[i])
        i++;
        else goto q1;
    }
    q1:
    cout<<v1[i-1];
}
void print(vector<int> &v)
{
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<"  ";
}
int main()
{
    // Let us create the Binary Tree shown in above diagram.
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
   vector<int> tv1,tv2;
   bt bo;
   bo.findpath(root,tv1,7);
    bo.findpath(root,tv2,3);
    lca(tv1,tv2);cout<<endl;
//   print(tv);
    return 0;
}
