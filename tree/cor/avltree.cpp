#include<iostream>
using namespace std;
#include <queue>
struct node
{
    int key;
    node *left;
    node *right;
    int height;
};
class avltree
{
public:
    node* root;
    avltree()
    {
        root=NULL;
    }
    // A utility function to get height of the tree
    int height(struct node *N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }

// A utility function to get maximum of two integers
    int max(int a, int b)
    {
        return (a > b)? a : b;
    }

    /* Helper function that allocates a new node with the given key and
        NULL left and right pointers. */
    node* newNode(int key)
    {
        node* node1 = new node;
        node1->key   = key;
        node1->left   = NULL;
        node1->right  = NULL;
        node1->height = 1;  // new node is initially added at leaf
        return(node1);
    }

    node *rightRotate( node *y)
    {
        node *x = y->left;
        node *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right))+1;
        x->height = max(height(x->left), height(x->right))+1;

        // Return new root
        return x;
    }

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
    node *leftRotate( node *x)
    {
        node *y = x->right;
        node *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        //  Update heights
        x->height = max(height(x->left), height(x->right))+1;
        y->height = max(height(y->left), height(y->right))+1;

        // Return new root
        return y;
    }

// Get Balance factor of node N
    int getBalance( node *N)
    {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }

    node* insert( node* node, int key)
    {
        /* 1.  Perform the normal BST rotation */
        if (node == NULL)
            return(newNode(key));

        if (key < node->key)
            node->left  = insert(node->left, key);
        else
            node->right = insert(node->right, key);

        /* 2. Update height of this ancestor node */
        node->height = max(height(node->left), height(node->right)) + 1;

        /* 3. Get the balance factor of this ancestor node to check whether
           this node became unbalanced */
        int balance = getBalance(node);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key)
        {
            node->left =  leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }
     node * minValueNode( node* node2)
{
     node* current = node2;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}
     node* deleteNode(node* root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            node *temp = root->left ? root->left : root->right;

            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child

            delete(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
             node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = max(height(root->left), height(root->right)) + 1;

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
        void inorder(node *nod1)
    {
        if(nod1!=NULL)
        {
            inorder(nod1->left);
            cout<<nod1->key<<endl;
            inorder(nod1->right);
        }

    }
    void levelordertraverse(node *n)
    {
        queue<node*> myq;
        myq.push(root);
        int levelno=0,nodeno=1;
        while(!myq.empty())
        {   int tmp=0;
            cout<<"levelno  "<<levelno<<"  ";
            while(nodeno!=0){
            node *t=myq.front();
            myq.pop();
            cout<<t->key<<"  ";
            if(t->left!=NULL)  { myq.push(t->left);tmp++;}
            if(t->right!=NULL)  { myq.push(t->right);tmp++;}
            nodeno--;
        }
        cout<<endl;
        nodeno=tmp;
        levelno=levelno+1;
        }
    }

};
main()
{
    avltree ao;
    ao.root=ao.insert(ao.root,4);
    ao.root=ao.insert(ao.root,42);
    ao.root=ao.insert(ao.root,43);
    ao.root=ao.insert(ao.root,44);
    ao.root=ao.insert(ao.root,45);
    ao.inorder(ao.root);
    ao.root=ao.deleteNode(ao.root,44);
    ao.inorder(ao.root);
  ao.levelordertraverse(ao.root);
}
