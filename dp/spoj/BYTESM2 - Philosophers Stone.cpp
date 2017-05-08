
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

int a[150][150];
int dp[150][150];

int main()
{   int h,w;
    frmlty
    {
        le2(h,w);
        loop(i,0,h)
        loop(j,0,w)
        le(a[i][j]);

         loop(j,0,w)
         dp[h-1][j]=a[h-1][j];

         for(int i=h-2;i>=0;i--)
         {
             loop(j,0,w)
             {
                 dp[i][j]=dp[i+1][j]+a[i][j];
                 if(j-1>=0)dp[i][j]=maX(dp[i][j],dp[i+1][j-1]+a[i][j]);
                  if(j+1<w)dp[i][j]=maX(dp[i][j],dp[i+1][j+1]+a[i][j]);
             }
         }
         int ans=0;

          loop(j,0,w)
         ans=maX(ans,dp[0][j]);

         printf("%d\n",ans);


    }
    return 0;
}

