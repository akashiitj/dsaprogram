#include<bits/stdc++.h>
struct  node
{
    int val;
       node * nxt;

};
void insert1(  node **head1,  node **tail1,int val)
{
     node* n=new node;
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
void f(node *n)
{
    while(n!=NULL)
    {   int sum=0;
        node *ip=n;
        while(n->val!=0)
        {
            sum=sum+n->val;
            n=n->nxt;
        }
        ip->val=sum;
        ip->nxt=n->nxt;
        n=n->nxt;
    }
}
void show(  node *hc)//its head copy
{
    while(hc!=NULL)
    {
        printf("%d ",hc->val);
        hc=hc->nxt;
    }
}
main()
{
     node *head=NULL, *tail=NULL;
    char s;
    while(1)
    {
        //cin>>s;
        scanf("%c",&s);
        if(s=='i')
        {
            int no;
            scanf("%d",&no);
            //cin>>no;
            insert1(&head,&tail,no);
        }
        if(s=='f')
        {
           f(head);
        }
        if(s=='s')
            show(head);
    }
}
