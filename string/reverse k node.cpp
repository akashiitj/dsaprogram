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

void show(struct node *hc)//its head copy
{
    while(hc!=NULL)
    {
        cout<<hc->val<<" ";
        hc=hc->nxt;
    }
}
void f(node **root,int k)
{
    node *c=*root,*pre=NULL,*pre1,*p;
    int k1,k2=0;
    while(c!=NULL)
    {
        k1=0;
        p=c;
        while(c!=NULL&&k1<k)
        {
            k2++;
            k1++;
            node *nxt=c->nxt;
            c->nxt=pre;
            pre=c;
            c=nxt;

        }
        if(k2<=k)
        {
            *root=pre;

        }
        else pre1->nxt=pre;//first element of pre chunk without reversing pont to last element of nxt chunk with reversingbe

        pre1=p;//first element of previus chunk become last element of that chunk
    }
    p->nxt=NULL;

}
main()
{
    struct node *head=NULL, *tail=NULL;
    char s;
    while(1)
    {
        //cin>>s;
        cin>>s;
        if(s=='i')
        {
            int no;
            //scanf("%d",&no);
            cin>>no;
            insert1(&head,&tail,no);
        }
        if(s=='f')
        {
            int k;
            cin >>k;
            f(&head,k);
        }
        if(s=='s')
            show(head);
    }
}
