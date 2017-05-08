
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

int dp[1003][3],a[1003];
int main()
{
    int n;
    le(n);
    for(int i=0;i<n;i++)le(a[i]);
    dp[0][a[0]%3]=a[0];
    for(int i=1;i<n;i++)
    {
        dp[i][a[i]%3] = max(dp[i-1][a[i]%3],dp[i-1][0] + a[i]);

        dp[i][(1+a[i])%3] = dp[i-1][(1+a[i])%3];
        if(dp[i-1][1]!=0)dp[i][(1+a[i])%3] = max(dp[i][(1+a[i])%3],dp[i-1][1] + a[i]);

        dp[i][(2+a[i])%3] = dp[i-1][(2+a[i])%3];
        if(dp[i-1][2]!=0)dp[i][(2+a[i])%3] = max(dp[i][(2+a[i])%3],dp[i-1][2] + a[i]);
        //cout<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<endl;
    }
    cout<<dp[n-1][0]<<endl;
}
