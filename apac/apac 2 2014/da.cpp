
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

int n,m,k,tm;
int t[550][550][24];
int dp[550][24];
int dis[550];
int vis[550];
vi g[550];

void init()
{
    loop(i,0,510)
    loop(j,0,510)
    loop(k,0,24)
    t[i][j][k]=INT_MAX;

    loop(i,0,510)
    g[i].clear();
}

void da(int sv,int st)
{
    loop(i,0,510)
    dis[i]=INT_MAX;
    memset(vis,0,sizeof vis);
    priority_queue< pair<int,pii >,vector<pair<int,pii > >,greater<pair<int,pii > > > q;

    q.push(mp(0,mp(1,st)));
    dis[1]=0;

    int cv;
    int tm;
    while(q.size()!=0)
    {
        sv=q.top().second.first;
        tm=q.top().second.second;

        q.pop();

        if(vis[sv]==0)
        {
            vis[sv]=1;
            loop(i,0,g[sv].size())
            {
                cv=g[sv][i];
                if(t[sv][cv][tm]!=INT_MAX&&vis[cv]==0&& dis[cv]>=dis[sv]+t[sv][cv][tm])
                {
                    dis[cv]=dis[sv]+t[sv][cv][tm];
                    q.push(mp(dis[cv],mp(cv,(tm+t[sv][cv][tm])%24)));
                }
            }
        }

    }
    loop(i,1,n+1)
    {
        if(dis[i]!=INT_MAX)dp[i][st]=dis[i];
        else dp[i][st]=-1;
    }
}


int main()
{
    freopen("1.in","r",stdin);
    freopen("1o.out","w",stdout);
    int hcv=0;
    int x,y,ti;
    int dv,st;
    frmlty
    {
        hcv++;
        le2(n,m);
        le(k);

        init();

        loop(i,0,m)
        {
            le2(x,y);
            g[x].pb(y);
            g[y].pb(x);
            loop(j,0,24)
            {
                le(ti);
                t[x][y][j]=miN(ti,t[x][y][j]);
                t[y][x][j]=t[x][y][j];
            }
        }

        loop(i,0,24)
        da(1,i);

        cout<<"Case #"<<hcv<<": ";
        loop(i,0,k)
        {
            le2(dv,st);
            printf("%d ",dp[dv][st]);
        }
        printf("\n");

    }
    return 0;
}

