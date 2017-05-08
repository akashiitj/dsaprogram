#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<ll>
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

bool isp[1000001]= {};

void seive()
{
    int sz=1000;
    isp[1]=0;
    for(int i=2; i<=1000; i++)
    {
        if(isp[i]==0)
        {
            for(int j=i*i; j<=sz; j=j+i)
            {
                isp[j]=1;
            }
        }
    }
}

map< pair<ll,int>,int > mp1;
map< pair<ll,int>,int > mem;


int ds(ll n)
{
    int ans=0;

    while(n>0)
    {
        ans=ans+(n%10);
        n=n/10;
    }
    return ans;
}

int f(ll n,int p,vi v)
{
    if(isp[ds(n)]==0)
        return 1-p;
    if(mem[mp(n,p)]==1)return mp1[mp(n,p)];
    mem[mp(n,p)]=1;
    ll d=n;
    loop(i,0,v.size())
    {
        if(v[i]==0)continue;
        d=v[i];
        v[i]=0;
        if(f(n/d,1-p,v)==p)return mp1[mp(n,p)]=p;
        v[i]=d;
    }
    return mp1[mp(n,p)]=1-p;

}

int main()
{
    //freopen ("3.in","r",stdin);
    //freopen ("o3.out","w",stdout);
    //cout<<isp[17]<<"\n";

    seive();
    ll n;
    int c=0;


    vi v;
    ll nd;
    frmlty
    {

        v.clear();
        lell(n);
        nd=n;
        //cout<<f(n,0)<<"\n";
        c++;

        ll hv=1LL;

        if(n%2==0)
        {
            while(n%2==0)
            {
                n=n/2;

                hv=hv*1LL*2;
            }
            v.pb(hv);
        }

        for(ll i=3; i*i<=n; i=i+2)
        {
            hv=1LL;
            if(n%i==0)
            {
                while(n%i==0)
                {
                    n=n/i;
                    hv=hv*i;
                }
                v.pb(hv);
            }
        }
        if(n>1)v.pb(n);

        if(f(nd,0,v)==0)
            printf("Case #%d: Laurence\n",c);
        else
            printf("Case #%d: Seymour\n",c);

    }

    return 0;
}


