#include<iostream>
using namespace std;
struct node
    {
        node *pre;
        int x;
        node *nxt;
    }*head;
class dll
{
public:

    // node *head;
    node *check;
    dll()
    {
        head=NULL;
    }
    void insert1(int x1);
    void show();
    void delete1(int x2);
    node* search1(int x1)
    {
        node* sr=head;
        while(sr!=NULL&&sr->x!=x1)//see sr!=null comes first becoz as sr becomes null sr->x has no meaning and comand doest goes to it
        {

            sr=sr->nxt;}
        return sr;
    }
};
void dll::delete1(int x2)
{
    node *dp;
    dp=search1(x2);
    if(dp==NULL)cout<<"element not found";
   else if(dp==head)
    {
        head=dp->nxt;
       if(dp->nxt!=NULL) dp->nxt->pre=NULL;
        delete dp;
    }
    else if(dp->nxt==NULL)
    {
        dp->pre->nxt=NULL;
        delete dp;
    }
    else
    {
        dp->pre->nxt=dp->nxt;
        dp->nxt->pre=dp->pre;
        delete dp;
    }

}
void dll::insert1(int x1)
{

    node *n=new node;
    n->x=x1;
    n->nxt=head;
    if(head!=NULL)head->pre=n;
    head=n;
    n->pre=NULL;
}
void dll::show()
{
    node *sh;
    sh=head;
    if(sh==NULL)cout<<"list is empty";
    while(sh!=NULL)
    {
        cout<<sh->x<<"   ";
        sh=sh->nxt;
    }
   // check=search1(4);
    //if(check==NULL)cout<<"nhjhhh"<<endl;

}
char rf(string s)
{   dll dllo;

    bool expec[52]={false};
    node *ptdll[52]={NULL};//pointing to doubly link list node
    for(int i=0;i<s.length();i++)
    {
        if((expec[(int)s[i]-65]==false )&&(ptdll[(int)s[i]-65]==NULL))
        {
          dllo.insert1((int)s[i]-65)  ;
          ptdll[(int)s[i]-65]=head;
        }
        else if(expec[(int)s[i]-65]==false &&ptdll[(int)s[i]-65]!=NULL)
        {
            expec[(int)s[i]-65]=true;
            dllo.delete1((int)s[i]-65);

        }
    }
    dllo.show();
}
main()
{
    rf("BCBccCA");
}
