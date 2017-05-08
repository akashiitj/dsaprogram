
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

int a[1000001];

int dp[1001][1001];

int main()
{
    int n,m;
    le2(n,m);

    loop(i,1,n+1)
    {
        le(a[i]);
    }
    if(n>=m)
    {
        cout<<"YES\n";
        return 0;
    }

    //dp[0][0]=1;
    int x;
    loop(i,1,n+1)
    {

        dp[i][a[i]%m]=1;
        loop(j,0,m)
        {
            dp[i][j]=dp[i][j]||dp[i-1][j];
            x=((j-a[i]))%m;
            while(x<0)x=x+m;
            dp[i][j]=dp[i][j]||dp[i-1][x%m];
        }

    }
    if(dp[n][0]==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}


