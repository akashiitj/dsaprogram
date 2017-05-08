#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

//ll mod= maxn07;

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

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";
ll maxn=10000001;

ll a[10000001]={};
ll p[10000001]={};
ll c[10000001]={};
ll cs[10000001]={};
void sieve()
{
    c[0]=0;
    c[1]=0;
    for(ll i=2;i<maxn;i++)
    {   if(p[i]==0)
        for(ll j=2*i;j<maxn;j=j+i)
        {
            p[j]=1;
            c[i]+=a[j];
        }
    }
     loop(i,2,maxn)
     if(p[i]==0)c[i]+=a[i];

     cs[0]=0;
     cs[1]=0;
     loop(i,2,maxn)
     cs[i]=cs[i-1]+c[i];

}

int main()
{
    ll n;
    ll x;
    lell(n);
    loop(i,0,n)
    {
        lell(x);
        a[x]++;
    }
    sieve();
 //   cout<<"c1\n";
    ll q;
    lell(q);
    loop(i,0,q)
    {
        le2ll(x,n);
        if(n>=maxn)n=10000000;//you
       // if(x>=maxn)x=10000000;
        if(x>n) printf("0\n");
        else
        printf("%I64d\n",cs[n]-cs[x-1]);
    }
    return 0;
}


