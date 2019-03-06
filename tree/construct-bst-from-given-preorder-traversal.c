#include<stdio.h>
struct node
{
    int x;
   struct node *l;
   struct node *r;
};
struct node *f(int a[],int i,int j)//n*n approch
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
}

struct node* constructTreeUtil( int pre[], int &preIndex, int key, 
								int min, int max, int size ) //n approch
{ 
	// Base case 
	if( preIndex >= size ) 
		return NULL; 

	struct node* root = NULL; 

	// If current element of pre[] is in range, then 
	// only it is part of current subtree 
	if( key > min && key < max ) 
	{ 
		// Allocate memory for root of this subtree and increment *preIndex 
		root = newNode ( key ); 
		preIndex = preIndex + 1; 
		
		if (preIndex < size) 
		{ 
			// Contruct the subtree under root 
			// All nodes which are in range {min .. key} will go in left 
			// subtree, and first such node will be root of left subtree. 
			root->left = constructTreeUtil( pre, preIndex, pre[preIndex], 
										min, key, size ); 

			// All nodes which are in range {key..max} will go in right 
			// subtree, and first such node will be root of right subtree. 
			root->right = constructTreeUtil( pre, preIndex, pre[preIndex], 
										key, max, size ); 
		} 
	} 

	return root; 
} 

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

    struct node *root = f(pre,0,size-1);//constructTreeUtil ( pre, preIndex, pre[0], INT_MIN, INT_MAX, size );

    printf("Inorder traversal of the constructed tree: \n");
    printpreorder(root);

    return 0;
}
