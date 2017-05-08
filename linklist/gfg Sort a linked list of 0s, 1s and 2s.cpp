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
    void sorting()
    {
        int c1=0,c2=0,c3=0;
        node *t=head,*ap=head;
        while(t!=NULL)
        {
            if(t->key==0)c1++;
            else if(t->key==1)c2++;
            else c3++;
            t=t->nxt;
        }
        int t1=0,t2=0,t3=0;
        while(ap!=NULL)
        {
           while(t1<c1){ap->key=0;ap=ap->nxt;t1++;}
           while(t2<c2){ap->key=1;ap=ap->nxt;t2++;}
           while(t3<c3){ap->key=2;ap=ap->nxt;t3++;}

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
        if(s[0]=='d')
        {
             p->sorting();

        }
        if(s[0]=='s')
            p->show();
    }
}

