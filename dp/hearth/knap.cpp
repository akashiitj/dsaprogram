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

int dp[1001][1001];

int c[1001];
int wa[1001];

int f(int n,int w)
{
    if(dp[n][w]!=-1)return dp[n][w];

    if(n<=0||w<=0)return 0;
    if(wa[n]>w)return dp[n][w]= f(n-1,w);
    return dp[n][w]=max(f(n-1,w),c[n]+f(n-1,w-wa[n]));
}

int main()
{  int n,w;
   frmlty
   {
       loop(i,0,1001)
       loop(j,0,1001)
       dp[i][j]=-1;

       le2(w,n);
       loop(i,0,n)
       {
           le(wa[i+1]);
           le(c[i+1]);
       }

       printf("%d\n",f(n,w));
   }
    return 0;
}


