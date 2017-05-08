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

vi g[100001];
vll w[100001];
ll dp[100001];
int vis[100001];
int sz[100001];
ll ans[100001];

void dfs(int sv)
{
    vis[sv]=1;
    loop(i,0,g[sv].size())
    {
        if(vis[g[sv][i]]==0)
        {
            dfs(g[sv][i]);
            sz[sv]+=sz[g[sv][i]];
            dp[sv]+=dp[g[sv][i]]+sz[g[sv][i]]*w[sv][i];
        }
    }
    sz[sv]+=1;
}
int n;
void dfs2(int sv)
{
    vis[sv]=1;

    loop(i,0,g[sv].size())
    {
        int chd=g[sv][i];
        if(vis[chd]==0)
        {
            //cout<<sv<<" "<<chd<<" "<<ans[chd]<<" "<<ans[sv]<<" "<<n<<" "<<sz[chd]<<"\n";
            ans[chd]=ans[sv]+1LL*w[sv][i]*(n-(2*sz[chd]));
            dfs2(chd);
        }
    }
}

int main()
{

    int x,y;
    ll z;
    frmlty
    {
        le(n);
        loop(i,1,n+1)
        {
            vis[i]=0;
            g[i].clear();
            w[i].clear();
            dp[i]=0;
            sz[i]=0;
            ans[i]=0;
        }
        loop(i,1,n)
        {
            le2(x,y);
            lell(z);
            g[x].pb(y);
            w[x].pb(z);
            g[y].pb(x);
            w[y].pb(z);

        }

        dfs(1);
        ans[1]=dp[1];


        loop(i,1,n+1)
        vis[i]=0;
        dfs2(1);

        loop(i,1,n+1)
        printf("%lld\n",ans[i]);
        //cout<<ans[i]<<"\n";


    }
    return 0;
}
