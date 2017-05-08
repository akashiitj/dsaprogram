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


priority_queue<pii,vector<pii >,greater<pii > > mi;//min priority q
vector<pii > g[10001];
int vis[10001];
int prnt[10001];
int dprnt[10001];
int mindis[10001];

pii dp;
int infi=INT_MAX;

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

void prims(int sv)
{
    pii hv;
    while(sv!=-1)
    {

        vis[sv]=1;
        loop(i,0,g[sv].size())
        {
            int vn=g[sv][i].second;
            if(vis[vn]==0&&mindis[vn]>g[sv][i].first)
            {
                mindis[vn]=g[sv][i].first;
                mi.push(g[sv][i]);
                prnt[vn]=sv;
            }
        }

        hv=vsmin();
        sv=hv.second;
    }
}




int main()
{   int hv1,v2,w;
    char s[34];
    dp.first=-1;
    dp.second=-1;
    frmlty
    {
        le(n);
        loop(i,1,n+1)
        g[i].clear();

        loop(i,1,n+1)
        {
            scanf("%s",&s);
            le(hv1);
            loop(j,0,hv1)
            {
                cin>>v2>>w;
                g[i].pb(mp(w,v2));

            }
        }
        loop(i,1,n+1)
        {
            mindis[i]=infi;
            vis[i]=0;
        }

        mi.push(mp(0,1));
        mindis[1]=0;
        prnt[1]=-1;
        prims(1);
        int ans=0;
        loop(i,1,n+1)
        {
            ans+=mindis[i];

        }
        cout<<ans<<"\n";
    }
    return 0;
}



