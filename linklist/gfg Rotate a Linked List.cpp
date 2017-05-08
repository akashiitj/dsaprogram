#include<iostream>
using namespace std;
 struct node//we cant create class here again for this purpose as in java
    {
        int key;
        node *nxt;
    };
class sll
{
public:
    node *head,*tail;
    sll()
    {
        head=NULL;
        tail=NULL;
    }
    void insert1(node *hp,int x)
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
    void show(node *sp)//head pointer to show
    {


        if(sp==NULL)cout<<"list is empty";
        while(sp!=NULL)
        {
            cout<<sp->key<<"  ";

            sp=sp->nxt;
        }
        cout<<endl;

    }
    void swapp(node *hp,int k)
    {
        int c=1;
        node *n=hp;
        while(c!=k&&hp->nxt!=NULL)
        {

            hp=hp->nxt;
            c++;
        }
        if(hp->nxt!=NULL)
        {
         tail->nxt=head;
         head=hp->nxt;
         hp->nxt=NULL;
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
            p->insert1(sllo.head,no);
        }
        if(s[0]=='r')
        {
            int no;
            cin>>no;
            p->swapp(sllo.head,no);
        }
        if(s[0]=='s')
            p->show(sllo.head);
    }
}


