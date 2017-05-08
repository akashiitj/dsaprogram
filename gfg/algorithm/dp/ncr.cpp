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

//begin

ll fact[200001];
ll ifact[200001];

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
    loop(i,1,200001)
    {
        fact[i]=fact[i-1]*i;
        if(fact[i]>=mod)fact[i]=fact[i]%mod;
    }

    ll invx,x;
    ifact[1]=1;
    ifact[200000]=pow1(fact[200000],mod-2);

    for(ll i=200000-1; i>=2; i--)
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

//end


int dp[100][100]={};

int bup(int n,int k)
{
    loop(i,0,n+1)
    {
        loop(j,0,min(n+1,k+1))
        {
            if(j==0||i==j)dp[i][j]=1;
            else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
    return dp[n][k];
}




int main()
{   cout<<bup(4,2);
    return 0;
}

