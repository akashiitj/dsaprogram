
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


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

vll g[100001];
ll a[100001];
int vis[100001];


ll dfs(ll sv)
{   ll ans=a[sv];
    vis[sv]=1;
    loop(i,0,g[sv].size())
    {
        if(vis[g[sv][i]]==0)
        {
            ans=ans+dfs(g[sv][i]);
        }
    }
    return ans;
}

int main()
{
    ll n,x,y,k;
    frmlty
    {
        le2ll(n,k);
        loop(i,1,n+1)
        {
            g[i].clear();
            vis[i]=0;
        }
        loop(i,0,k)
        {
            le2ll(x,y);
            g[x].pb(y);
            g[y].pb(x);
        }
        loop(i,1,n+1)
        lell(a[i]);

        ll ma=-1;

        loop(i,1,n+1)
        {
            if(vis[i]==0)
            {
                ma=max(ma,dfs(i));
            }
        }
        cout<<ma<<"\n";

    }
    return 0;
}

