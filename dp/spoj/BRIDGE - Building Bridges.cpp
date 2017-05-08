
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

pii a[1001];
int dp[1001];

int main()
{   int n,fa;
    frmlty
    {   memset(dp,0,sizeof(dp));
        fa=1;
        le(n);
        loop(i,1,n+1)
        {
            le(a[i].first);
        }

         loop(i,1,n+1)
        {
            le(a[i].second);
        }

        sort(a+1,a+1+n);

        loop(i,1,n+1)
        {
            dp[i]=1;
            loop(j,1,i)
            {   //cout<<a[i].second<<" "<<a[j].second<<"   "<<i<<" "<<j<<"\n";
                if(a[j].second<=a[i].second)
                {
                    dp[i]=maX(dp[i],dp[j]+1);
                    fa=maX(fa,dp[i]);
                }
            }
           // cout<<dp[i]<<"\n";
        }
        cout<<fa<<"\n";

    }
    return 0;
}

