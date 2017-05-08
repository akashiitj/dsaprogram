
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

vector<pair<pii ,int > > v;
ll dp[2000005];

int main()
{
    int n;
    int x,y,w;
    int mx=0;
    frmlty
    {   memset(dp,0,sizeof(dp));
        mx=0;
        v.clear();
        le(n);
        loop(i,0,n)
        {
            le2(x,y);
            le(w);
            v.pb(mp(mp(y+x,x),w));
            mx=maX(mx,y+x);
        }
        sort(v.begin(),v.end());
        int c=0;
        loop(i,1,mx+1)
        {
            while(v[c].first.first==i)
            {

                dp[i]=maX(dp[i],dp[v[c].first.second]+v[c].second*1LL);
                c++;
            }
            dp[i]=maX(dp[i-1],dp[i]);

        }
        cout<<dp[mx]<<"\n";
    }
    return 0;
}

