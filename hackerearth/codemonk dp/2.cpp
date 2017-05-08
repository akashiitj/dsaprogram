
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

int dp[100001][3];

int main()
{
    int n;
    int x,y,z;
    frmlty
    {
        le(n);
        le2(x,y);
        le(z);
        dp[0][0]=x;
        dp[0][1]=y;
        dp[0][2]=z;
        loop(i,1,n)
        {
            le2(x,y);
            le(z);

            dp[i][0]=miN(dp[i-1][1],dp[i-1][2])+x;

             dp[i][1]=miN(dp[i-1][0],dp[i-1][2])+y;

              dp[i][2]=miN(dp[i-1][0],dp[i-1][1])+z;


        }

        cout<<miN(miN(dp[n-1][0],dp[n-1][1]),dp[n-1][2])<<"\n";
    }
    return 0;
}

