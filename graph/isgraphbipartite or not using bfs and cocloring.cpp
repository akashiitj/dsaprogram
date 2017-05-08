//http://www.geeksforgeeks.org/bipartite-graph/
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
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

vector<int> g[100005];
int vis[100005]= {};
int colr[100005];//note down color of each node

int c1=0,c0=0;
int soc=0;//number of node in component

int isbarpitite(int sv)
{
    int hv;
    queue<int> q;
    q.push(sv);
    colr[sv]=0;
    vis[sv]=1;
    c0++;
    while(!q.empty())
    {
        hv=q.front();
        q.pop();
        loop(i,0,g[hv].size())
        {
            if(vis[g[hv][i]]==0)
            {
                vis[g[hv][i]]=1;
                colr[g[hv][i]]=1-colr[hv];
                if(colr[g[hv][i]]==1)c1++;
                else c0++;
                q.push(g[hv][i]);
            }
            else if(colr[g[hv][i]]==colr[hv])//means not bipartite
                return 0;
        }
    }
    return 1;
}

int main()
{
    int n,m,v1,v2;
    le2(n,m);
    loop(i,0,m)
    {
        le2(v1,v2);
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    cout<<isbarpitite(1);
    cout<<" "<<c0<<" "<<c1<<"\n";
    return 0;
}


