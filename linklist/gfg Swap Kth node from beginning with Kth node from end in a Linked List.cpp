#include<iostream>
using namespace std;
int l=0;
class sll
{
public:
    struct node//we cant create class here again for this purpose as in java
    {
        int key;
        node *nxt;
    }*head,*tail;
    sll()
    {
        head=NULL;
        tail=NULL;
    }
    void insert1(int x)
    {
        if(tail==NULL)
        {
            node* n=new node;
            n->key=x;
            l++;
            tail=n;
            head=n;
            n->nxt=NULL;
        }
        else
        {
            node* n=new node;
            n->key=x;
            n->nxt=NULL;
            tail->nxt=n;
            tail=n;
            l++;
        }
    }
    void show()
    {
        node* sp;
        sp=head;
        if(sp==NULL)cout<<"list is empty";
        while(sp!=NULL)
        {
            cout<<sp->key<<"  ";

            sp=sp->nxt;
        }
        cout<<endl<<l;
    }
    void removek(int k)
    {   int c1=1,c2=0;
        node *k1=NULL,*k3=NULL,*k2=head,*k4=head,*t;
        if(l%2==1&&k==(l/2)+1)return;
        if(k>(l/2))k=l-k+1;
        while(c1!=k)
        {
            k1=k2;
            k2=k2->nxt;
            c1++;
        }
        while(c2!=l-k)
        {
            k3=k4;
            k4=k4->nxt;
            c2++;
        }
        //cout<<k1->key<<"  "<<k2->key<<"  "<<k3->key<<"  "<<k4->key<<"  ";
        if(k3!=k2)
        {
            k3->nxt=k2;
            t=k2->nxt;
            k2->nxt=k4->nxt;
            k4->nxt=t;
            if(k1==NULL)head=k4;
            else k1->nxt=k4;
        }
        else
        {
            k2->nxt=k4->nxt;
            k4->nxt=k2;
            if(k1==NULL)head=k4;
            else k1->nxt=k4;
        }

    }


};
main()
{
    sll sllo;
    sll *p;
    p=&sllo;
    string s;
    while(true)
    {
        cin>>s;
        if(s[0]=='i')
        {
            int no;
            cin>>no;
            p->insert1(no);
        }
         if(s[0]=='r')
                 {
            int no;
            cin>>no;
            p->removek(no);
        }

        if(s[0]=='s')
            p->show();
    }
}

