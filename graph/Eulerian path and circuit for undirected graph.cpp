
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
int degree[100];

int c=0;

int dfsc(int sv)
{   c++;
    vis[sv]=1;
    loop(i,0,g[sv].size())
    {
        if(vis[g[sv][i]]==0)
            dfsc(g[sv][i]);
    }
}

int main()
{
    int n,e;
    le2(n,e);
    int x,y;
    loop(i,0,e)
    {
        le2(x,y);
        g[x].pb(y);
        g[y].pb(x);
        degree[x]++;
        degree[y]++;
    }
    dfsc(0);
  // cout<<c<<"\n";
    if(c==n)
    {   int flag=0;
        loop(i,0,n)
        {
            if(degree[i]%2==1)flag=1;
        }
        if(flag==0)
            cout<<"yes\n";
        else cout<<"no\n";
       return 0;
    }
    cout<<"no\n";
    return 0;



}

