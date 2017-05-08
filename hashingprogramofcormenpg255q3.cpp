#include<iostream>
using namespace std;
class hashing
{   public:
    class node
    {   public:
        int key;//means no to be inserted
        node *nxt;
    } *head[10], *tail[10];
    hashing()
    {   for(int i=0;i<10;i++)
        {
         head[i]=NULL;
         tail[i]=NULL;
        }
    }
    void insert1(int x)
    { int correspondingkey=x%10;
         if(tail[correspondingkey]==NULL)
        {
            node* n=new node;
            n->key=x;
            tail[correspondingkey]=n;
            head[correspondingkey]=n;
            n->nxt=NULL;
        }
        else
        {
            node* n=new node;
            n->key=x;
            n->nxt=NULL;
            tail[correspondingkey]->nxt=n;
            tail[correspondingkey]=n;
        }
    }
    node *search1(int nts)
    {
        int sh=nts%10;
        node *sp=head[sh];
        while(sp!=NULL&&sp->key!=nts)
            sp=sp->nxt;
        return sp;
    }
    void delete1(int x2)
    {
        node* del;
        del=search1(x2);
         if(del==NULL)cout<<"element not found";
        else{
        node* del1=head[x2%10];
        node* del2=head[x2%10]->nxt;

        if(del==head[x2%10])
        {    if(del==tail[x2%10])tail[x2%10]=NULL;
            head[x2%10]=head[x2%10]->nxt;
        }

        else
        {
            while(del2!=NULL&&del2->key!=x2)
            {
                del1=del1->nxt;
                del2=del2->nxt;
            }
            if(del2->nxt==NULL)tail[x2%10]=del1;
            del1->nxt=del2->nxt;
            delete del2;
        }
        }
    }
    void show()
    {   node *sho;
        for(int i=0;i<10;i++)
        {   sho=head[i];
            while(sho!=NULL)
                {cout<<sho->key<<"   ";sho=sho->nxt;}
            cout<<endl;
        }
    }

};
main()
{
    hashing ho;
    hashing *hp;
    hp=&ho;
   //hp->node *np;

    string str;
  while(true)
  {
    cin>>str;
    if(str[0]=='i')
    {int no;cin>>no;hp->insert1(no);}
    if(str[0]=='d'){
            int no;
    cin>>no;
    hp->delete1(no);
    }
    if(str[0]=='s')
        hp->show();

  }
    hp->insert1(23);
    hp->show();
}
