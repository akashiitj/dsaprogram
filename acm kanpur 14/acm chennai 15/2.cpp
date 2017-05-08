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

double dp[1001][1001];

int main()
{
    int n,x;
    dp[0][1]=1.0;
    int c=0;
    frmlty
    {
        le(n);
        //memset(dp,-1,sizeof dp);
        dp[1][1]=1;
        le(x);
        loop(i,2,n+1)
        {
            le(x);
            if(x==-1)
                c++;
            loop(j,1,i+1)
            {   dp[i][j]=-1;
                if(x== -1)
                {
                    if(dp[i-1][j]!=-1)dp[i][j]=0.5*dp[i-1][j];
                    if(dp[i-1][j-1]!=-1&&dp[i][j]!=-1)dp[i][j]+=0.5*dp[i-1][j-1];
                    if(dp[i-1][j-1]!=-1&&dp[i][j]==-1)dp[i][j]=0.5*dp[i-1][j-1];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        double ans=0;

        loop(i,1,n+1)
        {
            if(dp[n][i]!=-1)ans=ans+(double)(i*dp[n][i]);
        }
        //ans=a;
        cout<<fixed<<setprecision(6)<<ans<<"\n";
    }
    return 0;
}


