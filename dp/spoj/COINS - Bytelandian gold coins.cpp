
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

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

#define F first
#define S second

priority_queue<pii,vector<pii >,greater<pii > > mi;//min priority q of pair

map<int,ll> m;

bool a[1000000001]={};


ll f(int n)
{
    if(n<=0)return m[n]=0;
    if(n<=3)return m[n]=n;
    if(a[n])return m[n];
    a[n]=true;
    ll hv=f(n/2)+f(n/3)+f(n/4);
    return m[n]=maX(n,hv);
}

int main()
{   int n;
    while(scanf("%d",&n)!=EOF)
    {
        cout<<f(n)<<"\n";
    }
    return 0;
}

