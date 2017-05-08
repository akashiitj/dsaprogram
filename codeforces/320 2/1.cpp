#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
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
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

ll a[15];
ll dp[200001][12];
ll b[200001];

int main()
{
    int n,k;
    ll x;
    le2(n,k);
    lell(x);

    loop(i,1,n+1)
    lell(b[i]);

    a[0]=1LL;
    a[1]=x;
    loop(i,2,k+1)
    {
        a[i]=a[i-1]*x;
    }


    loop(i,0,k+1)
    dp[1][i]=b[1]*a[i];

    loop(i,2,n+1)
    {
        loop(j,0,k+1)
        {
            dp[i][j]=dp[i-1][j]|(b[i]);
            loop(k1,0,j)
            {
                dp[i][j]=maX(dp[i-1][k1]|(b[i]*1LL*a[j-k1]),dp[i][j]);
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    ll ans=dp[n][0];
    loop(j,0,k+1)
    ans=maX(ans,dp[n][j]);

    cout<<ans<<"\n";


    return 0;
}



