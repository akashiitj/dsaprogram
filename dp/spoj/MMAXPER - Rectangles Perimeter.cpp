
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



int main()
{
    int n;
    le(n);
    int w[n+1];
    int h[n+1];

    int dp[n+1][2];

    loop(i,1,n+1)
    {
        le2(w[i],h[i]);
    }

    dp[1][0]=w[1]+h[1];
    dp[1][1]=w[1]+h[1];
     //cout<<dp[1][0]<<" "<<dp[1][1]<<"\n";
    loop(i,2,n+1)

    {
        dp[i][0]=maX(dp[i-1][0]-w[i-1]+abs(w[i-1]-w[i]),dp[i-1][1]-h[i-1]+abs(h[i-1]-w[i]))+w[i]+h[i];

        dp[i][1]=maX(dp[i-1][0]-w[i-1]+abs(w[i-1]-h[i]),dp[i-1][1]-h[i-1]+abs(h[i-1]-h[i]))+w[i]+h[i];

        //cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";

    }

    dp[n][0]-=w[n];
    dp[n][1]-=h[n];
    cout<<maX(dp[n][0],dp[n][1])<<"\n";


    return 0;
}

