#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

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

//#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define le(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

ll  n, sx, sy , ex, ey, bx, by;
ll inf=10000000;
int visit[25][25];
ll m[25][25];



int main()
{
    frmlty
    {
        le(n);
        le(sx);
        le(sy);
        le(ex);
        le(ey);
        le(bx);
        le(by);

        if(sx==ex&&ex==bx&&(by>sy&&by<ey||by<sy&&by>ey))
        {


            cout<<abs(ey-sy)+2<<"\n";
        }
        else if(sy==ey&&ey==by&&(bx>sx&&bx<ex||bx<sx&&bx>ex))
            cout<<abs(ex-sx)+2<<"\n";
        else cout<<abs(ey-sy)+abs(ex-sx)<<"\n";
    }
    return 0;
}


