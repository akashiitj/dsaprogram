
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>
#define pll       pair<ll,ll>

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

int main()
{
    int n;
    frmlty
    {
        le(n);
        pll a[n];
        ll dp[n];
        ll r,h;
        loop(i,0,n)
        {
            le2ll(r,h);
            a[i].first=r;
            a[i].second=h;
        }
        sort(a,a+n);
        reverse(a,a+n);
        ll ans=0;
        dp[0]=a[0].second;
        loop(i,1,n)
        {   dp[i]=a[i].second;
            loop(j,0,i)
            {
                if(a[j].second>a[i].second)
                    dp[i]=max(dp[i],dp[j]+a[i].second);
            }
            ans=maX(ans,dp[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

