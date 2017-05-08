#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
}  *ptr[10];

node* traverse(node *q)
{   //cout<<"traverse";
    while (q->next != NULL)
    q = q->next;
    return q;
}
void print(node *q)
{    //cout<<"print";
     while (q ->next!= NULL)
        {cout<<q->next->data<<"    ";q=q->next;}
}
void insert1(int x)
{   //cout<<"insert";
    node *p;
  //  p = new node;
    p = traverse(ptr[x%10]);
    node *n;
    n=new node;
    n->data=x;
    n->next=NULL;
    p->next=n;
}
int main(){
    for(int i=0;i<10;i++){
    ptr[i] = new node;
    ptr[i]->data=0;
    ptr[i]->next = NULL;}
    int x;
   // insert1(5);
   // insert1(15);insert1(25);
    print(ptr[5]);

   while(x!=78)
    {
     cin>>x;
     insert1(x);
    }
     for(int i=0;i<10;i++){
    print(ptr[i]);cout<<endl;
    }

    /*
node *n;node *n1;
node *ptr[10];int c=0;n1=ptr[0];
while(c!=4)
{node *n=new node;
node *t=new node;
int x;
cin>>x;
if(x%10==1){if(c==0)ptr[0]=n;n->data=x ;n->next=t;t->next=NULL;c++;}

}

cout<<n1->data;*/
return 0;
}
