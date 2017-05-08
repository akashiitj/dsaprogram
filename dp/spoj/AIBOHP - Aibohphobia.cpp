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

//ll dps[101][101];
int dp[6200][6200];
int m[101];

int main()
{
    int n;
    string s;
    frmlty
    {

        cin>>s;
        n=s.length();
        loop(i,1,n+1)
        {
            dp[i][i]=0;

        }

        loop(i,1,n)
        {
            dp[i][i+1]=1*(s[i-1]!=s[i+1-1]);
          cout<<dp[i][i+1]<<" ";
        }
   cout<<"\n";
        loop(l,3,n+1)
        {
            loop(i,1,n-l+1+1)
            {   dp[i][i+l-1]=INT_MAX;
               if(s[i-1]==s[i+l-2]) dp[i][i+l-1]=dp[i+1][i+l-2];

               dp[i][i+l-1]=miN(miN(dp[i][i+l-2],dp[i+1][i+l-1])+1,dp[i][i+l-1]);



            }

        }
        cout<<dp[1][n]<<"\n";

    }
    return 0;
}
