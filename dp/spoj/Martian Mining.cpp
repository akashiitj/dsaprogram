
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

int a[501][501][2];
int ca[501][501][2];//stores cumulative sum

int dp[505][505];

int main()
{
    int m,n;
    while(true)
    {
        le2(m,n);
        if(m==0&&n==0)break;
        loop(i,1,m+1)
        loop(j,1,n+1)
        le(a[i][j][0]);

        loop(i,1,m+1)
        {
            loop(j,1,n+1)
            {
                ca[i][j][0]=ca[i][j-1][0]+a[i][j][0];

            }

        }

        loop(i,1,m+1)
        loop(j,1,n+1)
        le(a[i][j][1]);


        loop(i,1,n+1)
        {
            loop(j,1,m+1)
            {
                ca[j][i][1]=ca[j-1][i][1]+a[j][i][1];//spend 1 hour due to a[i][j][1]
                //cout<<ca[j][i][1]<<" ";
            }
            //cout<<"\n";
        }


//        cout<<"\n";
        loop(i,1,m+1)
        {
            loop(j,1,n+1)
            {
                dp[i][j]=maX(dp[i][j-1]+ca[i][j][1],dp[i-1][j]+ca[i][j][0]);
                // dp[i][j]=maX(maX(dp[i-1][j]+ca[i][j][0],ca[i][j][1]),dp[i][j]);
                // cout<<dp[i][j]<<" ";
            }

        }
        cout<<dp[m][n]<<"\n";

    }

    return 0;
}

