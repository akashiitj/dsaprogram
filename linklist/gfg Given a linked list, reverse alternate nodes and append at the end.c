#include<stdio.h>
struct node
{
    int val;
    struct  node * nxt;

};
void insert1(struct node **head1,struct node **tail1,int val)
{
    struct node* n=(struct node*) malloc(sizeof(struct node) );
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
        printf("%d ",hc->val);
        hc=hc->nxt;
    }
}
void rf(struct node *h)//its head copy
{
    if(h==NULL||h->nxt==NULL||h->nxt->nxt==NULL)
        return;
    struct node *e1=h->nxt;//*e2=e1;
    struct node *ol=e1->nxt;//odd last
    h->nxt=h->nxt->nxt;
    h=h->nxt;
    e1->nxt=NULL;
    while(h&&h->nxt)
    {
        struct node *vp=h->nxt;
        if(vp->nxt!=NULL)  ol=vp->nxt;
        h->nxt=h->nxt->nxt;
        h=h->nxt;
        vp->nxt=e1;
        e1=vp;

    }
    ol->nxt=e1;
}
main()
{
    struct node *head=NULL, *tail=NULL;
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
        /*if(s[0]=='d')
        {
            int no;
            //cin>>no;
              scanf("%d",&no);
            delete1(&head,no);
        }*/
        if(s=='r')
            rf(head);
        if(s=='s')
            show(head);
    }
}
