#include<iostream>
using namespace std;
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
        cout<<endl;
    }
    void dele(int m,int n)
    {
        node *t1=head;
        node *t2;
        while(true)
        {
            int c1=1,c2=1;
            while(c1!=m)
            {
                t1=t1->nxt;
                c1++;
              if(t1==NULL)goto en;
            }
            t2=t1->nxt;
            if(t2==NULL)break;
            while(c2!=n)
            {   if(t2->nxt==NULL)goto q;
                t2=t2->nxt;
                c2++;
            }
            q:
            t1->nxt=t2->nxt;
            t1=t2->nxt;
            if(t1==NULL)break;

        } en:;
    }
    void dele1(int m,int n)
    {
        node *p=head;
        node *p2=NULL;//previous
        while(p!=NULL)
        {
            int c1=1,c2=1;
            while(p!=NULL&&c1<=m)
            {   p2=p;
                p=p->nxt;
                c1++;
              //if(t1==NULL)goto en;
            }

            while(p!=NULL&&c2<=n)
            {
                p2->nxt=p->nxt;
                p=p2->nxt;
                c2++;
            }



    }}
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
        if(s[0]=='d')
        {
            int m,n;
            cin>>m;
            cin>>n;
            p->dele1(m,n);
        }
        if(s[0]=='s')
            p->show();
    }
}

