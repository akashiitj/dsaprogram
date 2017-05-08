#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;
int u;
struct node
{
    int x;
    int val;
    node *next1;
};
void addedge(node a[],int *q,int src,int dest,int dist,int v)
{

    node *ptr=new node();
    node *head=a[src].next1;
    ptr->x=dest;
    ptr->val=1000;
    a[src].next1=ptr;
    ptr->next1=head;
    q[(src*v)+dest]=dist;
}
void print(node a[],int v)
{

    for(int i=0;i<v;i++)
    {
        cout<<a[i].x<<"("<<a[i].val<<")"<<"\t";
        node *ptr1=a[i].next1;
        while(ptr1!=NULL)
        {
            cout<<ptr1->x<<"\t";
            ptr1=ptr1->next1;
        }
        cout<<"\n";
    }
}
int minimum(int *q,int v,int o,int t)
{
    int k;
    int mini=q[o*v+0];
    for(int i=0;i<v&&i!=o&&i!=t;i++)
    {

        if(q[o*v+i]<mini)
        {
            k=i;
            mini=q[o*v+i];
        }
    }
    return k;
}

int main()
{
    int v,r,m,k,t;
    cout<<"enter no. of vertices";
    cin>>v;
    u=v;
  node graph[v];
  int d[v][v];
  memset(d,2,sizeof d);

  cout<<"enter values of graph starting from 0"<<"\t";
    for(int i=0;i<v;i++)
    {
        graph[i].val=0;
        cin>>graph[i].x;
        graph[i].next1=NULL;
    }
   /* while(cin.get()!='\n')
    {
        cin>>m>>k;
        addedge(graph,m,k);
    }*/
    //or
 addedge(graph,&d[0][0],0,1,10,v);
 addedge(graph,&d[0][0],0,3,30,v);
 addedge(graph,&d[0][0],0,4,100,v);
 addedge(graph,&d[0][0],1,2,50,v);
 addedge(graph,&d[0][0],2,4,10,v);
addedge(graph,&d[0][0],3,2,20,v);
 addedge(graph,&d[0][0],3,4,60,v);
 cout<<"enter vertex no. through which u want shortest path of all vertices"<<endl;
    cin>>r;
    vector<int> v1;
    v1.push_back(r);
    t=r;
    while(v1.size()!=v)
    {
 int l=minimum(&d[0][0],v,r,t);
         t=l;
    v1.push_back(l);
    for(int i=0;i<v&&i!=r;i++)
    {
        d[0][i]=min(d[0][i],d[0][v1.back()]+d[v1.back()][i]);
    }

    }

 print(graph,v);
 for(int i=0;i<v;i++)
 {
     cout<<d[0][i]<<endl;
 }
 return 0;
}
