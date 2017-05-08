
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

int g[100][100]= { {0, 1, 1, 1},
    {0, 0, 0, 1},
    {0, 0, 0, 1},
    {0, 0, 0, 0}
};
int dp[100][100][1000];
int n,k;

int main()
{
    le2(n,k);
    loop(i,0,n)
    dp[i][i][0]=1;


    loop(e,1,k+1)
    loop(k,0,n)
    loop(i,0,n)
    loop(j,0,n)
    if(g[i][k]&&i!=k)
        dp[i][j][e]+=dp[k][j][e-1];

    cout<<dp[0][3][2];
    return 0;
}

