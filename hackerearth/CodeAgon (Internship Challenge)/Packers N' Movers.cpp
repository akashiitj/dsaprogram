
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

int a[300];
int dp[16][300];
int cs[300];
int main()
{
    int m,p;
    le2(m,p);

    loop(i,1,p+1)
    le(a[i]);

    cs[1]=a[1];
    dp[1][1]=a[1];
    loop(i,1,p+1)
    {
        cs[i]=a[i]+cs[i-1];
        dp[1][i]=cs[i];
    }
    int ans=cs[p];
    loop(i,2,m+1)
    {
        loop(j,i,p+1)
        {
            dp[i][j]=INT_MAX;
            loop(k,i-1,j)
            {
                dp[i][j]=miN(dp[i][j],maX(dp[i-1][k],cs[j]-cs[k]));
                if(j==p)  ans=miN(ans,dp[i][j]);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}

