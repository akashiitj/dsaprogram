
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

ll gcdo(ll a,ll b)
{
  return b==0?a:gcdo(b,a%b);
}

ll pwr(ll a,ll b)
{
  if(b==0)
    return 1;
  ll temp=pwr(a,b/2);
  temp=(temp*temp);
  if(b&1)
    temp=(temp*a);
  return temp;
}

ll dp[61]={};

int main()
{
    ll n,k;
    le2ll(n,k);
    dp[k]=1;
    loop(i,k+1,n+1)
    {
        loop(j,1,k+1)
        dp[i]+=dp[i-j];
        dp[i]+=pwr(2,i-k);
    }
    ll ans=1ll<<n;
    ll gc=gcdo(dp[n],ans);
    cout<<dp[n]/gc<<"/"<<ans/gc;

    return 0;
}

