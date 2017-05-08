
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

string s[200];

int dp[200][200];

int main()
{
    int n,m;
    frmlty
    {
        le2(n,m);
        loop(i,0,n)
        cin>>s[i];

        loop(i,0,n)
        loop(j,0,m)
        dp[i][j]=100000;

        loop(i,0,n)
        loop(j,0,m)
        {
            if(s[i][j]=='1')dp[i][j]=0;
            else if(j-1>=0&&dp[i][j-1]!=100000)dp[i][j]=dp[i][j-1]+1;
        }

        loop(i,0,n)
        for(int j=m-1; j>=0; j--)
        {
            if(s[i][j]=='1')dp[i][j]=0;
            else if(j+1<m&&dp[i][j+1]!=100000)dp[i][j]=miN(dp[i][j],dp[i][j+1]+1);
        }


        loop(i,0,m)
        loop(j,0,n)
        {
            if(s[j][i]=='1')dp[j][i]=0;
            else if(j-1>=0&&dp[j-1][i]!=100000)dp[j][i]=miN(dp[j][i],dp[j-1][i]+1);
        }

        loop(i,0,m)
        for(int j=n-1; j>=0; j--)
        {
            if(s[j][i]=='1')dp[j][i]=0;
            else if(j+1<n&&dp[j+1][i]!=100000)dp[j][i]=miN(dp[j][i],dp[j+1][i]+1);
        }


        loop(i,0,n)
        {
            loop(j,0,m)
            {
               cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }

    }

    return 0;
}

