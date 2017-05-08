#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)

vector<int> graph[1000];
vector<int> dist[1000];
int mindis[1000];
int mark[1000];

int n;

int infi=10000000;

int vsmin()
{
    int x=infi;
    int ans=-1;
    loop(i,1,n)
    {
        if(mark[i]==0&&mindis[i]<x)
        {

            x=mindis[i];
            ans=i;
        }
    }
    return ans;
}

void da(int sv)
{

    while(sv!=-1)
    {

        mark[sv]=1;

        loop(i,0,graph[sv].size())
        {
            int vn=graph[sv][i];
            if(mark[vn]==0&&mindis[vn]>mindis[sv]+dist[sv][i])
            {
                mindis[vn]=mindis[sv]+dist[sv][i];
            }
        }
        sv=vsmin();
    }
}


main()
{

    cin>>n;
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
        mindis[i]=infi;
        mark[i]=0;
    }
    cout<<"enter source vertex"<<endl;
    int s;
    cin>>s;
    mindis[s]=0;

    da(s);

    loop(i,1,n+1)
    {
        cout<<mindis[i]<<" ";
    }

}
