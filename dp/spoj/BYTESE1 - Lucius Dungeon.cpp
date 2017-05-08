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

int m,n;
int a[101][101];
//int dp[101][101];
int vis[101][101];
int mindis[101][101];

priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > mi,mid;//min priority q

vector<pair<int,pair<int,int> > > g[101];


pair<int,pair<int,int> > dp1;
int infi=INT_MAX;

int fx,fy,tt;

pair<int,pair<int,int> > vsmin()
{
    while(true)
    {
        pair<int,pair<int,int> > x=mi.top();
        mi.pop();
        if(vis[x.second.first][x.second.second]==0)
            return x;

    }

}

int da(int x,int y)
{
    pair<int,pair<int,int> > hv;
    while(true)
    {   //cout<<x<<" "<<y<<" "<<mindis[x][y]<<"\n";
        if(x==fx&&y==fy)
            return mindis[x][y];

        vis[x][y]=1;

        if(x+1<m&&vis[x+1][y]==0&&mindis[x+1][y]>mindis[x][y]+a[x+1][y])
        {
            mindis[x+1][y]=mindis[x][y]+a[x+1][y];
            mi.push(mp(mindis[x+1][y],mp(x+1,y)));

        }
        if(x-1>=0&&vis[x-1][y]==0&&mindis[x-1][y]>mindis[x][y]+a[x-1][y])
        {
            mindis[x-1][y]=mindis[x][y]+a[x-1][y];
            mi.push(mp(mindis[x-1][y],mp(x+1,y)));

        }

        if(y+1<n&&vis[x][y+1]==0&&mindis[x][y+1]>mindis[x][y]+a[x][y+1])
        {
            mindis[x][y+1]=mindis[x][y]+a[x][y+1];
            mi.push(mp(mindis[x][y+1],mp(x,y+1)));

        }
        if(y-1>=0&&vis[x][y-1]==0&&mindis[x][y-1]>mindis[x][y]+a[x][y-1])
        {
            mindis[x][y-1]=mindis[x][y]+a[x][y-1];
            mi.push(mp(mindis[x][y-1],mp(x,y-1)));

        }

        hv=vsmin();
        x=hv.second.first;
        y=hv.second.second;
    }
}

int main()
{
    dp1.second.first=-1;
    dp1.second.second=-1;
    frmlty
    {
        le2(m,n);
        loop(i,0,m)
        loop(j,0,n)
        le(a[i][j]);

        loop(i,0,m)
        loop(j,0,n)
        {
            mindis[i][j]=infi;
            vis[i][j]=0;
        }
        mindis[0][0]=a[0][0];
        le2(fx,fy);
        le(tt);
        fx--;
        fy--;
        while(!mi.empty())mi.pop();
        int ans=da(0,0);
        if(tt>=ans)
        {
            printf("YES\n");
            tt=tt-ans;
            printf("%d\n",tt);
        }
        else
            printf("NO\n");
    }
    return 0;
}

