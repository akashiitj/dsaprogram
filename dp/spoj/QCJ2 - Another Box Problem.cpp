#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 761238923;

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

ll dp[101][101];

ll f(int i,int j)
{
    if(i==1&&j==1)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    ll ans=0;
    loop(j1,0,min(i,j)+1)
    if(j-j1<=i-1)ans=(ans+f(i-1,j-j1))%mod;

    return dp[i][j]=ans;
}


int main()
{
    int n;
    while(true)
    {
        le(n);
        if(n==0)break;
        memset(dp,-1,sizeof(dp));
        ll res=0;
        for(int i=0;i<=n;i++)
        {
            res = (res + f(n,i))%mod;
        }
        cout<<res<<"\n";
    }
    return 0;
}
