#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

#define frmlty     ll test_case;cin>>test_case;while(test_case--)

#define vi        vector<ll>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<ll,ll>

#define msi       map<string,ll>
#define msit      map<string,ll>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(ll i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second

ll m;
ll dp[25][1001];


ll pow1(ll a, ll b)
{
    ll x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>m) x%=m;
        }
        y = (y*y);
        if(y>mod) y%=m;
        b /= 2;
    }
    return x;
}

ll s;//req length

ll f(ll i,ll sumupto)
{

    if(i==s/2)
    {
        if(s%2==0)
            return sumupto==0;
        else
        {

            ll psum;
            ll ans=0;
            loop(i1,0,10)
            {
                if(i1==0&&i==0)continue;
                psum=(sumupto+i1*pow1(10,s/2))%m;

                if(psum==0) ans++;
            }
            return ans;
        }
    }
    if(dp[i][sumupto]!=-1)
        return dp[i][sumupto];
    ll ans=0;
    loop(i1,0,10)
    {
        if(i1==0&&i==0)continue;
        ans=ans+f(i+1,(pow1(10,i)*i1+sumupto+i1*pow1(10,s-i-1))%m);
    }
    return dp[i][sumupto]=ans;

}


int main()
{
    frmlty
    {
        le2ll(m,s);
        memset(dp,-1,sizeof (dp));
        cout<<f(0,0)<<"\n";
    }
    return 0;
}


