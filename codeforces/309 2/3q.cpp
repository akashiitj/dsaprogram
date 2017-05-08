

#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;



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

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%%I64d",&x);
#define le2ll(x,y) scanf("%%I64d%%I64d",&x,&y);

ll fact[1001];
ll ifact[1001];
ll mod=1000000007;

ll pow1(ll a, ll b)
{
    ll x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}

void init()
{
    fact[0]=1;
    loop(i,1,1001)
    {
        fact[i]=fact[i-1]*i;
        if(fact[i]>=mod)fact[i]=fact[i]%mod;
    }
    //cout<<" c1"<<"\n";
    ll invx,x;
    ifact[1]=1;
    ifact[1000]=pow1(fact[1000],mod-2);
    //cout<<" c2"<<"\n";
    for(ll i=1000-1; i>=2; i--)
    {

        ifact[i]=ifact[i+1]*(i+1);
        if(ifact[i]>=mod)ifact[i]=ifact[i]%mod;
    }
}

ll ncr(ll n,ll r)
{
    if(r==0 || r==n)return 1;
    ll x=(fact[n]*ifact[r])%mod;
    x=(x*ifact[n-r])%mod;
    return x;
}

ll dp[1001];


int main()
{   init();
    ll n;
    ll x;
    ll gap=1;
    cin>>n;
    ll tp=0;
    ll fop=0;
    ll ans=0;
    dp[0]=1;
    loop(i,1,n+1)
    {
        cin>>x;
        tp=tp+x;
        ans=ncr(tp-1,fop)*dp[i-1];
        if(ans>=mod)ans=ans%mod;
      //  cout<<ans<<"\n";
        dp[i]=ans;
        fop=tp;


    }
    cout<<dp[n]<<"\n";
    return 0;
}


