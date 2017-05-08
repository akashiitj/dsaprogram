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

ll dp[5001][5001];
pair<ll,ll> a[5001];

int main()
{
    int n;
    frmlty
    {
        le(n);
        loop(i,1,n+1)
        lell2(a[i].second,a[i].first);

        sort(a+1,a+1+n);
        reverse(a+1,a+1+n);

        loop(i,1,n+1)
        {
            if(i==1) dp[1][i]=a[i].second;
            else dp[1][i]=maX(dp[1][i-1],a[i].second);
        }
        cout<<dp[1][n]<<" ";

        loop(i,2,n+1)
        {
            loop(j,i,n+1)
            {
                if(i==j)dp[i][j]=dp[i-1][j-1]+((i-1)*a[j].first+a[j].second);
                else
                {
                    dp[i][j]=maX(dp[i-1][j-1]+((i-1)*a[j].first+a[j].second),dp[i][j-1]);
                }
            }
            cout<<dp[i][n]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

