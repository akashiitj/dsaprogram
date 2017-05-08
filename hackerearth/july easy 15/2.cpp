
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
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

ll f(ll x)
{
    return (x*(x-1))/2;
}

int main()
{
    int n,x;
    ll ce,co;
    frmlty
    {
        int ht[100005]={};
        le(n);
        ce=0;
        co=0;
        loop(i,0,n)
        {
            le(x);
            ht[x]++;
            if(x%2==0)ce++;
            else co++;
        }
        ll ans=f(ce)+f(co);
        loop(i,1,100001)
        {
            if(ht[i]>=2)
                ans=ans-f(ht[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

