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
    void intialiseofgraph(node graph1[],int ml)
    {
        for(int i=0; i<ml; i++)
        {
            int x;
            cout<<"enter value of "<<i<<" vertex";
            cin>>x;
            graph1[i].vertexvalue=x;
            graph1[i].ptav=NULL;

        }
    }

    void squaregraph(node gp[],int ml)
    {
      node tg[ml];
        intialiseofgraph(tg,ml);
        for(int i=0; i<ml; i++)//see how to pass size since gp is pointer so we cant use gp.length
        {
            node *hp=gp[i].ptav;
            // cout<<gp[i].vertexvalue<<"  ";
            while(hp!=NULL)
            {
                addedge(tg,gp[i].vertexvalue,hp->vertexvalue,ml);
                for(int j=0;j<ml;j++)//it search for  hp->vertexvalue means neighbour of neighboour and add in it
                {
                    if(hp->vertexvalue==gp[j].vertexvalue)
                        {
                         node* hp1=gp[j].ptav;
                         while(hp1!=NULL)
                         {
                            addedge(tg,gp[i].vertexvalue,hp1->vertexvalue,ml);
                            hp1=hp1->ptav;
                         }
                        }
                }
                hp=hp->ptav;
            }
            cout<<endl;
        }
        show(tg,ml);

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
   go.addedge(graph,1 ,2,v);
   go.addedge(graph,1 ,4,v);
    go.addedge(graph,2 ,3,v);
     go.addedge(graph,4,5,v);
       go.addedge(graph,4 ,2,v);
        go.addedge(graph,5 ,3,v);
go.show(graph,v);
go. squaregraph(graph,v);
}

