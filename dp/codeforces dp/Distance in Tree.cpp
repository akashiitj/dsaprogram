
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
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

vi g[50001];
int visit[50001]= {};
ll dp[50001][501]= {};
ll ans=0;
int k;
void dfs(int sv)
{
    visit[sv]=1;
    dp[sv][0]=1;
    loop(i,0,g[sv].size())
    {
        if(visit[g[sv][i]]==0)
        {
            dfs(g[sv][i]);

            loop(j,0,k)
            ans=ans+dp[sv][j]*dp[g[sv][i]][k-j-1];

            loop(j,1,k)
            dp[sv][j]+=dp[g[sv][i]][j-1];


        }
    }

}

int main()
{
    int n;
    le2(n,k);
    int x,y;
    loop(i,0,n-1)
    {
        le2(x,y);
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1);
    cout<<ans<<"\n";
    return 0;
}


