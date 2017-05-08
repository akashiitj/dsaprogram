#include<bits/stdc++.h>

using namespace std;
//int visit[4]= {0};

#define loop(i,a,b)      for(int i=a;i<b;i++)

struct node
{
    int vn;//vertex no
    int vv;//vertex value
    node* ptav;//pointing to adjacent vertex
};

struct vi//vertex information when searched from a given sourece
{
    int d=-5;//distance from source
    int potv=NULL;//parent of that vertex
};

node v[1000];
vi vibfs[1000];
int n;//total no of nodes

void addedge(int i,int j)// i and j are node number
{
    node *n1=new node;
    n1->ptav=v[i].ptav;
    n1->vn=j;
    n1->vv=v[j].vv;
    v[i].ptav=n1;
}

queue<int> q;
int visit[1000]= {0};

void bfs(int svn)//source vertex no
{
    vibfs[svn].d=0;
    vibfs[svn].potv=-1;
    visit[svn]=1;
    q.push(svn);
    while(q.empty()!=1)
    {
        int pvn=q.front();//present vertex no
        q.pop();
        node *n1=v[pvn].ptav;
        int d=vibfs[pvn].d+1;
        while(n1!=NULL)
        {
            int cvn=n1->vn;//child vertex no
            if(visit[cvn]!=1)
            {
                vibfs[cvn].d=d;
                vibfs[cvn].potv=pvn;
                q.push(cvn);
                visit[cvn]=1;
            }
            n1=n1->ptav;
        }
    }

}

void showbfs()
{
    loop(i,0,n)
    cout<<vibfs[i].d<<" "<<vibfs[i].potv<<endl;
}

void show()
{
    //graph printing
    for(int i=0; i<n; i++)//see how to pass size since gp is pointer so we cant use gp.length
    {
        node *hp=v[i].ptav;
        cout<<v[i].vn<<"  ";
        while(hp!=NULL)
        {
            cout<<hp->vn<<"  ";
            hp=hp->ptav;
        }
        cout<<endl;
    }
}
main()
{
    int v1,v2;
    cout<<"enter total no of nodes"<<endl;
    cin>>n;
    cout<<"enter values of nodes"<<endl;
    loop(i,0,n)
    {
        cout<<i<<": ";
        cin>>v[i].vv;
        v[i].vn=i;
        v[i].ptav=NULL;
    }
    cout<<"enter 2 vertex no in which you wanted to add edge and type -1 to end"<<endl;
    while(true)
    {
        cin>>v1;
        if(v1==-1)break;
        cin>>v2;
        addedge(v1,v2);
        addedge(v2,v1);
    }
    show();
    bfs(0);
    showbfs();



}

