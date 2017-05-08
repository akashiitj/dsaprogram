
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

int v1[40001];
int v2[40001];

vi g[5001];

int vis[5001]= {};
int parent[5001]= {};
int cv;
int dfs(int sv)
{
    vis[sv]=1;
    cv++;
    loop(i,0,g[sv].size())
    {
        if(vis[g[sv][i]]==0)
        {
            parent[g[sv][i]]=sv;
            if(dfs(g[sv][i]))
            {
                return 1;
            }
        }
        else if(parent[sv]!=g[sv][i])//you are making mistake here,you are at a vertex(sv) and you are going to visit its child and it is not its parent
        {
            return 1;
        }
    }
    return 0;
}


int main()
{   int n,m,x;
    frmlty
    {
      le2(n,m);
      loop(i,1,m+1)
      {
          le2(v1[i],v2[i]);
      }
      loop(i,1,n+1)
    {
      parent[i]=0;
      vis[i]=0;
      g[i].clear();
    }
      loop(i,1,n)
      {
          le(x);
          g[v1[x]].pb(v2[x]);
          g[v2[x]].pb(v1[x]);
      }
      cv=0;
      if(dfs(v1[x])==0&&cv==n)
        printf("YES\n");
      else  printf("NO\n");

    }
    return 0;
}

