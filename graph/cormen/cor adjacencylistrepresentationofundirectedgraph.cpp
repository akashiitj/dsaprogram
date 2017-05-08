#include<iostream>
using namespace std;
struct node
{
    int vertexvalue;
    node* ptav;//pointing to adjacent vertex
};
class graphc
{
public:
     int rvnk(node gp[],int ml,int k)//return vertexno to key
    {
        for(int i=0; i<ml; i++)
        {
            if (gp[i].vertexvalue==k)return gp[i].vertexno;
        }
    }
    node *rpk(node gp[],int ml,int k)//return pointer to key
    {
        for(int i=0; i<ml; i++)
        {
            if (gp[i].vertexvalue==k)return gp[i].ptav;
        }
    }
    void addedge(node gp[],int viwwwta,int vtba,int ml)//vertex in which we want to add;vertex to be added
    {
        for (int i=0;i<ml;i++)
        {
            if( viwwwta==gp[i].vertexvalue)
            {
                node *n=new node;
                node *n1=gp[i].ptav;
                n->vertexvalue=vtba;
                gp[i].ptav=n;
                n->ptav=n1;
                break;
            }
        }

    }
    void show(node gp[],int ml)
    {
       //graph printing
   for(int i=0; i<ml; i++)//see how to pass size since gp is pointer so we cant use gp.length
   {   node *hp=gp[i].ptav;
       cout<<gp[i].vertexvalue<<"  ";
       while(hp!=NULL)
       {
           cout<<hp->vertexvalue<<"  ";
           hp=hp->ptav;
       }
       cout<<endl;
   }
    }
};
main()
{
    int v;
    cout<<"enter no of vertex in graph";
    cin>>v;
    node graph[v];//formation of array of vertex
    for(int i=0; i<v; i++)
    {
        int x;
        cout<<"enter value of "<<i<<" vertex";
        cin>>x;
        graph[i].vertexvalue=x;
        graph[i].ptav=NULL;

    }
    for(int i=0; i<v; i++)//print vertex
        cout<<graph[i].vertexvalue<<"  ";
   graphc go;
   go.addedge(graph,2 ,5,v);
   go.show(graph,v);
}
