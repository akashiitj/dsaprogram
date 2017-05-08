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
#define lell(x) scanf("%lld",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second


string s[1000001];
ll st[1000000];
ll l[1000000];
ll lazy[1000000];
ll a[100001];

ll loa(ll x)
{
    ll ans=0;
    while(x>0)
    {

        x=x/(10*1LL);
        ans++;
    }
    return ans;
}

ll mod1(ll x)
{
    return x%1000000007;
}

ll stoi1(string s)
{
    ll x=0;
    loop(i,0,s.length())
    x=x*10+ll(s[i]-'0');

    x=x%mod;
    return x;
}


ll fast_mul(ll A,ll pow)
{
    ll C=1;


    while(pow>0)
    {
        if(pow&1)
        {
            C=C*A;
            C=mod1(C);

        }
        A=mod1(A*A);
        pow>>=1;
    }
    return mod1(C);
}

void build(ll sti,ll si,ll ei)
{
    if(si==ei)
    {
        a[si]=stoi1(s[si]);
        st[sti]=a[si]%mod;
        l[sti]=s[si].length();
        lazy[sti]=0;
        return;
    }
    lazy[sti]=0;
    ll mid=(si+ei)/2;
    build(2*sti,si,mid);
    build((2*sti)+1,mid+1,ei);

    st[sti]=mod1(mod1(st[2*sti]*fast_mul(10,l[(2*sti)+1]))+st[(2*sti)+1]);
    l[sti]=l[2*sti]+l[2*sti+1];
}

pair<ll,ll> cnt(ll i,ll j,ll sti,ll si,ll ei)
{
    if(i<=si&&j>=ei)
    {
        return mp(st[sti],l[sti]);
    }
    if(j<si||i>ei)return mp(0,0);
    ll mid=(si+ei)/2;
    pair<ll,ll> l=cnt(i,j,2*sti,si,mid);
    pair<ll,ll> r=cnt(i,j,(2*sti)+1,mid+1,ei);

    ll n=mod1(mod1(l.first*fast_mul(10,r.second))+r.first);
    ll l1=l.second+r.second;
    return mp(n,l1);
}

void update(ll i,string nn,ll sti,ll si,ll ei)
{
    if(i<si||i>ei)return;
    if(si==ei)
    {
        st[sti]=stoi1(nn);
        l[sti]=nn.length();
        return;
    }
    if(si!=ei)//condition for base case
    {
        ll mid=(si+ei)/2;
        update(i,nn,sti*2,si,mid);
        update(i,nn,(sti*2)+1,mid+1,ei);
        st[sti]=mod1(mod1(st[2*sti]*fast_mul(10,l[(2*sti)+1]))+st[(2*sti)+1]);
        l[sti]=l[2*sti]+l[2*sti+1];
    }
}

int main()
{

    ll n,m;
    lell(n);
    loop(i,1,n+1)
    cin>>s[i];

    build(1,1,n);
    ll x;
    ll c=1;
    ll l,r;
    ll pn;
    ll nv;
    lell(m);
    string s11;
    loop(i,0,m)
    {
        lell(x);
        if(x==0)
        {
            le2ll(l,r);
            cout<<cnt(l,r,1,1,n).first<<"\n";

        }
        if(x==1)
        {
            lell(pn);
            cin>>s11;
            update(pn,s11,1,1,n);
        }
    }
    return 0;
}


