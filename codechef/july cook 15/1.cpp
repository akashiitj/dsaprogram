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

int f(int a,int b,int c,int d)
{
    return(abs(a+b-c-d) +abs(a+c-b-d) + abs(a+d-b-c) + abs(c+d-a-b) + abs(b+d-a-c) + abs(b+c-a-d));
}

int main()
{   int n;
    ll ans;
    frmlty
    {
     le(n);
     int a[n];
     loop(i,0,n)
     le(a[i]);
     ans=0;
     loop(i,0,n-3)
     ans=ans+f(a[i],a[i+1],a[i+2],a[i+3]);
     printf("%lld\n",ans);
    }
    return 0;
}

