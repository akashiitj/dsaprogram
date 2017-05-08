
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
#define frmlty     ll test_case;cin>>test_case;while(test_case--)

#define vi        vector<ll>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<ll,ll>

#define msi       map<string,ll>
#define msit      map<string,ll>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(ll i=b-1;i>=a;i--)

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

ll g[501][501];
ll have[500+1]= {0};
ll dp[501][501];
int main()
{
    ll n;
    lell(n);
    loop(i,1,n+1)
    loop(j,1,n+1)
    {

        lell(g[i][j]);
        dp[i][j]=g[i][j];
    }
    ll a[n+1];
    loop(i,1,n+1)
    {
        lell(a[i]);
    }
    ll ans[n+1];
    ll me;
    for(ll i=n; i>=1; i--)
    {
        me=a[i];
        have[me]=1;
        ans[i]=0;
        loop(j,1,n+1)
        loop(k,1,n+1)
        {
            dp[j][k]=miN(dp[j][k],dp[j][me]+dp[me][k]);
        }

        loop(j,1,n+1)
        loop(k,1,n+1)
        if(have[j]&&have[k])ans[i]+=dp[j][k];
    }
    loop(i,1,n+1)
    cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}


