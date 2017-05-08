
#include<iostream>
#include<stack>
using namespace std;

struct node
{
    int val;
    struct  node * nxt;

};
void insert1(struct node **head1,struct node **tail1,int val)
{
    struct node* n=new node();
    //scanf("%d", n->val);
    n->val=val;
    n->nxt=NULL;
    if(*tail1==NULL)
    {
        *head1=n;
        *tail1=*head1;
    }

    else
    {
        (*tail1)->nxt=n;
        (*tail1)=n;
    }
}
void show(struct node *hc)//its head copy
{
    while(hc!=NULL)
    {
//        printf("%d ",hc->val);
        cout<<hc->val<<" ";
        hc=hc->nxt;
    }
    cout<<endl;
}
void f(struct node *hc)
{   stack<int> s;
cout<<"c  "<<endl;
    node *p1=hc;
    node *p2=hc;
    while(p2->nxt&&p2->nxt->nxt)
    { cout<<"c1  "<<endl;
        p1=p1->nxt;
        p2=p2->nxt->nxt;
    }
    p2=p1->nxt;
    while(p2)
    {
        s.push(p2->val);
        p2=p2->nxt;
    }
    while(!s.empty())
    {   //cout<<"c4  "<<endl;
        hc->val=hc->val-s.top();
        s.pop();
        hc=hc->nxt;
    }
}
main()
{
    struct node *head=NULL, *tail=NULL;
    char s;
    while(1)
    {
        //cin>>s;
        //scanf("%c",&s);
        cin>>s;
        if(s=='i')
        {
            int no;
            //scanf("%d",&no);
            cin>>no;
            insert1(&head,&tail,no);
        }
        /*if(s[0]=='d')
        {
            int no;
            //cin>>no;
              scanf("%d",&no);
            delete1(&head,no);
        }*/
         else if(s=='s')
        show(head);
        else
        {
            f(head);
        }
    }
}
