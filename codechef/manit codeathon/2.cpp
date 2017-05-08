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

string s[301];
int vis[301];
vi g[301];

void dfs(int sv)
{
    vis[sv]=1;
    //cout<<sv<<" "<<g[sv].size()<<"\n";
    loop(i,0,g[sv].size())
    {   //cout<<g[sv][i]<<" ";
        if(vis[g[sv][i]]==0)
            dfs(g[sv][i]);
    }

}

int main()
{
    int n;
    le(n);
    loop(i,0,n)
    cin>>s[i];

    loop(i,0,n)
    {
        loop(j,i+1,n)
        {
            if(s[i][j]=='Y')
            {
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }

    int ans=0;
    loop(i,0,n)
    {
        if(vis[i]==0)
        {
            ans++;
            dfs(i);
        }
    }
    cout<<ans<<"\n";

    return 0;
}


