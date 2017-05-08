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
int c=0;//it is for finding level of a node in tree
  bool findpath(Node *p,vector<int> &sp,int k)
  {    if (p == NULL) return false;
      sp.push_back(p->key);
      c++;
      if(p->key==k)
        return true;
           if ( (p->left && findpath(p->left, sp, k)) ||(p->right && findpath(p->right, sp, k)) )
        return true;
         sp.pop_back();
         c--;
    return false;

  }

};


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
   bo.findpath(root,tv1,8);
   cout<<bo.c-1;
    return 0;
}
