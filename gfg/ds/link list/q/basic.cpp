#include<bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    node *nxt;
};

node *head=NULL, *tail=NULL;

void insrt(int val)
{
    node *n=new node;
    n->x=val;
    n->nxt=NULL;

    if(head==NULL)
    {
        head=n;
        tail=n;
    }
    else
    {
        tail->nxt=n;
        tail=n;
    }
}

void dlt(int val)
{
    node *prev;
    node *crnt=head;

    if(crnt->x==val)//deleting head
    {
        head=crnt->nxt;
    }
    else
    {
        while(crnt->nxt!=NULL&&crnt->x!=val)
        {
            prev=crnt;
            crnt=crnt->nxt;
        }
        prev->nxt=crnt->nxt;
    }
    free(crnt);
}

void show(node *hc)//its head copy
{
    while(hc!=NULL)
    {
        cout<<hc->x<<" ";
        hc=hc->nxt;
    }
    cout<<"\n";
}

int cnt_node(node *head)
{
    int ans=0;
    if(head!=NULL)ans=1;
    while(head->nxt!=NULL)
    {
        ans++;
        head=head->nxt;//you forgot it
    }
    return ans;
}

int srch(node *head,int key)
{
    int ans=0;
    if(head==NULL)return 0;
    if(head->x==key)
    {

        return ans+1;
    }
    while(head->nxt!=NULL)
    {
        ans++;
        if(head->nxt->x==key)
            return ans+1;

        head=head->nxt;
    }
}

void dltnodegivenpointertothatnode(node* p)//last node we cant delete using it, actually nxt node is getting deleted
{

    p->x=p->nxt->x;
    p->nxt=p->nxt->nxt;
    //to free node p->nxt intial wala  you need to to record it intially
}

main()
{

    char s;
    while(1)
    {
        cin>>s;
        if(s=='b')
            break;
        if(s=='i')
        {
            int no;
            cin>>no;
            insrt(no);
        }
        if(s=='d')
        {
            int no;
            cin>>no;
            dlt(no);
        }

        if(s=='s')
            show(head);
        if(s=='c')
            cout<< cnt_node(head)<<"\n";
        if(s=='f')
        {
            int no;
            cin>>no;
            cout<<"elemnt found at place "<< srch(head,no)<<"\n";
        }
    }
    dltnodegivenpointertothatnode(head);
    show(head);

}
