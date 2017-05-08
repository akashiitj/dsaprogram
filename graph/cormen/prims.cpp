#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)

int g[100][100];//store dis between node i and j if 1000 means no direct connection
int a[100];//used at each step for extracting vertex corresponding to minimum edge of cut
int vis[100];//represent mst 1 means included in mst
int pi[100];//used for making tree parent index of vertex

int n;

int f()//extracting vertex corresponding to minimum edge of cut
{
    int ansi=-1;
    int ans=10000;
    loop(i,0,n)
    {
        if(ans>a[i]&&vis[i]==0)
        {
            ans=a[i];
            ansi=i;
        }
    }
    return ansi;
}

void prims(int cv)
{
    while(cv!=-1)
    {
        vis[cv]=1;
        loop(i,0,n)//when some vertex is chossen we have to update
        {
            if(cv!=i&&g[cv][i]<a[i]&&vis[i]!=1)//dont update vertex already choosen thats why greedy
            {
                a[i]=g[cv][i];
                pi[i]=cv;
            }
        }
        cv=f();
    }
}

main()
{
    cin>>n;
    loop(i,0,n)
    loop(j,0,n)
    if(i!=j)g[i][j]=10000;

    int v1,v2,w;
    while(true)
    {
        cin>>v1;
        if(v1==-1)break;
        cin>>v2>>w;
        g[v1][v2]=w;
        g[v2][v1]=w;
    }
    loop(i,0,n)
    a[i]=1000;

    a[0]=0;
    pi[0]=-1;

    prims(0);

    loop(i,0,n)
    cout<<i<<" "<<pi[i]<<" "<<g[i][pi[i]]<<endl;

}

