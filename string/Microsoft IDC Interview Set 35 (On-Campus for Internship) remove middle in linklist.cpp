#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    int y;
    struct  node * nxt;

};
void insert1(struct node **head1,struct node **tail1,int x,int y)
{
    struct node* n=new node;
    //scanf("%d", n->x);
    n->x=x;
    n->y=y;
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
        cout<<hc->x<<","<<hc->y<<"   ";
        hc=hc->nxt;
    }
}
void f(node *hc)
{
    node *p=hc;
    while(p!=NULL)
    {
        if(p->nxt!=NULL&&p->nxt->nxt!=NULL)
        {cout<<"dd1"<<endl;
            if((p->x==p->nxt->x)&&(p->nxt->x==p->nxt->nxt->x)||(p->y==p->nxt->y)&&(p->nxt->y==p->nxt->nxt->y))
              {
                  p->nxt=p->nxt->nxt;
                  cout<<"dd"<<endl;
              }
p=p->nxt;
        }
        else p=NULL;
    }
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
            int x,y;
            //scanf("%d",&no);
            cin>>x;
            cin>>y;
            insert1(&head,&tail,x,y);
        }

        if(s=='s')
            show(head);
        if(s=='f')
            f(head);
    }
}

