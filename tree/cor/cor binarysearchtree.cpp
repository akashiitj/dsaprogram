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
        if(y==NULL)//root formation
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

    void inorder(node *node1)
    {
        if(node1!=NULL)
        {
            inorder(node1->left);
            cout<<node1->key<<endl;
            inorder(node1->right);
        }

    }
    node *sear(node *pth,int x)//pth means pointer to head
    {
        if (pth==NULL)return NULL;
        else if (pth->key==x)return pth;
        else if (x<pth->key) return sear(pth->left,x);
        else return sear(pth->right,x);
    }
    node* minimum(node *pth )
    {
        if(pth==NULL)return NULL;
        else
        {
            while(pth->left!=NULL)
                pth=pth->left;
        }
        return pth;
    }
    node* maximum(node *pth )
    {
        if(pth==NULL)return NULL;
        else
        {
            while(pth->right!=NULL)
                pth=pth->right;
        }
        return pth;
    }
    node *successor(node *n)
    {
        node *y;
        if(n->right!=NULL)
            return(minimum(n->right));
        else
        {
            y=n->parent;
            while(y!=NULL&&y->key<n->key)
            {
                n=y;
                y=y->parent;
            }
            return y;
        }

    }
    node *predessor(node *n)
    {
        node *y;
        if(n->left!=NULL)
            return(maximum(n->left));
        else
        {
            y=n->parent;
            while(y!=NULL&&y->key<n->key)
            {
                n=y;
                y=y->parent;
            }
            return y;
        }

    }
    void  deleten(node *ntd)
    {
        node *nqw;
        if (ntd->left==NULL&&ntd->right==NULL)
        {
            if(ntd->parent==NULL)
            {
                root=NULL;
                delete ntd;
            }
            else if(ntd->parent->key>ntd->key)
            {
                ntd->parent->left=NULL;
                delete ntd;
            }
            else
            {
                ntd->parent->right=NULL;
                delete ntd;
            }
        }
        else if(ntd->left==NULL)
        {
            if(ntd->parent==NULL)
            {
                root=ntd->right;
                delete ntd;
            }
            else if(ntd->parent->key>ntd->key)
            {
                ntd->parent->left=ntd->right;
                delete ntd;
            }
            else
            {
                ntd->parent->right=ntd->right;
                delete ntd;
            }
        }
        else if(ntd->right==NULL)
        {
            if(ntd->parent==NULL)
            {
                root=ntd->left;
                delete ntd;
            }
            else if(ntd->parent->key>ntd->key)
            {
                ntd->parent->left=ntd->left;
                delete ntd;
            }
            else
            {
                ntd->parent->right=ntd->left;
                delete ntd;
            }
        }
        else
        {
            nqw=predessor(ntd);
            int y=nqw->key;
            deleten(nqw);
            ntd->key=y;
        }


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
    bsto.inorder(bsto.root);
    //bsto.test=bsto.sear(bsto.root,1);
    //cout<<bsto.test->key<<endl;
    //
    //cout<<bsto.maximum(bsto.root)<<endl;
    //bsto.test=bsto.predessor(bsto.maximum(bsto.root));
    //cout<<bsto.test->key<<endl;
    //bsto.test=bsto.minimum(bsto.root);
    bsto.deleten(bsto.sear(bsto.root,2));
    bsto.inorder(bsto.root);
    /*while(bsto.test!=NULL)//this is use to inorder tree traversal by repeat call of succesor starting from minimum;
    {
        cout<<bsto.test->key<<"   ";
        bsto.test=bsto.successor(bsto.test);
    }*/
}
