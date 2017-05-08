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
void lca(vector<int> &v1,vector<int> &v2,int n1,int n2)
{   int i=0;
    while(1)
    {
        if(v1[i]==v2[i])
        i++;
        else goto q1;
    }
    q1:
    //cout<<i<<endl;
  int c1=0, k=i-1;
   int c2=0,j=i-1;
    while(v1[k]!=n1){k++;c1++;}
    //cout<<c1<<endl;
    while(v2[j]!=n2){j++;c2++;}
    //cout<<c2<<endl;
    cout<<c1+c2;
}
void lca(vector<int> &v1,vector<int> &v2,int n1,int n2)//lca modify to find distance between two node
{   int i=0;
    while(1)
    {
        if(v1[i]==v2[i])
        i++;
        else goto q1;
    }
    q1:
    //cout<<i<<endl;
  int c1=0, k=i-1;
   int c2=0,j=i-1;
    while(v1[k]!=n1){k++;c1++;}
    //cout<<c1<<endl;
    while(v2[j]!=n2){j++;c2++;}
    //cout<<c2<<endl;
    cout<<c1+c2;
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
    root->right->left->right = newNode(8);
   vector<int> tv1,tv2;
   bt bo;
   bo.findpath(root,tv1,1);
    bo.findpath(root,tv2,4);
    lca(tv1,tv2,1,4);cout<<endl;
  //print(tv1);cout<<endl;
 // print(tv2);
    return 0;
}
