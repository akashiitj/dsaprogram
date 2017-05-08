#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct  node * nxt;

};
void insert1(struct node **head1,struct node **tail1,int val)
{
    struct node* n=new node;
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
        cout<<hc->val<<" ";
        hc=hc->nxt;
    }
}
void add(node *l1,node *l2,node **rh,node **rt)//r=result of sum
{   string s1,s2,s3;


    while(l1!=NULL)
    {
        stringstream ss;
        ss<<l1->val;
        s1=s1+ss.str();
        l1=l1->nxt;
    }
    while(l2!=NULL)
    {
        stringstream ss;
        ss<<l2->val;
        s2=s2+ss.str();
        l2=l2->nxt;
    }
    cout<<s1<<" "<<s2<<endl;
    int sum=atoi(s1.c_str())+atoi(s2.c_str());


    stringstream ss;
        ss<<sum;
        s1=ss.str();
        cout<<s1<<" "<<s1.length()<<endl;
    for(int i=0;i<s1.length();i++)
    {   cout<<"fd"<<endl;
        insert1(rh,rt,s1[i]-48);
    }
}
main()
{
    struct node *l1=NULL, *t1=NULL,*l2=NULL,*t2=NULL,*rh=NULL,*rt=NULL;
    char s;
    while(1)
    {
        //cin>>s;
        cin>>s;
        if(s=='i')
        {
            int no;
            //scanf("%d",&no);
            cin>>no;
            insert1(&l1,&t1,no);
        }
         if(s=='q')
        {
            int no;
            //scanf("%d",&no);
            cin>>no;
            insert1(&l2,&t2,no);
        }
        if(s=='f')
        {
            add(l1,l2,&rh,&rt);
        }
        if(s=='s')
            show(rh);
    }
}
