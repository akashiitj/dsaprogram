
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

int n;
int dp[10][100];
int f(int i,int ps,int rem)
{
    if(n == i & rem==0)
    {
        return dp[i][ps]=1;
    }
    if(rem<0||n==i)return 0;
    if(dp[i][ps]!=-1)return dp[i][ps];
    int ans=0;
    if(i!=0)ans=ans+f(i+1,ps,rem);
    for(int j=1; j<=9; j++)
    {
        ans=ans+f(i+1,ps+j,rem-j);
    }
    return dp[i][ps]=ans;
}

int main()
{
    memset(dp,-1,sizeof dp);
    int rem;
    cin>>n;
    cin>>rem;
    cout<<f(0,0,rem);
    return 0;
}

