#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
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

//#define le(x) scanf("%d",&x);
//#define le2(x,y) scanf("%d%d",&x,&y);
#define le(x) scanf("%lld",&x);
#define le2(x,y) scanf("%lld%lld",&x,&y);


int main()
{
    ll n;
    frmlty
    {
        le(n);
        vector<pii > vp,vn;
        ll a[n];
        vp.clear();
        vn.clear();
        loop(i,0,n)
        {
            le(a[i]);
            if(a[i]>0)vp.pb(mp(a[i],i));
            if(a[i]<0)vn.pb(mp(abs(a[i]),i));
        }
        ll i=0,j=0;
        ll ans=0;

        while(i<vp.size()&&j<vn.size())
        {
            if(vp[i].first>vn[j].first)
            {
                ans=ans+(vn[j].first)*abs(vp[i].second-vn[j].second);
                vp[i].first= vp[i].first-vn[j].first;
                j++;
            }
            else  if(vp[i].first<vn[j].first)
            {
                ans=ans+(vp[i].first)*abs(vp[i].second-vn[j].second);
                vn[j].first= vn[j].first-vp[i].first;
                i++;
            }
            else  if(vp[i].first==vn[j].first)
            {
                ans=ans+(vn[j].first)*abs(vp[i].second-vn[j].second);
                i++;
                j++;
            }


        }
        cout<<ans<<"\n";
    }

    return 0;
}


