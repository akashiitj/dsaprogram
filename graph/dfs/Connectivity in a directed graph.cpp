

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

vector<int> g[100];
vi gr[100];
int vis[100]= {};
int visr[100]= {};
int parent[100]= {};
int cv=0;
void dfs(int sv)
{
    vis[sv]=1;
    cv++;
    loop(i,0,g[sv].size())
    {
        if(vis[g[sv][i]]==0)
        {
            dfs(g[sv][i]);
        }
    }
}
int cv1=0;
void dfsr(int sv)
{
    visr[sv]=1;
    cv1++;
    loop(i,0,gr[sv].size())
    {
        if(visr[gr[sv][i]]==0)//you are making mistke here using vis instead of visr
        {
            dfsr(gr[sv][i]);

        }
    }
}


int main()
{
    int n,m;
    int v1,v2;
    le2(n,m);
    loop(i,0,m)
    {
        le2(v1,v2);
        g[v1].push_back(v2);
        gr[v2].pb(v1);
    }
    dfs(1);
    dfsr(1);

    if(cv==n&&cv1==n)
        cout<<"yes\n";
    else cout<<"no\n";
    return 0;
}

