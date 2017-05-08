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

#define le(x) scanf("%llu",&x);
#define le2(x,y) scanf("%llu%llu",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

int main()
{
    ll n,m,l,d;
    ll ans,hv;
    frmlty
    {
        ans=0;
        lell(m);
        int flag=0;
        loop(i,0,m)
        {
            le2ll(l,d);
            if(d!=0)flag=1;
            ans=(ans+(l*d))%9;
        }
        if(ans==0&&flag==1)printf("9\n");
        else cout<<ans<<"\n";
    }
    return 0;
}
