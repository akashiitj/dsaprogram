#include<iostream>
#include<queue>
using namespace std;
//int visit[4]= {0};
struct node
{
    int vertexno;
    int vertexvalue;
    node* ptav=NULL;//pointing to adjacent vertex
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
    node *rpk(node gp[],int ml,int k)//return pointer to next to key
    {
        for(int i=0; i<ml; i++)
        {
            if (gp[i].vertexvalue==k)return gp[i].ptav;
        }
    }
    node *rpk11(node gp[],int ml,int k)//return pointer to key
    {
        node *hp4=gp;
        for(int i=0; i<ml; i++)
        {
            if (gp[i].vertexvalue==k)return hp4;
            hp4++;
        }
    }

    void addedge(node gp[],int viwwwta,int vtba,int ml)//vertex in which we want to add;vertex to be added
    {
        node *hp=rpk11(gp,ml,viwwwta);
        node *n=new node;
        node *hp11=hp->ptav;
        hp->ptav=n;
        n->vertexvalue=vtba;
        n->ptav=hp11;


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
    int v;
    cout<<"enter no of vertex in graph";
    cin>>v;
    node graph[v];//formation of array of vertex
    for(int i=0; i<v; i++)
    {
        int x;
        cout<<"enter value of "<<i<<" vertex";
        cin>>x;
        graph[i].vertexno=i;
        graph[i].vertexvalue=x;
        graph[i].ptav=NULL;

    }
    for(int i=0; i<v; i++)//print vertex
        cout<<graph[i].vertexvalue<<"  ";
    graphc go;
    go.addedge(graph,11 ,2,v);
    go.addedge(graph,2,11,v);
    go.addedge(graph,2,3,v);
    go.addedge(graph,3 ,2,v);
    go.addedge(graph,11,4,v);
    go.addedge(graph,4 ,11,v);
    go.addedge(graph,4 ,55,v);
    go.addedge(graph,55 ,4,v);
    go.addedge(graph,4 ,6,v);
    go.addedge(graph,6 ,4,v);
    go.addedge(graph,55 ,6,v);
    go.addedge(graph,6 ,55,v);
    go.addedge(graph,55,7,v);
    go.addedge(graph,7 ,55,v);
    go.addedge(graph,6,7,v);
    go.addedge(graph,7,6,v);
    go.addedge(graph,6,8,v);
    go.addedge(graph,8,6,v);
    go.addedge(graph,7,8,v);
    go.addedge(graph,8,7,v);

    //  go.addedge(graph,55,4 ,v);
    go.show(graph,v);

}


