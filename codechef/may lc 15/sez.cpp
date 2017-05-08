#include<bits/stdc++.h>
using namespace std;


#define fast      ios_base::sync_with_stdio(false)
#define frmlty     int test_case;cin>>test_case;while(test_case--)
int mini1=-10000;

#define loop(i,a,b)      for(int i=a;i<b;i++)

vector<int > graph[201];
int degree[201];
int visit[201];

vector<int> v;

void dfs(int i)
{
    visit[i]=1;
    v.push_back(i);
    loop(x,0,graph[i].size())
    {
        if(visit[graph[i][x]]==0)
        {
            dfs(graph[i][x]);
        }
    }
}

int av[201];

int f()
{
    int ans=10000;
    int ansi=-1;
    loop(i,0,v.size())
    {
        if(av[v[i]]==0&&degree[v[i]]<ans)
        {
            ans=degree[v[i]];
            ansi=v[i];
        }
    }
         return ansi;
}

int main()
{
    fast;
    //declare variable here
    int n;
    int m,x,y;
    cin>>n>>m;
    loop(i,1,n+1)
    {
        degree[i]=0;
        visit[i]=0;
        av[0];
    }
    while(m--)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }
    int x1,y1;
    int ans=0;
  //  cout<<"1"<<endl;
    loop(i,1,n+1)
    {
        if(visit[i]==0)
        {
            dfs(i);
            //loop(i,0,v.size())
           // cout<<v[i]<<" ";
           // cout<<endl;
            x1=0;
            y1=0;
            int sv=f();//return vertex with minimum degree
            while(sv!=-1)
            {   av[sv]=1;
                x1++;
                loop(j,0,graph[sv].size())
                {
                    if(av[graph[sv][j]]==0)
                    {  av[graph[sv][j]]=1;
                        y1++;
                        loop(k,0,graph[graph[sv][j]].size())
                        {
                            degree[graph[graph[sv][j]][k]]--;
                        }
                    }
                }
                sv=f();
            }

            if((x1-y1)>0)ans=ans+x1-y1;
            if((x1-y1)>mini1)mini1=x1-y1;

            v.clear();
        }

        //cout<<x1-y1<<"  v  "<<endl;

    }
if(ans>0)
cout<<ans<<endl;
else cout<<mini1<<endl;
}
