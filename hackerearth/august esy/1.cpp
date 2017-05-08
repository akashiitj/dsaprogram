
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

int a[100001];
int p[100001];
int vis[100001];
vi v[100001];
vi pos[100001];

int main()
{
    int n;
    le(n);
    ll t;
    cin>>t;
    loop(i,1,n+1)
    le(a[i]);

    loop(i,1,n+1)
    le(p[i]);
    int comp=0;
    loop(i,1,n+1)
    {
        if(vis[i]==0)
        {
            int j=i;
            int source=i;
            comp++;
            while(p[j]!=source)
            {
                vis[j]=1;
                v[comp].pb(a[j]);
                pos[comp].pb(j);
                j=p[j];
            }
            vis[j]=1;
            v[comp].pb(a[j]);
            pos[comp].pb(j);
        }
    }
    vi ta;
    loop(i,1,comp+1)
    {
        ta.clear();
        loop(j,0,v[i].size())
        ta.pb(v[i][j]);
        loop(j,0,v[i].size())
        ta.pb(v[i][j]);
        ll r=t%(ll)v[i].size();
        loop(j,0,v[i].size())
        a[pos[i][j]]=ta[r+j];
    }

    loop(i,1,n+1)
    printf("%d ",a[i]);

    cout<<"\n";
    return 0;
}

