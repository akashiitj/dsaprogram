
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

int dp[1001][10];

int main()
{
    int n,x;
    le(n);
    int k=3;
    loop(i,0,k)
    {
        dp[0][i]=-1;
    }

    dp[0][0]=0;
    int hv;
    loop(i,1,n+1)
    {
        le(x);

        loop(j,0,k)
        {
            dp[i][j]=-1;
            hv=(j-x)%k;
            while(hv<0)
                hv+=k;
            if(dp[i-1][j]!=-1)dp[i][j]=dp[i-1][j];
            if(dp[i-1][hv]!=-1)dp[i][j]=maX(dp[i][j],dp[i-1][hv]+x);


        }
    }
    cout<<dp[n][0]<<"\n";
    return 0;
}

