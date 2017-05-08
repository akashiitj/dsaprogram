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

void reverse1()
{
    node *future=head->nxt;
    node *cur=head;
    node *pre=NULL;
    while(future!=NULL)
    {

        future=cur->nxt;
        cur->nxt=pre;
        pre=cur;
        cur=future;
    }
    if(pre!=NULL) head=pre;//for 1 node case
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
            reverse1();
        }
        if(s=='s')
            show();


    }

}
