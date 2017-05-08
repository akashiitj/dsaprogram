#include<stdio.h>
struct node
{
    int x;
   struct node *l;
   struct node *r;
};
struct node *f(int a[],int i,int j)
{
    if(i>j)
        return NULL;
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->x=a[i];
    int k=i+1;
    while(i<j&&a[i]>a[k])
        k++;
    n->l=f(a,i+1,k-1);
    n->r=f(a,k,j);
    return n;
};
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->l);
    printf("%d ", node->x);
    printInorder(node->r);
}
void printpreorder (struct node* node)
{
    if (node == NULL)
        return;
         printf("%d ", node->x);
    printpreorder(node->l);

    printpreorder(node->r);
}

// Driver program to test above functions
int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );

    struct node *root = f(pre,0,size-1);

    printf("Inorder traversal of the constructed tree: \n");
    printpreorder(root);

    return 0;
}
