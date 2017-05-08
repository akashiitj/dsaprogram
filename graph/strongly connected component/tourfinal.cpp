#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false)
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>

#define pb        push_back
#define mp        make_pair



#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

vi graph[1001],grapht[1001];
int visit[1001];
vi outtime;

int com=0;

void dfs(int sv)
{
    visit[sv]=1;
    com++;
    loop(i,0,graph[sv].size())
    {
        if(visit[graph[sv][i]]==0)
            dfs(graph[sv][i]);
    }
    outtime.pb(sv);

}

int ans=0;


void rdfs(int sv)
{
    visit[sv]=1;
    ans++;
    loop(i,0,grapht[sv].size())
    {
        if(visit[grapht[sv][i]]==0)
            rdfs(grapht[sv][i]);
    }

}

int main()
{
    fast;
    frmlty
    {
        int n;
        cin>>n;

        for (int i = 1; i <= n; ++i ) {
            visit[ i ] = 0;
            graph[ i ].clear();
            grapht[ i ].clear();
            outtime.clear();
        }
        loop(i,1,n+1)
        {
            visit[i]=0;
            int x;
            cin>>x;
            loop(j,0,x)
            {
                int y;
                cin>>y;
                graph[y].pb(i);
                grapht[i].pb(y);
            }
        }



        loop(i,1,n+1)
        {
            if(visit[i]==0)
                dfs(i);
        }

        int startvertex=outtime[outtime.size()-1];
        // cout<<startvertex<<endl;
        loop(i,1,n+1)
        visit[i]=0;

        com=0;
        ans=0;
        dfs(startvertex);


        loop(i,1,n+1)
        visit[i]=0;
        if(com!=n)
            ans=0;
        else{
            rdfs(startvertex);
        }
        cout<<ans<<endl;
    }


    return 0;
}

