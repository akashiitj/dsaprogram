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
         del=search1(x2);
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
    friend class f;
};
class f
{
 public:
    f(){
    while(sl1.head!=NULL&&sl2.head!=NULL)
        {
            node *t1,*t2;
            t1=sl1.head->nxt;
            sl1.head->nxt=sl2.head;
            t2=sl2.head->nxt;
            sl2.head->nxt=t1;
            sl1.head=t1;
            sl2.head=t2;

        }
    }


};
main()
{
    sll sl1;
    sll sl2;
    cout<<"create first list";
    string s;
    while (true)
    {
        cin>>s;
         if(s[0]=='i')
        {
            int no;
            cin>>no;
            sl1.insert1(no);
        }
        else break;
    }
    cout<<"enter element of second list and type exit";
    while (true)
    {
        cin>>s;
         if(s[0]=='i')
        {
            int no;
            cin>>no;
            sl2.insert1(no);
        }
        else break;
    }
     while (true)
    {    cout<<"type s1 to show first list";
        cin>>s;
         if(s[0]=='s'&&s[1]=='1')
        {
        sl1.show();
        cout<<endl;
        }
        else if(s[0]=='s'&&s[1]=='2')
        {
        sl2.show();
        }
        else break;
    }
f fo;

}

