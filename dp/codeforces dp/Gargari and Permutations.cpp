
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

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

int a[7][1000+1];

vector<int> g[1001];

int vis[1001]={0};
int ml[1001];
int ans=1;
void dfs(int i)
{
    vis[i]=1;
    ml[i]=1;
    int best=0;
    loop(j,0,g[i].size())
    {
        if(vis[g[i][j]]==0)
        {
            dfs(g[i][j]);

        }
        best=maX(best,ml[g[i][j]]);
    }
    ml[i]=maX(ml[i],1+best);
    ans=maX(ans,ml[i]);
}

int main()
{
    int n,k;
    le2(n,k);
    int x;
    loop(i,1,k+1)
    {
        loop(j,1,n+1)
        {    le(x);
             a[i][x]=j;
        }
    }
    int c=0;
    loop(j,1,n+1)
    loop(i,1,n+1)
    {   if(i==j)continue;
        c=0;
        loop(i1,1,k+1)
        if(a[i1][j]<a[i1][i])c++;

        if(c==k)
            g[j].pb(i);
    }



    loop(i,1,n+1)
    {
        if(vis[i]==0)
            dfs(i);
    }
//    loop(i,1,n+1)
//    cout<<ml[i]<<" ";
//    cout<<"\n";
    cout<<ans<<"\n";
    return 0;
}


