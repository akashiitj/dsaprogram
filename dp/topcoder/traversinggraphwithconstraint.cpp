#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)

vector<int> graph[1000];
vector<int> dist[1000];
int mindis[100][100];//minimum itna distance cover karke we will reach i vertex eith j money left
int mark[100][100];

int cost[100];

int n;
int tmi;

int infi=100;

int cv,ml;//current chosen vertex with minimum path cost,money left

void vsmin()
{
    int x=infi;
    int ans=-1;
    cv=-1;
    ml=-1;
    loop(i,1,n+1)
    {
        loop(j,0,tmi+1)
        {
            if(mindis[i][j]<x&&mark[i][j]==0)
            {
                x=mindis[i][j];
                cv=i;
                ml=j;
            }
        }

    }

}

void da()
{
    while(cv!=-1&&ml!=-1)
    {
        mark[cv][ml]=1;
        loop(i,0,graph[cv].size())
        {
            int vn=graph[cv][i];

            if(mark[vn][ml-cost[vn]]==0&&ml>=cost[vn]&&mindis[vn][ml-cost[vn]]>mindis[cv][ml]+dist[cv][i])
            {
                mindis[vn][ml-cost[vn]]=mindis[cv][ml]+dist[cv][i];
            }

        }
        vsmin();//it return cv and ml with minimum distance

    }
}

void print()
{
    loop(i,1,n+1)
    {
        loop(j,0,tmi+1)
        {
            cout<<mindis[i][j]<<" ";
        }
        cout<<endl;
    }

}

main()
{

    cin>>n>>tmi;
    ml= tmi;
    while(true)
    {
        int v1,v2,d;
        cin>>v1;
        if(v1==-1)break;
        cin>>v2>>d;
        graph[v1].push_back(v2);
        dist[v1].push_back(d);
    }
    loop(i,1,n+1)
    {
        cin>>cost[i];
        loop(j,0,tmi+1)
        {
            mindis[i][j]=infi;
            mark[i][j]=0;
        }
    }
    cout<<"enter source vertex "<<endl;

    cin>>cv;

    mindis[cv][tmi]=0;

    da();
    print();


}

7
