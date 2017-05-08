#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct  node * nxt;

};
void insert1(struct node **head1,struct node **tail1,int val)
{
    struct node* n=new node;
    //scanf("%d", n->val);
    n->val=val;
    n->nxt=NULL;
    if(*tail1==NULL)
    {
        *head1=n;
        *tail1=*head1;
    }

    else
    {
        (*tail1)->nxt=n;
        (*tail1)=n;
    }
}
void f(node *n,int k)
{   int i=1;
    node *n1;
    while(i)
    {
        if(n->val<=k)
        {
            if(n->nxt->val>n->val&&n->nxt->val>=k)
            {   node *n2=new node;

                n1=n->nxt;
                n->nxt=n2;
                n2->val=k;
                n2->nxt=n1;
  i=0;
            }
            else if(n->nxt->val<n->val&&n->nxt->val<=k)
            {
                 node *n2=new node;

                n1=n->nxt;
                n->nxt=n2;
                n2->val=k;
                n2->nxt=n1;
i=0;
            }
            else n =n->nxt;
        }
        else n=n->nxt;
    }
}
void show(struct node *hc)//its head copy
{   node* hc1=hc->nxt;
cout<<hc->val<<" ";
    while(hc1!=hc)
    {
        cout<<hc1->val<<" ";
        hc1=hc1->nxt;
    }
}
main()
{  char c1=char(97);
string s = "45";

int num = atoi(s.c_str());
cout<<num<<endl;
cout<<c1<<endl;
     node *head=NULL,*tail=NULL;
    insert1(&head,&tail,1);
    insert1(&head,&tail,2);
    insert1(&head,&tail,3);
    insert1(&head,&tail,4);
    insert1(&head,&tail,50);
    insert1(&head,&tail,60);
    tail->nxt=head;
    f(head,120);

    show(head);
}
