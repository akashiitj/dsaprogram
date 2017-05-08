
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
int ht[100]={};

int dfs(int sv)
{
    vis[sv]=1;
    ht[sv]=1;//mark it 1 as you are going to explore its subtree
    loop(i,0,g[sv].size())
    {
        if(vis[g[sv][i]]==0)
        {

            if(dfs(g[sv][i]))
            {
                return 1;
            }
        }
        else if(ht[g[sv][i]])
        {
            return 1;
        }
    }
    ht[sv]=0;//mark it 0 when you finished exploring its subtree
    return 0;
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
    int flag=0;
    loop(i,0,n)
    {
        if(vis[i]==0&&dfs(i)==1)
        {   flag=1;
            cout<<"cycle\n";
            return 0;
        }

    }
    if(flag==0)
    cout<<"no cycle\n";

    return 0;
}

