#include <iostream>
#include <vector>
using namespace std;

// A Bianry Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};

// Utility function creates a new binary tree node with given key
Node * newNode(int k)
{
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

void sum(Node *root,int x)
{
    if(root->left!=NULL||root->right!=NULL)
    {
        if(root->left!=NULL)sum(root->left,x+root->left->key);
        if(root->right!=NULL)sum(root->right,x+root->right->key);
    }
    else {cout<<x<<endl;}
}
int main()
{
    struct Node *root = newNode(6);
    root->left        = newNode(3);
    root->right       = newNode(5);
    root->right->right= newNode(7);
    root->left->left  = newNode(2);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    sum(root,root->key);
    return 0;
}
