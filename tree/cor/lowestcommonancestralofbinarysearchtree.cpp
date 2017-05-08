#include<iostream>
using namespace std;
struct node
{
    node *parent;
    node *left;
    int key;
    node *right;
};
class bst
{
public:
    node *root,*test;
    bst()
    {
        root=NULL;

    }
    void inser(node *node1,int no)
    {
        node *y=NULL;
        node *x=node1;
        while(x!=NULL)
        {
            y=x;
            if(x->key>no)x=x->left;
            else x=x->right;
        }
        node *n=new node;
        if(y==NULL)
        {

            n->key=no;
            root=n;
            n->parent=NULL;
        }

        else if(y->key>no)
        {
            n->parent=y;
            //node *n=new node;
            n->key=no;
            y->left=n;
        }
        else
        {
            n->parent=y;
            //node *n=new node;
            n->key=no;
            y->right=n;
        }
        n->left=NULL;
        n->right=NULL;
    }

    node *lca(node *node1,int key1,int key2)
    {
        if(node1->key > key1 &&node1->key<=key2 )
            return node1;
        else if(node1->key > key1)
            return lca(node1->left, key1, key2);
         else if(node1->key <= key1)
            return lca(node1->right,key1, key2);
    }
};

main()
{
    bst bsto;
    bsto.inser(bsto.root,2);
    bsto.inser(bsto.root,1);
    bsto.inser(bsto.root,12);
    bsto.inser(bsto.root,82);
    bsto.inser(bsto.root,2);
    bsto.inser(bsto.root,20);
    bsto.test=bsto.lca(bsto.root,2,20);
    cout<<bsto.test->key;
}

