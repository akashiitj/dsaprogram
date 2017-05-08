
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

vi g[100];
int vis[100]= {};
int parent[100]= {};
int dv;
vi path;
void dfs(int sv)
{
    vis[sv]=1;
    path.pb(sv);
    if(sv==dv)
    {
        loop(i,0,path.size())
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;
        path.pop_back();
        return ;
    }
    loop(i,0,g[sv].size())
    {
        dfs(g[sv][i]);
    }
    path.pop_back();
}


int main()
{
    int n,m;
    int v1,v2;
    le2(n,m);
    loop(i,0,m)
    {
        le2(v1,v2);
        g[v1].pb(v2);
    }
    cout<<"enter source and destination\n";
    int sv;
    le2(sv,dv);
    dfs(sv);
    return 0;
}

