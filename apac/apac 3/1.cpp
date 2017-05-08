
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

map<string,vector<pii> > m;
vector<pair<ll,string> > v;

template<typename P> struct Cmp
{
    bool operator()(const P &p1, const P &p2)
    {
        if(p1.first > p2.first) return true;
        if(p1.first == p2.first) return p1.second < p2.second;
        return false;
    }
};
ll a[101];
int main()
{
    freopen("1.in","r",stdin);
    freopen("1o.out","w",stdout);
    ll p,n,w;
    string s;
    ll hc=0;
    frmlty
    {
        m.clear();
        hc++;

        lell(p);
        loop(i,1,p+1)
        lell(a[i]);

        lell(n);
        loop(i,0,n)
        {
            lell(w);
            loop(j,1,p+1)
            {
                cin>>s;
                m[s].pb(mp(w,a[j]));
            }
        }
        ll m1;
        cin>>m1;
        string nam;
        vi dv;
        dv.clear();
        ll ttl;
        v.clear();
        for (map<string,vector<pii> >::iterator it=m.begin(); it!=m.end(); ++it)
        {
            dv.clear();
            //  cout<<it->first<<" \n";
            loop(i,0,(it->second).size())
            {
                //cout<<(it->second)[i].first<<" "<<(it->second)[i].second<<"\n";
                dv.pb((it->second)[i].first * (it->second)[i].second);
            }
            sort(dv.rbegin(),dv.rend());
            ttl=0;

            loop(i,0,miN(m1,dv.size()))
            ttl+=dv[i];

            //  cout<<ttl<<" "<<it->first<<"\n";
            v.pb(mp(ttl,it->first));
        }
        sort(v.begin(),v.end(),Cmp<pair<ll, string> >());
        cout<<"Case #"<<hc<<":\n";
        ll chv1=0;
        ll di=-1;
        loop(i,0,v.size())
        {
            if(di!=v[i].first){

            cout<<i+1<<": "<<v[i].second<<"\n";
            chv1=i+1;
            di=v[i].first;
            }
            else
            {
                cout<<chv1<<": "<<v[i].second<<"\n";

            }
        }



    }

    return 0;
}

