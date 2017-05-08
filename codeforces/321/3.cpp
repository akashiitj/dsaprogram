#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
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
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

#define fi first;
#define se second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

vi g[100001];
int isc[100001];
int ck[100001];
int ckm[100001];
int vis[100001];

int total =0;
int ans=0;

int n,m;

void f(int sv,int p)
{
    vis[sv]=1;
    if(isc[sv]==0)ck[sv]=0;
    else if(isc[sv]==1)
    {
        ck[sv]=ck[p]+1;

    }
    ckm[sv]=maX(ck[sv],ckm[p]);
    int flag=0;

    loop(i,0,g[sv].size())
    {
        if(vis[g[sv][i]]==0)
        {
            flag=1;
            f(g[sv][i],sv);
        }
    }

    if(flag==0)
    {
        total++;
        if(ckm[sv]>m)ans++;
    }
}

int main()
{

    le2(n,m);

    int x,y;

    loop(i,1,n+1)
    {
        le(isc[i]);
    }

    loop(i,1,n)
    {
        le2(x,y);
        g[x].pb(y);
        g[y].pb(x);
    }

    f(1,0);


    cout<<total-ans<<"\n";


    return 0;
}



