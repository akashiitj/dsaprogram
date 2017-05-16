

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

//ll dp[4][10000001];

/*ll f(ll vn,ll n)
{
    if(vn==0&&n==0)return dp[vn][n]=1;
    if(dp[vn][n]!=-1)return dp[vn][n];
    ll ans=0;
    loop(i,0,4)
    {
        if(i!=vn)
        {
            ans=ans+f(i,n-1);
            if(ans>=mod)ans=ans%mod;
        }
    }
    return dp[vn][n]=ans;
}
*/
int main()
{
    ll n;
    lell(n);
    ll nz,oz=1,nabc,oabc=0;
    loop(i,1,n+1)
    {
        nz=(3*oabc)%mod;//ways to reach z
        nabc=(oz+2*oabc)%mod;//ways to reach any of the a b c
        oz=nz;
        oabc=nabc;
    }
    cout<<oz<<"\n";

    return 0;
}

