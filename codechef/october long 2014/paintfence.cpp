#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000009;

#define fast      ios_base::sync_with_stdio(false);
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<ll,ll>

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


int main()
{
    int n,m;
    ll x,y;
    char c;
    frmlty
    {
        le2(n,m);
        //cout<<"d"<<endl;
        vector<pii> a;

        //cout<<"d"<<endl;
        loop(i,0,m)
        {
            cin>>c;
            lell(y);
            a.pb(mp(y,c-'A'));

        }
        sort(a.begin(),a.end());
        ll ans=1;
        loop(i,0,m-1)
        {
            if(a[i].second!=a[i+1].second)
            {
                ans=ans*(a[i+1].first-a[i].first);
                if(ans>=mod)ans=ans%mod;
            }
        }
        cout<<ans<<"\n";

    }
    return 0;
}


