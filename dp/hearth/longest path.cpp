//https://www.hackerearth.com/problem/algorithm/longest-increasing-path-9/

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

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%%I64d",&x);
#define le2ll(x,y) scanf("%%I64d%%I64d",&x,&y);


int main()
{   int n,m;
    frmlty
    {
      le2(n,m);
      int a[n][m];
      int dp[100][100]={1};

      loop(i,0,n)
      loop(j,0,m)
      {le(a[i][j]);
       dp[i][j]=-1;
      }
      dp[0][0]=1;

      int ans=0;

      loop(i,0,n)
      loop(j,0,m)
      {
          if(i-1>=0&&a[i-1][j]<a[i][j]&&dp[i-1][j]!=-1)
          {
              dp[i][j]=1+dp[i-1][j];
          }
          if(j-1>=0&&a[i][j-1]<a[i][j]&&dp[i][j-1]!=-1)
          {
              dp[i][j]=max(dp[i][j],1+dp[i][j-1]);
          }
          ans=max(ans,dp[i][j]);

      }
      cout<<ans<<"\n";

    }
    return 0;
}


