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
    if(*tail1==NULL)//inserting 1st element

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
        /*if(s[0]=='d')
        {
            int no;
            //cin>>no;
              scanf("%d",&no);
            delete1(&head,no);
        }*/
        if(s=='s')
            show(head);
    }
}
