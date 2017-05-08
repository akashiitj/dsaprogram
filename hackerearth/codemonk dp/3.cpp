// digit dp
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

int dgt[20];
ll dp[20][200][1500][2];

ll f(int i,int sum,int ssum,int tight)
{
    if(i==-1&& gcd(sum,ssum)==1)return 1;
    if(i==-1) return 0;
    if(dp[i][sum][ssum][tight]!=-1)
        return dp[i][sum][ssum][tight];
    int ed;
    if(tight==1)
    {
        ed=dgt[i];
    }
    else ed=9;
    ll ans=0;
    loop(j,0,ed+1)
    {
        ans+=f(i-1,sum+j,ssum+j*j,tight&&(j==ed));
    }
    if(tight==0)dp[i][sum][ssum][tight]=ans;
    return ans;



}

int main()
{
    ll l1,r;
    memset(dp,-1,sizeof dp);
    ll dx,dy;
    frmlty
    {

        le2ll(l1,r);
        dx=l1;
        dy=r;
        int l=0;
        while(r>0)
        {
            dgt[l]=r%10;
            r=r/10;
            l++;
        }
        //	cout<<l<<" \n";
        ll x=f(l-1,0,0,1);
        l1--;
        l=0;
        while(l1>0)
        {
            dgt[l]=l1%10;
            l1=l1/10;
            l++;
        }

        ll y=f(l-1,0,0,1);
        if(dx==0)y=0;
        if(dy==0)x=0;
        cout<<x-y<<"\n";
    }
    return 0;
}
