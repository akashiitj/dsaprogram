#include<iostream>
using namespace std;
int c=0;
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

    void inorder(node *node1)
    {
        if(node1!=NULL)
        {
            inorder(node1->left);
            cout<<node1->key<<endl;
            inorder(node1->right);
        }

    }
    void inorderforr(node *node1)
    {
        if(node1!=NULL)
        {     inorderforr(node1->right);
            node1->key=node1->key+c;
            c=node1->key;

             inorderforr(node1->left);
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
        node* t=n;
        if(n->left!=NULL)
            return(maximum(n->left));
        else
        {
            y=n->parent;
            while(y!=NULL&&y->key>n->key)
            {
                n=y;
                y=y->parent;
            }
            if(y!=NULL&&t->key<y->key)return NULL;//condition for returning predessor because it get modify
            else return y;
        }

    }
    void modify(node *r)
    {
        node *n1=maximum(r);
        node *ptp,*ptpp;//pointer to predessor,/pointer to predessor predessor
        //  int c=0;
        ptp=predessor(maximum(r));

        // cout<<ptp->key<<endl<<n->key<<endl;
        while(ptp!=NULL)
        {

             ptpp=predessor(ptp);
         //  if(ptpp==NULL)cout<<"hhhy"<<endl;

           // cout<<ptp->key<<"  "<<n1->key<<endl;

            ptp->key=ptp->key+n1->key;
           // cout<<ptp->key<<"  "<<n1->key<<endl;
            n1=ptp;
            ptp=ptpp;
        }
    }

};

main()
{
    bst bsto;
    bsto.inser(bsto.root,50);
    bsto.inser(bsto.root,30);
    bsto.inser(bsto.root,20);
    bsto.inser(bsto.root,40);
    bsto.inser(bsto.root,70);
    bsto.inser(bsto.root,60);
    bsto.inser(bsto.root,80);
    bsto.inorder(bsto.root);
    //bsto.test=bsto.sear(bsto.root,1);
    //cout<<bsto.test->key<<endl;
    //
    //cout<<bsto.maximum(bsto.root)<<endl;
    //bsto.test=bsto.predessor(bsto.maximum(bsto.root));
    //cout<<bsto.test->key<<endl;
    //bsto.test=bsto.minimum(bsto.root);
    bsto.inorderforr(bsto.root);
    bsto.inorder(bsto.root);
    /*while(bsto.test!=NULL)//this is use to inorder tree traversal by repeat call of succesor starting from minimum;
    {
        cout<<bsto.test->key<<"   ";
        bsto.test=bsto.successor(bsto.test);
    }*/
}

