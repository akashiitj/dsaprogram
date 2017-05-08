#include<iostream>
using namespace std;
struct node
{
    int x;
    node *left;
    node *right;
}*head,*last,*ptr1,*ptr,*ptr3;
int c=0;
void create(int q)
{
    node *ptr=new node();
    head=ptr;
    //while()
    //{
        ptr->x=q;
        ptr1=ptr;
        ptr=new node();
        ptr1->right=ptr;
        ptr->left=ptr1;
        c++;
    //}
    last=ptr;
    ptr->right=NULL;
    last->right=NULL;
    head->left=NULL;
}
void show(node *ptr2)
{
    ptr3=head;
    while(ptr3->right!=NULL)
    {
        cout<<ptr3->x<<"\t";
        ptr3=ptr3->right;
    }
    cout<<c;
}
void first(node *q)
{
    node *ptr12=head;
    cout<<"element at first position is \t"<<ptr12->x;
}
void lst(node *m)
{
    node *ptr13=last;
    cout<<"element at last position is \t"<<ptr13->x;
}
int main()
{
    create(34);
    show(head);
    first(head);
    lst(head);
//show1(last);
    return 0;
}
