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

int dp[100][100];

int main()
{
    string a,b;
    cin>>a>>b;
    int m=a.length();
    int n=b.length();

    int dp[2][n+1];
    memset(dp,0,sizeof dp);
    int pre=0;
    int cur=1;
    dp[0][0]=1;

    loop(i,1,n+1)
    {
        if(b[i-1]=='*')
            dp[0][i]=dp[0][i-1];
        else dp[0][i]=0;
    }

    loop(i,1,m+1)
    {
        loop(j,1,n+1)
        {
            dp[cur][0]=0;
            dp[cur][j]=0;
            if((a[i-1]==b[j-1])||(b[j-1]=='?'))
                dp[cur][j]=dp[pre][j-1];
            else if(b[j-1]=='*')
            {
                dp[cur][j]=dp[cur][j-1]|dp[pre][j];
            }
        }
        swap(pre,cur);
    }

    cout<<dp[pre][n];
    return 0;
}

