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
    void insert1(node *hp,int x)
    {node* n=new node;
    n->key=x;
        if(tail==NULL)
        {

           // n->key=x;
            tail=n;
            head=n;
            n->nxt=NULL;
        }
        else
        {
           // node* n=new node;
          //  n->key=x;
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
    node* search1(node *sr,int x1)
    {

        while(sr!=NULL&&sr->key!=x1)//see sr!=null comes first becoz as sr becomes null sr->x has no meaning and comand doest goes to it
        {
            sr=sr->nxt;
        }
        return sr;
    }
    void delete1(node *dp,int x2)
    {
        node* del;
         del=search1(dp,x2);
        if(del==NULL)cout<<"element not found";
        else{
        node* del1=head;
        node* del2=head->nxt;


         if(del==head)
        {    if(del==tail)tail=NULL;
            head=head->nxt;
        }
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
            p->insert1(sllo.tail,no);
        }
        if(s[0]=='d')
        {
            int no;
            cin>>no;
            p->delete1(sllo.head,no);
        }
        if(s[0]=='s')
            p->show(sllo.head);
    }
}

