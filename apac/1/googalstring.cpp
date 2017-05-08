
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

int f(ll k)
{
    if(k==1)
        return 0;
    ll n=1LL;
    while(k>=n)
        n=n*2*1LL;
    n=n/2;
    ll rem=k-n;
    if(rem==0)return 0;
    return (1-(f(n-rem)));
}


int main()
{
    freopen("aa.in","r",stdin);
	freopen("aa.out","w",stdout);
    ll k;
    int c=0;
    frmlty
    {  c++;
        lell(k);
        cout<<"Case #"<<c<<": ";
        cout<<f(k)<<"\n";
    }
    return 0;
}

