
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

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);

double slp[2001][2001];
ll den[2001][2001];

int main()
{
    ll n,x,y;
    cin>>n;

    vector<pair<ll,ll> >v;
    loop(i,0,n)
    {
        cin>>x>>y;
        v.pb(mp(x,y));
    }
    if(n<=2)
    {
        cout<<"0\n";
        return 0;
    }
    sort(v.begin(),v.end());
    ll cp=0;
    double s,css;
    loop(i,0,n)
    {
        loop(j,i+1,n)
        {
          slp[i][j]=  double(v[j].second-v[i].second)/(v[j].first-v[i].first);
        }
    }
    loop(i,0,n)
    {
        loop(j,i+1,n)
        {

            loop(k,j+1,n)
            {

                if(slp[i][j]==slp[i][k])cp++;
            }
        }
    }
    ll ans;
    ans=n*(n-1)*(n-2);
    //  cout<<ans/6<<" "<<cp<<endl;
    ans=(ans/6)-cp;
    cout<<ans<<"\n";

    return 0;

}
