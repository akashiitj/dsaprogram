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

//int in[100];
//int pre[100];

int in[6] = {4, 2, 5, 1, 6, 3};
int pre[6] = {1, 2, 4, 5,3, 6};
int search1(int x,int l,int r)
{
    for(int i=l; i<=r; i++)
    {
        if(x==in[i])return i;
    }
    return -1;
}
int prei=-1;
node *build(int l,int r)
{
    if(l>r)
        return NULL;
    prei++;//you are making mistake here
    node *n=nn(pre[prei]);
   // if(l==r)
     //   return n;
    int mid=search1(pre[prei],l,r);
    if(mid!=-1)   n->l=build(l,mid-1);
    if(mid!=-1)   n->r=build(mid+1,r);

    return n;
}

void post(int l,int r)
{
    if(l>r)
        return ;
    prei++;//you are making mistake here
    int n=pre[prei];
     // if(l==r)
     //   return n;
    int mid=search1(pre[prei],l,r);
    if(mid!=-1)   post(l,mid-1);
    if(mid!=-1)   post(mid+1,r);

    cout<<n<<" ";
}


void printInorder(struct node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->l);

    /* then print the data of node */
    printf("%d ", node->x);

    /* now recur on right child */
    printInorder(node->r);
}

/* Driver program to test above functions */
int main()
{


   // struct node *root = build(0,5);

    /* Let us test the built tree by printing Insorder traversal */
   // printf("\n Inorder traversal of the constructed tree is \n");
    //printInorder(root);

    post(0,5);
    getchar();
}
