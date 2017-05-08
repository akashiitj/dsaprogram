#include<bits/stdc++.h>
#include<queue>
using namespace std;
//int visit[4]= {0};
struct node
{
    int vertexno;
    int vertexvalue;
    node* ptav;//pointing to adjacent vertex
};
struct vi//vertex information when searched from a given sourece
{
    int dfs=-5;//distance from source
    node* potv=NULL;//parent of that vertex
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
    node *rpk1(node gp[],int ml,int k)//return pointer to key
    {
        node *hp4=gp;
        for(int i=0; i<ml; i++)
        {
            if (gp[i].vertexvalue==k)return hp4;
            hp4++;
        }
    }

    void addedge(node gp[],int viwwwta,int vtba,int ml)//vertex in which we want to add;vertex to be added//by value
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
    void bfs(node gp[],int ml,int svk)//svk source vertex key
    {
        vi vic[ml];
        vic[rvnk( gp, ml, svk)].dfs=0;
        vic[rvnk( gp, ml, svk)].potv=NULL;
        queue<int>q;
        int visit[ml];
        int c=0;//it count distance of vertex from source
        for(int i=0; i<ml; i++)
        {
            visit[i]=0;
        }
        int vn=rvnk(gp,ml,svk);
        //  cout<<"vn of source "<<vn<<endl;
        q.push(svk);
        visit[vn]=1;
        while(!q.empty())
        {
            int s=q.front();
            node *np=rpk(gp,ml,s);
            int vnof=rvnk( gp, ml, s);//vertex no of front element
            // cout<<"vnof "<<vnof;
            cout<<s<<"  ";
            q.pop();
            c= vic[rvnk(gp,ml,s)].dfs;//first you do c++ here c=parent ka distance from source
            node *hp2=rpk1(gp,ml,s);
            while(np!=NULL)
            {
                //cout<<np->vertexvalue<<"  ";
                if(visit[rvnk(gp,ml,np->vertexvalue)]==0)
                {
                    // cout<<np->vertexvalue<<"  ";
                    vic[rvnk(gp,ml,np->vertexvalue)].dfs=c+1;
                    //cout<<"hp2 "<<hp2->vertexvalue<<endl;
                    vic[rvnk(gp,ml,np->vertexvalue)].potv=hp2;
                    q.push(np->vertexvalue);
                    visit[rvnk(gp,ml,np->vertexvalue)]=1;

                }
                np=np->ptav;
            }
            cout<<endl;

        }
        showvertexinformation(vic,ml);
        povfs(gp,vic, 1,5 , ml);
    }
    void showvertexinformation(vi vid[],int ml)//vertex information duplicate
    {
        node *a;
        for(int i=0; i<ml; i++)
        {
            cout<<vid[i].dfs<<"  ";
            a=vid[i].potv;
            //if(a!=NULL)
            //  cout<<a->vertexvalue<<endl;
        }
    }
    void povfs(node gp[],vi vic[],int s,int v,int ml)//path of vertex from source
    {
        node *hp1=vic[rvnk(gp,ml,v)].potv;
        cout<<hp1->vertexvalue<<endl;
        while(hp1!=NULL)
        {
            cout<<hp1->vertexvalue<<"  ";
            hp1=vic[rvnk(gp,ml,hp1->vertexvalue)].potv;
        }
        cout<<endl;
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
    go.addedge(graph,1 ,2,v);
    go.addedge(graph,2,1,v);
    go.addedge(graph,2,3,v);
    go.addedge(graph,3 ,2,v);
    go.addedge(graph,1,4,v);
    go.addedge(graph,4 ,1,v);
    go.addedge(graph,4 ,5,v);
    go.addedge(graph,5 ,4,v);
    go.addedge(graph,4 ,6,v);
    go.addedge(graph,6 ,4,v);
    go.addedge(graph,5 ,6,v);
    go.addedge(graph,6 ,5,v);
    go.addedge(graph,5,7,v);
    go.addedge(graph,7 ,5,v);
    go.addedge(graph,6,7,v);
    go.addedge(graph,7,6,v);
    go.addedge(graph,6,8,v);
    go.addedge(graph,8,6,v);
    go.addedge(graph,7,8,v);
    go.addedge(graph,8,7,v);

    //  go.addedge(graph,5,4 ,v);
    go.show(graph,v);
    go.bfs(graph,v,1);
}

