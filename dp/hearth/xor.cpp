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

int ht[1000001];

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

ll f(ll n)
{
    if(n<=1)return 0;
    else return ((n*(n-1))%mod*pow1(2,mod-2))%mod;
}

int main()
{   int n,x;
    ll dp[128][2]={};//number of subsets having xor i
    le(n);
    int hv;
    dp[0][0]=0;
    int cu=1,pre=0;
    loop(i,0,n)
    {   le(x);

        loop(i,0,128)
        {   hv=x^i;
            dp[hv][cu]=dp[hv][pre]+dp[i][pre];
            if(i==x)dp[i][cu]++;
        }
        swap(pre,cu);
    }
    ll ans=0;

    loop(i,0,128)
    {
        ans=ans+f(dp[i][pre]);
        if(ans>=mod)ans=ans%mod;
    }
    cout<<ans<<"\n";
    return 0;
}



