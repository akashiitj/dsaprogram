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
    sll sllo1,sllo2;
    string s;
    cout<<"make first link list by reapedly insrtion and press exit to stop";
    while(true)
    {
        cin>>s;
        if(s[0]=='i')
        {
            int no;
            cin>>no;
            sllo1.insert1(sllo1.head,no);
        }

        else if(s[0]=='s')
            sllo1.show(sllo1.head);
        else break;
    }
    cout<<"enter element of second list and type exit to stop";
    while(true)
    {
        cin>>s;
        if(s[0]=='i')
        {
            int no;
            cin>>no;
            sllo2.insert1(sllo2.head,no);
        }

        else if(s[0]=='s')
            sllo2.show(sllo2.head);
        else break;
    }
    node *tp=sllo1.head;//tp means traversing pointer in first list;
    while(tp!=NULL&&sllo2.head!=NULL)
    {
        node *t1=tp->nxt;
        tp->nxt=sllo2.head;
        node *t2=  sllo2.head->nxt;
        sllo2.head->nxt=t1;
        sllo2.head=t2;
        tp=t1;
    }
    sllo1.show(sllo1.head);cout<<endl;
    sllo2.show(sllo2.head);
}

