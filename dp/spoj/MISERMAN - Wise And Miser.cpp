
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

int a[101][101];

int main()
{
    int n,m;
    le2(n,m);
    loop(i,0,n)
    loop(j,0,m)
    le(a[i][j]);

    int dp[m];
    loop(i,0,m)
    dp[i]=a[0][i];
    int x;

    loop(j,0,m)
        cout<<dp[j]<<" ";
        cout<<"\n";
    for(int i=1;i<n;i++)
    {
        loop(j,0,m)
        {    x=a[i-1][j];
             if(j-1>=0)x=miN(x,a[i-1][j-1]);
             if(j+1<m)x=miN(x,a[i-1][j+1]);
             dp[j]+=x;
        }
        loop(j,0,m)
        cout<<dp[j]<<" ";
        cout<<"\n";
    }
    x=dp[0];
    loop(j,0,m)
    x=miN(x,dp[j]);

    cout<<x<<"\n";

    return 0;
}


