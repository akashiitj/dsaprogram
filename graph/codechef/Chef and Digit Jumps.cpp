
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
#define pb        push
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

vi g[10];

int vis[100001];
int dis[100001];
int vis1[10];//it prevent tle

int main()
{

    string s;
    cin>>s;
    loop(i,0,s.length())
    {
        g[s[i]-'0'].push_back(i);
    }
    queue<int > q;
    q.pb(0);
    dis[0]=0;
    vis[0]=1;
    int tp;
    while(true)
    {
        tp=q.front();
        q.pop();
      //  cout<<tp<<"\n";
        if(tp==(s.length()-1))
        {
            cout<<dis[tp]<<"\n";
            return 0;
        }
        if(vis1[s[tp]-'0']==0)
        loop(i,0,g[s[tp]-'0'].size())
        {
                if(vis[g[s[tp]-'0'][i]]==0)
                {
                q.pb(g[s[tp]-'0'][i]);
                dis[g[s[tp]-'0'][i]]=dis[tp]+1;
                vis[g[s[tp]-'0'][i]]=1;
                }
                vis1[s[tp]-'0']=1;
        }
        if(tp-1>=0&&vis[tp-1]==0&&vis1[s[tp-1]-'0']==0)
        {
            q.pb(tp-1);
            dis[tp-1]=dis[tp]+1;
            vis[tp-1]=1;
        }
        if(tp+1<s.length()&&vis[tp+1]==0&&vis1[s[tp+1]-'0']==0)
        {
            q.pb(tp+1);
            dis[tp+1]=dis[tp]+1;
            vis[tp+1]=1;
        }
    }
    return 0;
}

