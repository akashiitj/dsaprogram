#include<iostream>
using namespace std;
class sll
{
public:
    struct node
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
    node* search1(int x1)
    {
        node* sr=head;
        while(sr!=NULL&&sr->key!=x1)//see sr!=null comes first becoz as sr becomes null sr->x has no meaning and comand doest goes to it
        {
            sr=sr->nxt;
        }
        return sr;
    }
    void delete1(int x2)
    {
        node* del;
        node* del1=head;
        node* del2=head->nxt;
        del=search1(x2);

        if(del==head)
        {
            if(del==tail)tail=NULL;
            head=head->nxt;
        }
        else if(del==NULL)cout<<"element not found";
        else
        {
            while(del2!=NULL&&del2->key!=x2)
            {
                del1=del1->nxt;
                del2=del2->nxt;
            }
            if(del2->nxt==NULL)tail=del1;
            del1->nxt=del2->nxt;
            delete del2;
        }
    }
};
main()
{
    sll sllo1,sllo2;
    sll *p1,*p2;
    p1=&sllo1;
    p2=&sllo2;
   // string s;
   cout<<"enter no in set 1 using space and press enter and then no of set 2 using space and then enter";
    while(true)
    {       int no;
            cin>>no;
            p1->insert1(no);
            if(cin.get()=='\n')goto rp;
    }
    rp:
    p1->show();
    while(true)
    {   int no;
        cin >>no;
        p2->insert1(no);       if(cin.get()=='\n')break;
    }
    p1->tail->nxt=p2->head;
    p1->show();

}


