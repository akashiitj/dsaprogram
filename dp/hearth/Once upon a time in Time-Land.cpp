//https://www.hackerearth.com/problem/algorithm/once-upon-a-time-in-time-land/

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
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

ll a[10001];
ll dp[10001];

int main()
{
    int n,k;

    frmlty
    {
        dp[0]=0;
        le2(n,k);
        loop(i,1,n+1)
        {
            lell(a[i]);
            dp[i]=0;
        }
        loop(i,1,1+k+1)
        {
            dp[i]=maX(dp[i-1],a[i]);
           // cout<<dp[i]<<" ";
        }
        loop(i,k+2,n+1)
        {
            dp[i]=maX(dp[i-1],maX(dp[i-k-1]+a[i],dp[i-k-1]));
        }
        cout<<dp[n]<<"\n";

    }
    return 0;
}


