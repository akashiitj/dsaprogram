
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

ll a[100];
ll b[100];

int main()
{
    freopen("2.in","r",stdin);
    freopen("2o.out","w",stdout);
    ll n,k,c,x;
    int hc=0;
    frmlty
    {
        hc++;
        le2ll(n,k);
        le2ll(c,x);

        loop(i,1,n+1)
        lell(a[i]);

        loop(i,1,n+1)
        lell(b[i]);

        ll fa=0;

        loop(i,1,n-k+2)
        loop(j,1,n-k+2)
        {
            ll pa=-1;
            loop(i1,i,i+k)
            {


                loop(j1,j,j+k)
                {
                    pa=maX(pa,((a[i1]*i1)%x+(b[j1]*j1)%x+c%x)%x);
                    // cout<<pa<<" ";
                }
                // cout<<"\n";
            }
            fa=fa+pa;
        }
        cout<<"Case #"<<hc<<": ";
        cout<<fa<<"\n";
    }

    return 0;
}

