#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 100010000007;

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

vi g[10001];
int ma=0,ai;
int vis[10001];
int dis[10001];
void dfs(int sv)
{
    vis[sv]=1;

    loop(i,0,g[sv].size())
    {
        if(vis[g[sv][i]]==0)
        {
            dis[g[sv][i]]=dis[sv]+1;
            if(ma<dis[g[sv][i]])ai=g[sv][i];
            ma=maX(ma,dis[g[sv][i]]);
            dfs(g[sv][i]);
        }
    }
}


int main()
{
    int n;
    le(n);
    int x,y;
    loop(i,0,n-1)
    {
        le2(x,y);
        g[x].pb(y);
        g[y].pb(x);
    }
//   cout<<hit(1);

    dfs(1);
    loop(i,1,n+1)
    {

        dis[i]=0;
        vis[i]=0;
    }
    dfs(ai);
   // cout<<ai<<"\n";
    cout<<ma<<"\n";
    return 0;
}

