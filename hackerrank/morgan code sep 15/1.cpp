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
int n,m,k;;
int val[10001];
int vis[10001];

int dp[10001][301];//max profit when you start from i node and uses exactly k key

void dfs(int sv)
{
    vis[sv]=1;
    dp[sv][0]=val[sv];
    if(val[sv]>0)dp[sv][1]=m*val[sv];

    loop(i,0,g[sv].size())
    {
        if(vis[g[sv][i]]==0)dfs(g[sv][i]);
        dp[sv][0]=maX(dp[sv][0],dp[g[sv][i]][0]+val[sv]);

        loop(j,1,k+1)
        {
            if(dp[g[sv][i]][j-1]!=INT_MIN)   dp[sv][j]=maX(dp[sv][j],dp[g[sv][i]][j-1]+val[sv]*m);//include
            if(dp[g[sv][i]][j]!=INT_MIN)   dp[sv][j]=maX(dp[sv][j],dp[g[sv][i]][j]+val[sv]);//not include
        }
    }
}

int main()
{
    int x,y;
    frmlty
    {
        le2(n,m);
        le(k);

        int flag=0;
        loop(i,0,n)
        {
            g[i].clear();
            vis[i]=0;
            le(val[i]);
            if(val[i]==0)flag=1;
            loop(i1,0,k+1)
            {
                dp[i][i1]=INT_MIN;
            }
        }
        loop(i,0,n-1)
        {
            le2(x,y);
            g[x].pb(y);
        }

        loop(i,0,n)
        {
            if(vis[i]==0)
            {
                dfs(i);
            }
        }

        int ans=INT_MIN;
        loop(i,0,n)
        {
            loop(j,0,k+1)
            {
                ans=maX(ans,dp[i][j]);
            }
        }

        if(ans<0&&flag)cout<<"0\n";
        else cout<<ans<<"\n";
    }
    return 0;
}


