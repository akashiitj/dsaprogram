
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

int a[50];
int ans=0;
int n;

void f(int i,vi v)
{
    if(i>n)return;
    if(v.size()==n)
    {
        int ca=0;
        loop(i,0,n/2)
        ca=ca+abs(v[i]-v[n-i-1]);
        ans=maX(ans,ca);
        return;
    }

    vi v1=v;
    v1.pb(a[i]);
    f(i+1,v1);

    if(i!=0)
    {
        if(i+1<n&&a[i+1]%2==0&&v[i-1]%2==0)
        {
              v.pb((a[i+1]+v[i-1])/2);
              f(i+1,v);
        }
    }
}
int main()
{
    frmlty
    {
        ans=0;
        le(n);
        loop(i,0,n)
        le(a[i]);
        vi v;
        f(0,v);
        cout<<ans<<"\n";
    }
    return 0;
}

