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
    void swapingusingkey()
    {
        node *wp;
        wp=head;
        while(wp!=NULL&&wp!=tail)
        {
            int t=wp->key;
            wp->key=wp->nxt->key;
            wp->nxt->key=t;
            wp=wp->nxt->nxt;

        }
    }
    void swappingusinglinkexchange()
    {   node *wp;
        if(head->nxt!=NULL)
        {
            wp=head;
            head=head->nxt;
        }
        while(wp->nxt!=NULL&&wp->nxt->nxt!=NULL)
        {
            node *t1,*t2;
            t1=wp;
            t2=wp->nxt;
            wp->nxt=wp->nxt->nxt;
            t2->nxt=t1;
            wp=t1->nxt;
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
        if(s[0]=='s'&&s[1]=='w'&&s[2]=='k')
        {
            //int no;
            //cin>>no;
            p->swapingusingkey();
        }
         if(s[0]=='s'&&s[1]=='w'&&s[2]=='l')
        {
            //int no;
            //cin>>no;
            p->swappingusinglinkexchange();
        }
        if(s[0]=='s')
            p->show();
    }
}
