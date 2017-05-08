#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


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

vi g[10001];

int main()
{
    int n;
    le(n);
    int x,y;
    while(true)
    {
        le2(x,y);
        if(x==0&&y==0)break;
        if(x>y)
            g[x].pb(y);
        else g[y].pb(x);

    }



    ll dp[10000+1]={};
    dp[1]=1;
    int hv;
    loop(i,2,n+1)
    {
        hv=g[i].size();
        loop(j,0,hv)
        {
            dp[i]+=dp[g[i][j]];

        }
       // cout<<dp[i]<<"\n";
    }
    cout<<dp[n]<<"\n";

    return 0;
}

