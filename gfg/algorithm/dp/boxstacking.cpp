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

vector<pair<pii,int> >a;
int dp[100];

int main()
{
    int n,x,y,z,x1[2];
    le(n);
    loop(i,1,n+1)
    {
        le(x);
        le2(y,z);

        x1[0]=x;
        x1[1]=y;
        sort(x1,x1+2);
        a.pb(mp(mp(x1[1],x1[0]),z));

        x1[0]=z;
        x1[1]=y;
        sort(x1,x1+2);
        a.pb(mp(mp(x1[1],x1[0]),x));

        x1[0]=x;
        x1[1]=z;
        sort(x1,x1+2);
        a.pb(mp(mp(x1[1],x1[0]),y));


    }
    n=a.size()*3;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    int ans=a[0].second;//making mistake here
    dp[0]=ans;
    loop(i,1,n)
    {
        dp[i]=a[i].second;
        loop(j,0,i)
        {
            if(a[i].first.first<a[j].first.first&&a[i].first.second<a[j].first.second)
                dp[i]=maX(dp[i],dp[j]+a[i].second);
        }
        ans=maX(ans,dp[i]);

    }
    cout<<ans<<"\n";
    return 0;
}


