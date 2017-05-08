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
   /* node* search1(int x1)
    {
        node* sr=head;
        while(sr!=NULL&&sr->key!=x1)//see sr!=null comes first becoz as sr becomes null sr->x has no meaning and comand doest goes to it
        {
            sr=sr->nxt;
        }
        return sr;
    }*/
    void delete1()
    {

    if(head!=NULL)
    { if(head->nxt==NULL)tail=NULL;
    head=head->nxt;
    }
    else
    cout<<"queue is empty"<<endl;
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
            //int no;
          //  cin>>no;
            p->delete1();
        }
        if(s[0]=='s')
            p->show();
    }
}

