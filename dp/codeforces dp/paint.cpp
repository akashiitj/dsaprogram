
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


int main()
{
    int n,p;
    le2(n,p);
    int dp[n][p];
    int x;

    loop(i,0,n)
    {
        loop(j,0,p)
        {   le(x);
          dp[i][j]=x;
        }}

    loop(i,0,n)
    {
        loop(j,0,p)
        {   x=dp[i][j];
            if(i==0&&j==0)
            {
                dp[i][j]=x;
            }
            else if(i==0&&j>0)
            {
                dp[i][j]=x+dp[0][j-1];
            }
            else if(j==0) dp[i][j]=dp[i-1][j]+x;
            else dp[i][j]=max(dp[i-1][j]+x,dp[i][j-1]+x);

        }
         cout<<dp[i][p-1]<<" ";
    }
    cout<<"\n";
        return 0;
}


