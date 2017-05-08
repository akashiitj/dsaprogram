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

vi g[10001];
int dp[10001][101];
int ans[10001][101];
int vis[10001];
int p[10001];

int n,k;

void dfs1(int root)
{
    vis[root]=1;
    int l=g[root].size();
    loop(i,0,l)
    {
        int child=g[root][i];
        if(vis[child]==0)
        {
            dfs1(child);
            loop(j,1,k+1)
            dp[root][j]=miN(dp[root][j],dp[child][j]);
        }

    }
    // dp[root][p[root]]=miN(dp[root][p[root]],root);
}

void dfs2(int root)
{
    vis[root]=1;
    int l=g[root].size();
    loop(i,0,l)
    {
        int child=g[root][i];
        if(vis[child]==0)
        {

            loop(j,1,k+1)
            {
     //           ans[child][j]=dp[child][j];
                if(dp[child][j]==INT_MAX)dp[child][j]=dp[root][j];
            }
            dfs2(child);
        }

    }
    //dp[root][p[root]]=miN(dp[root][p[root]],root);
}



int main()
{
    int x,y;
    le2(n,k);
    int root;
    le(root);
    loop(i,1,n)
    {
        le2(x,y);
        g[x].pb(y);
        g[y].pb(x);
    }
    int hv;
    loop(i,1,n+1)
    {
        le(hv);

        loop(j,1,k+1)
        dp[i][j]=INT_MAX;

        dp[i][hv]=i;
    }
    dfs1(root);

    loop(i,1,n+1)
    vis[i]=0;
//    loop(j,1,k+1)
//    {
//        ans[root][j]=dp[root][j];
//    }

    dfs2(root);

    int q;
    le(q);
    loop(i,0,q)
    {
        le2(x,y);
        if(dp[x][y]==INT_MAX)
            printf("-1\n");
        else printf("%d\n",dp[x][y]);
    }


    return 0;
}

