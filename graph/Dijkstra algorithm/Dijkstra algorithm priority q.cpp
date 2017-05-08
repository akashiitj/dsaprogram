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

int n;

struct compare
{
  bool operator()(const int& l, const int& r)
  {
      return l > r;
  }
};

priority_queue<pii,vector<pii >,greater<pii > > mi;//min priority q

vector<pii > g[100];
int vis[100];
int mindis[100];

pii dp;
int infi=1000000;

pii vsmin()
{
    while(mi.size()!=0)
    {
        pii x=mi.top();
        mi.pop();
        if(vis[x.second]==0)
            return x;

    }
    return dp;
}

void da(int sv)
{
    pii hv;
    while(sv!=-1)
    {

        vis[sv]=1;
        loop(i,0,g[sv].size())
        {
            int vn=g[sv][i].second;
            if(vis[vn]==0&&mindis[vn]>mindis[sv]+g[sv][i].first)
            {
                mindis[vn]=mindis[sv]+g[sv][i].first;
                mi.push(g[sv][i]);
            }
        }

        hv=vsmin();
        sv=hv.second;
    }
}

int main()
{
    cin>>n;
    dp.first=-1;
    dp.second=-1;
    while(true)
    {
        int v1,v2,d;
        cin>>v1;
        if(v1==-1)break;
        cin>>v2>>d;
        g[v1].pb(mp(d,v2));
    }

     loop(i,1,n+1)
    {
        mindis[i]=infi;
        vis[i]=0;
    }

    int sv;
    le(sv);
    mi.push(mp(0,sv));
    mindis[sv]=0;
    da(sv);

    loop(i,1,n+1)
    {
        cout<<mindis[i]<<" ";

    }
    cout<<"\n";

    return 0;
}

