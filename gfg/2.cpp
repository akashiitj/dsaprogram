#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *left;
    node *right;
    int val;
};

node *nn(int x1)//return new node
{
    node *n=new node;
    n->left=NULL;
    n->right=NULL;
    n->val=x1;
    return n;
}
node* bst_to_list(node* root)
{

    if (root == NULL)
        return root;

    if (root->left != NULL)
    {
        node* left = bst_to_list(root->left);
        while (left->right!=NULL)
            left=left->right;
        left->right = root;
        root->left = left;
    }
    if (root->right!=NULL)
    {
        node* right = bst_to_list(root->right);
        while(right->left!=NULL)
            right = right->left;
        right->left = root;
        root->right = right;
    }
    return root;
}

void print(node *node)
{
    while (node!=NULL)
    {
        cout<<node->val<<" ";
        node = node->right;
    }
}

main()
{
    struct node *root = nn(10);
    root->left        = nn(6);
    root->right       = nn(14);
    root->left->left  = nn(4);
    root->left->right = nn(8);
    root->right->left  = nn(12);
    root->right->right = nn(16);
    root = bst_to_list(root);
    while (root->left != NULL)
        root = root->left;
    print(root);
}

