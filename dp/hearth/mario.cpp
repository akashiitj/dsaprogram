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

ll dp[100001][4];

ll f(ll n,ll k)
{   //cout<<dp[n][k]<<" "<<n<<" "<<k<<"\n";
    if(dp[n][k]!=-1)return dp[n][k];
    if(n==k)
        return 1+f(n,k-1);
    if(k==0||n<0)
        return 0;
    if(k==1||n==0)return 1;
    dp[n][k]=f(n,k-1)+f(n-k,k);
    if(dp[n][k]>=mod)dp[n][k]%=mod;
    //cout<<dp[n][k]<<" "<<n<<" "<<k<<"\n";
    return dp[n][k];
}


int main()
{
    ll n;
    frmlty
    {
        lell(n);
        loop(i,0,n+1)
        {
            loop(j,0,4)
            dp[i][j]=-1;
        }
      //  cout<<n<<" "<<dp[n][3]<<"\n";
        printf("%lld\n",f(n,3));
    }
    return 0;
}

