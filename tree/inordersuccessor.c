#include<stdio.h>
//using namespace std;
struct node
{
    int data;
    struct node *l;
    struct node *r;
};
struct node *newnode(int data)
{
    struct node *temp=(struct node *) malloc(sizeof(struct node));
    temp->data=data;
    temp->l=NULL;
    temp->r=NULL;
    return temp;
}
void inorder(struct node *root)
{
    if(root==NULL)
        return;
    inorder(root->l);
    printf("%d ",root->data);

    inorder(root->r);
}

/*void correcting_bst(struct node *root,struct node *r,struct node a[],int *i)//to keep record
{
    if(root==NULL)
        return ;
     //printf("1 ");
    correcting_bst(root->l,r,a,i);
    if(r->data>root->data)
    {   if((*i)++==0)
       a[*i]=*r;
        else a[*i]=*root;
    }
//printf("1 ");
r->data=root->data;
    correcting_bst(root->r,r,a,i);
    //return 1;
}*/
struct node * is(struct node *root,struct node **r,struct node *a)//to keep record
{   struct node *temp;
    temp=NULL;
    if(root==NULL)
        return NULL ;

    temp=is(root->l,r,a);
    if(temp!=NULL)
    {
        return(temp);
   }
    if(*r==a)
    {
        printf("%d ",root->data);
       // *r=root;
        return root;
    }
    *r=root;


    is(root->r,r,a);
    return NULL;
}

main()
{

    struct node* root=newnode(120);
    // struct node* r=(struct node*)malloc(sizeof(struct node));
    // r->data=0;

    root->l=newnode(5);
    root->r=newnode(15);
    root->l->r=newnode(9);
    root->l->l=newnode(2);
    root->r->r=newnode(10);
    root->r->l=newnode(11);
    struct node *r=NULL;
    struct node *sn=is(root,&r,root);
   // if(sn!=NULL)printf("%d",r->data);
    //inorder(root);

}

