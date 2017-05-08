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

int p[100001];
int prnt[100001];
ll a[100001];

vi g[100001];
int vis[100001],inv[100005];
int cur=1;


int dfs(int sv)
{
    int sz=0;
    inv[sv]=cur;
    cur++;
    vis[sv]=1;
    loop(i,0,g[sv].size())
    {
        if(vis[g[sv][i]]==0)
        {
            prnt[g[sv][i]]=sv;
            sz=sz+dfs(g[sv][i]);
        }
    }
    p[sv]=1+sz;
    return 1+sz;
}

int main()
{
    int n,m,x,y;
    le2(n,m);
    loop(i,0,n-1)
    {
        le2(x,y);
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1);
    prnt[1]=-1;
    ll ans=0;
    loop(i,0,m)
    {
        le(x);
        ans=0;
        if(x==1)
        {
            le2(x,y);
            loop(i1,inv[x],inv[x]+p[x]+1)
            a[i1]+=(y*1LL);
        }
        else
        {
            le(x);
            while(x!=-1)
            {

                ans=ans+a[x];
                x=prnt[x];
            }
            printf("%lld\n",ans);
        }
    }

    return 0;
}

