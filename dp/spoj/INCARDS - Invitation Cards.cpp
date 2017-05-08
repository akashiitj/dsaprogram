
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
#define pii       pair<ll,int>

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
priority_queue<pii,vector<pii >,greater<pii > > mi,mir;//min priority q

vector<pii > g[1000005];
vector<pii > gr[1000005];
int vis[1000005];
int visr[1000005];
ll mindis[1000005];
int mindisr[1000005];

pii dp;
ll infi=100000000000000LL;

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

pii vsminr()
{
    while(mir.size()!=0)
    {
        pii x=mir.top();
        mir.pop();
        if(visr[x.second]==0)
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

void dar(int sv)
{
    pii hv;
    while(sv!=-1)
    {

        visr[sv]=1;
        loop(i,0,gr[sv].size())
        {
            int vn=gr[sv][i].second;
            if(visr[vn]==0&&mindisr[vn]>mindisr[sv]+gr[sv][i].first)
            {
                mindisr[vn]=mindisr[sv]+gr[sv][i].first;
                mir.push(gr[sv][i]);
            }
        }

        hv=vsminr();
        sv=hv.second;
    }
}



int main()
{
    int e;
    int v1,v2;
    ll d;
    //cout<<infi<<"\n";
    frmlty
    {
        //cin>>n>>e;
        le2(n,e);
        loop(i,1,n+1)
        {
            gr[i].clear();
            g[i].clear();
        }
        dp.first=-1;
        dp.second=-1;
        while(e--)
        {

            le2(v1,v2);
            lell(d);
            //cin>>v2>>d;
            g[v1].pb(mp(d,v2));
            gr[v2].pb(mp(d,v1));
        }

        loop(i,1,n+1)
        {
            mindis[i]=infi;
            mindisr[i]=infi;
            vis[i]=0;
            visr[i]=0;
        }

        int sv=1;
        mi.push(mp(0,sv));
        mir.push(mp(0,sv));
        mindis[sv]=0;
        mindisr[sv]=0;
        da(sv);
        dar(sv);
        ll ans=0,ans2=0;
        loop(i,1,n+1)
        {
            ans+=mindis[i];
            ans+=mindisr[i];
        }
        printf("%lld\n",ans);

    }
    return 0;
}

