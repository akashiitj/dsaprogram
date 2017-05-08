#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


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


#define F first
#define S second

//begin

ll fact[200005];
ll ifact[200005];

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
    loop(i,1,200005)
    {
        fact[i]=fact[i-1]*i;
        if(fact[i]>=mod)fact[i]=fact[i]%mod;
    }

    ll invx,x;
    ifact[1]=1;
    ifact[200004]=pow1(fact[200004],mod-2);

    for(ll i=200004-1; i>=2; i--)
    {

        ifact[i]=ifact[i+1]*(i+1);
        if(ifact[i]>=mod)ifact[i]=ifact[i]%mod;
    }
}

ll ncr(int n,int r)
{
    if(r==0 || r==n)return 1;
    ll x=(fact[n]*ifact[r])%mod;
    x=(x*ifact[n-r])%mod;
    return x;
}

//end

pii p[2001];
ll ans[2001];

int main()
{   init();
    int h,w,n;
    le2(h,w);
    le(n);
    loop(i,0,n)
    le2(p[i].first,p[i].second)

    p[n].first=h;
    p[n].second=w;



    sort(p,p+n+1);

 //cout<<"1\n";
    loop(i,0,n+1)
    {
        ans[i]=ncr(p[i].first+p[i].second-2,p[i].first-1);
        loop(j,0,i)
        {
            if(p[j].second>p[i].second)continue;
            ans[i]=ans[i]-(ans[j]*ncr((p[i].first-p[j].first+p[i].second-p[j].second),p[i].first-p[j].first));
            ans[i]%=mod;
            while(ans[i]<0)ans[i]+=mod;
        }
    }
    cout<<ans[n]<<"\n";
    return 0;
}

