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

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

ll maxl(ll x,ll y)
{
    if(x>y)return x;
    else return y;
}

ll minl(ll x,ll y)
{
    if(x<y)return x;
    else return y;
}

int main()
{
    frmlty
    {   int n;
        le(n);
        ll a[n+1];
        loop(i,1,n+1)
        lell(a[i]);

        ll maxs[n+1];
        ll mins[n+1];
        ll maxe[n+1];
        ll mine[n+1];

        ll maxupto,minupto;

        maxs[1]=a[1];
        mins[1]=a[1];

        maxupto=maxl(0,a[1]);
        minupto=minl(0,a[1]);

        loop(i,2,n+1)
        {
            maxupto=maxupto+a[i];
            minupto=minupto+a[i];

            maxs[i]=maxl(maxs[i-1],maxupto);
            mins[i]=minl(mins[i-1],minupto);

            if(maxupto<0)maxupto=0;
            if(minupto>0)minupto=0;
        }

        maxe[n]=a[n];
        mine[n]=a[n];

        maxupto=maxl(0,a[n]);
        minupto=minl(0,a[n]);

        for(int i=n-1; i>=1; i--)
        {
            maxupto=maxupto+a[i];
            minupto=minupto+a[i];

            maxe[i]=maxl(maxe[i+1],maxupto);
            mine[i]=minl(mine[i+1],minupto);

            if(maxupto<0)maxupto=0;
            if(minupto>0)minupto=0;
        }
        ll ans= -(1ll<<62);
        loop(i,1,n)
        {
            ans=maxl(ans,maxs[i]-mine[i+1]);
            ans=maxl(ans,maxe[i+1]-mins[i]);
        }
        cout<<ans<<"\n";


    }
    return 0;
}


