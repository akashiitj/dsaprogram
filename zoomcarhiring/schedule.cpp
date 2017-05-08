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

ll fact[100001];
ll ifact[100001];

ll pow1(ll a, ll b)
{
    ll x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}

void init()
{
    fact[0]=1;
    loop(i,1,100001)
    {
        fact[i]=fact[i-1]*i;
        if(fact[i]>=mod)fact[i]=fact[i]%mod;
    }
    ll invx,x;
    ifact[1]=1;
    loop(i,2,100001)
    {
        x=pow1(i,mod-2);
        ifact[i]=ifact[i-1]*x;
        if(ifact[i]>=mod)ifact[i]=ifact[i]%mod;
    }
}

ll ncr(ll n,ll r)
{
    if(r==0 || r==n)return 1;
    ll x=(fact[n]*ifact[r])%mod;
    x=(x*ifact[n-r])%mod;
    return x;
}

int main()
{
    ll n,m,x,ans=1LL;

    init();

    lell(n);
    ll tp=0;
    ll a[n];
    vector<ll> v;
    vector<ll> v1[n];
    ll pv,c;
    loop(i,0,n)
    {
        lell(m);
        a[i]=m;
        v.clear();
        loop(j,0,m)
        {
            lell(x);
            v.pb(x);


        }
        tp=tp+m;
        //cout<<v[0]<<"d"<<endl;
        sort(v.begin(),v.end());
        if(v.size()>0)pv=v[0];
        c=0;
        //  cout<<pv<<endl;
        loop(i1,0,v.size())
        {
            // cout<<i1<<" "<<v[i1]<<" "<<pv<<" "<<v.size()<<endl;
            if(pv==v[i1])
            {
                c++;
            }
            else if(pv!=v[i1])
            {
                v1[i].pb(c);
                pv=v[i1];
                c=1;
            }


        }
        v1[i].pb(c);
        // cout<<v1[0][0]<<endl;
    }
    // cout<<tp<<" "<<ncr(4,2)<<"\n";
    loop(i,0,n)
    {
        ans=ans*ncr(tp,a[i]);
        if(ans>=mod)ans=ans%mod;
        loop(i1,0,v1[i].size())
        {
            ans=ans*fact[v1[i][i1]];
            if(ans>=mod)ans=ans%mod;
        }
        tp=tp-a[i];
    }
    cout<<ans<<"\n";

    return 0;
}


