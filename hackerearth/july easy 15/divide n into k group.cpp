
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


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
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

ll dp[300][300];

ll f(ll n,ll k)
{   if(n<0)return 0;
    if(k==1)return 1;
    if(k==2)return n/2;
    if(dp[n][k]!=-1)return dp[n][k];
    dp[n][k]=f(n-1,k-1)+f(n-k,k);
    return dp[n][k];
}

int main()
{   loop(i,0,300)
    loop(j,0,300)
    dp[i][j]=-1;
    frmlty{
    ll n,k;
    le2ll(n,k);
    ll mg=n/k;
    ll re,ans=0;
    for(ll i=mg;i>=1;i--)
    {
        re=n-(i*k)+i;
        ans=ans+f(re,i);

    }
    cout<<ans<<"\n";}
    return 0;
}
