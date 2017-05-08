
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    node *nxt;
};

node *head=NULL, *tail=NULL;

void insrt(int x1)
{
    node *n=new node;
    n->x=x1;
    n->nxt=NULL;
    if(head==NULL)
    {
        head=n;
        //tail=head;
    }
    else
    {
        n->nxt=head;
        head=n;
    }
}

void show()
{
    node *n=head;
    while(n!=NULL)
    {
        cout<<n->x<<" ";
        n=n->nxt;
    }
    cout<<"\n";

}

void reverse1(int no)
{
    node *cur=head;
    node *pre1=NULL;
    node *intialhead;
    node *pre=NULL;
    node *nxt1;
    int c;
    while(cur!=NULL)
    {
        intialhead=cur;//used for calculating pre1 which is used in nxt iteration for connecting
        pre=NULL;
        nxt1=cur->nxt;
        c=0;
        while(c<no&&nxt1!=NULL)//reverse no number of node
        {
            nxt1=cur->nxt;
            cur->nxt=pre;
            pre=cur;
            cur=nxt1;
            c++;
            //  cout<<cur->x<<" i ";
        }
        if(pre1==NULL)//filling head
        {
            if(pre!=NULL)
                head=pre;
        }
        else
        {
            if(pre!=NULL)  pre1->nxt=pre;
            else pre1->nxt=cur;//if nxt1 is alredy null soo that pre is also null
        }
        pre1=intialhead;//pre1 used to connect previous group to present group
        if(pre==NULL)cur=NULL;
    }
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
        if(s=='r')
        {
            int no;
            cin>>no;
            reverse1(no);
        }
        if(s=='s')
            show();
    }

}
