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
    void addedge(node gp[],int viwwwta,int vtba,int ml)//vertex in which we want to add;vertex to be added
    {
        for (int i=0; i<ml; i++)
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
    node *transpose(node gp[],int ml)
    {
        node tg[ml];
        intialiseofgraph(tg,ml);
        for(int i=0; i<ml; i++)//see how to pass size since gp is pointer so we cant use gp.length
        {
            node *hp=gp[i].ptav;
            // cout<<gp[i].vertexvalue<<"  ";
            while(hp!=NULL)
            {
                addedge(tg,hp->vertexvalue,gp[i].vertexvalue,ml);
                hp=hp->ptav;
            }
            cout<<endl;
        }
        show(tg,ml);
        return tg;
    }
    void show(node gp[],int ml)
    {
        //graph printing
        for(int i=0; i<ml; i++)//see how to pass size since gp is pointer so we cant use gp.length
        {
            node *hp=gp[i].ptav;
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
    graphc go;
    int v;
    cout<<"enter no of vertex in graph";
    cin>>v;
    node graph[v];//formation of array of vertex
    node *graph1;
    go. intialiseofgraph(graph,v);
    for(int i=0; i<v; i++)
        cout<<graph[i].vertexvalue<<"  ";

    go.addedge(graph,2 ,1,v);
    go.addedge(graph,2 ,3,v);
    go.addedge(graph,1 ,4,v);
    go.addedge(graph,4 ,2,v);
    go.show(graph,v);
    graph1=go.transpose(graph,v);
    //go.show(graph1,1);
}

