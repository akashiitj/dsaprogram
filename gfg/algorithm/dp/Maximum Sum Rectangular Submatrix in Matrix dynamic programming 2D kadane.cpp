
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

int a[10][10]= {{-1, -2, -1, -4, -20},
    {-8, -3, -4, -2, -1},
    {-3, -8, -10, -1, -3},
    {-4, -1, -1, -7, -6}
};;
int dp[10];
int n,m;
int dp1[10];

void solve()
{
    int l,r,u,d,fa=INT_MIN,ta;
    loop(i,0,m)//fix a row
    {
        loop(j,0,n)
        dp[j]=0;

        loop(j,i,m)
        {
            loop(j1,0,n)
            dp[j1]=dp[j1]+a[j1][j];

            dp1[0]=dp[0];
            ta=INT_MIN;
            loop(j1,1,n)
            {
                dp1[j1]=maX(dp1[j1-1]+dp[j1],dp[j1]);
                ta=maX(ta,dp1[j1]);
            }

            if(ta>fa)
            {
                l=i;
                r=j;
                fa=maX(fa,ta);
            }
        }
    }
    cout<<fa<<" "<<l<<" "<<r<<"\n";
}

int main()
{
    le2(n,m);
    solve();
    return 0;
}

