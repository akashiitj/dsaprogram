
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

int dp[101][101];
int a[101];

int main()
{
    int n,k1;
    int c=0;
    frmlty
    {
        c++;
        le2(n,k1);
        loop(i,1,n+1)
        {
            le(a[i]);
        }
        memset(dp,0,sizeof(dp));


        loop(l,1,n+1)
        {
            loop(i,l,n+1)
            {
                int j=i-l+1;
                dp[j][i]=l;
                if(l<=2)dp[j][i]=l;
                else
                {
                    dp[j][i]=miN(1+dp[j][i-1],dp[j][i]);
                    dp[j][i]=miN(1+dp[j+1][i],dp[j][i]);

                    loop(k,j+1,i)
                    {
                        dp[j][i]=miN(dp[j][i],dp[j][k]+dp[k+1][i]);
                        if(a[k]-a[j]==k1 && k1==a[i]-a[k] &&dp[j+1][k-1]==0&&dp[k+1][i-1]==0)
                            dp[j][i]=0;
                    }
                }
              //  cout<<j<<" "<<i<<" "<<dp[j][i]<<"  ";
            }
            //cout<<"\n";

        }
        printf("Case #%d: %d\n", c, dp[1][n]);
        //cout<<dp[1][n]<<"\n";

    }
    return 0;
}

