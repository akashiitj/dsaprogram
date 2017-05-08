#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second

vi g[100];
int vis[100]= {};
int discovery[100]= {};
int backedge[100];
int parent[100];

vector<pii > bridge;

int time1=0;

void dfs(int sv)
{
    vis[sv]=1;
    time1++;
    discovery[sv]=time1;
    backedge[sv]=time1;
    loop(i,0,g[sv].size())
    {
        if(vis[g[sv][i]]==0)
        {
            parent[g[sv][i]]=sv;
            dfs(g[sv][i]);
            backedge[sv]=miN( backedge[sv], backedge[g[sv][i]]);
            if(backedge[g[sv][i]]>discovery[sv])
                bridge.pb(mp(g[sv][i],sv));
        }
        else if(g[sv][i]!=parent[sv])
            backedge[sv]=miN( backedge[sv], discovery[g[sv][i]]);//see figure in articulation point folder
    }

}

int main()
{
    int n,m;
    int v1,v2;
    le2(n,m);
    loop(i,0,m)
    {
        le2(v1,v2);
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    dfs(1);
    loop(i,0,bridge.size())
    {
        cout<<bridge[i].first<<" "<<bridge[i].second<<"\n";
    }

    return 0;
}
