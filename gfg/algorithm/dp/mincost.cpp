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
int a[100][100];
int dp[100][100]= {};
int mem[100][100]= {};
int f(int i,int j)
{
 //   dp[i][j]=10000000;
    if(i==0&&j==0)return dp[i][j]=a[i][j];
    if(mem[i][j]!=0)return dp[i][j];
    mem[i][j]=1;
    dp[i][j]=10000000;
    if(i-1>=0)dp[i][j]=min(dp[i][j],f(i-1,j)+a[i][j]);
    if(j-1>=0)dp[i][j]=min(dp[i][j],f(i,j-1)+a[i][j]);
    if(i-1>=0&&j-1>=0)dp[i][j]=min(dp[i][j],f(i-1,j-1)+a[i][j]);
    //cout<<dp[i][j]<<"\n";
    return dp[i][j];


}

int main()
{
    int n,m;
    le2(m,n);

    loop(i,0,m)
    loop(j,0,n)
    le(a[i][j]);

    cout<<f(--m,--n)<<"\n";
    return 0;
}


