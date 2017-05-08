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
    if(tail==NULL)
    {
        head=n;
        tail=head;
    }
    else
    {
        tail->nxt=n;
        tail=n;
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

void printm()
{
    if(head==NULL)
        return;
    node *slow=head;
    node *fast=head;

    while(fast!=NULL&&fast->nxt!=NULL)
    {
        slow=slow->nxt;
        fast=fast->nxt->nxt;
    }
    cout<<slow->x<<" m\n";
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
        if(s=='s')
            show();
        printm();

    }

}
