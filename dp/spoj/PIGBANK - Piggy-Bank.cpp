//using coin change approach
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



int f[501];
int w[501];

int dp1[10001];

int main()
{
    int n,tw,ew;

    frmlty
    {
        le(ew);
        le2(tw,n);

        tw=tw-ew;

        loop(i,1,n+1)
        le2(f[i],w[i]);


        loop(j,1,tw+1)
        dp1[j]=-1;

        dp1[0]=0;
        loop(i,1,n+1)
        {
            loop(j,1,tw+1)
            {
               if(j>=w[i]&&dp1[j-w[i]]!=-1&&dp1[j]==-1) dp1[j]=dp1[j-w[i]]+f[i];
               if(j>=w[i]&&dp1[j-w[i]]!=-1) dp1[j]=min(dp1[j],dp1[j-w[i]]+f[i]);
              // if(j>=w[i]&&dp1[j-w[i]]!=-1&&dp1[j]!=-1) dp1[j]=min(dp1[j],dp1[j-w[i]]+f[i]);

            }

        }
        if(dp1[tw]!=-1&&tw!=0)
            cout<< "The minimum amount of money in the piggy-bank is "<<dp1[tw]<<".\n";
        else
            cout<<"This is impossible.\n";

    }
    return 0;
}

//usinf knapsack approach
/*
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

int dp[501][10005];

int f[501];
int w[501];

int main()
{
    int n,tw,ew;

    frmlty
    {
        le(ew);
        le2(tw,n);

        tw=tw-ew;

        loop(i,1,n+1)
        le2(f[i],w[i]);
        int ans=0;

        loop(j,1,tw+1)
        dp[0][j]=-1;

        loop(j,0,n+1)
        dp[j][0]=0;
        //int x,y;
        loop(i,1,n+1)
        {
            loop(j,1,tw+1)
            {
                dp[i][j]=-1;
                if(dp[i-1][j]!=-1) dp[i][j]=dp[i-1][j];//you forgot this
                if(w[i]<=j&&dp[i][j-w[i]]!=-1&&dp[i][j]!=-1) dp[i][j]=miN(dp[i][j],dp[i][j-w[i]]+f[i]);
                if(w[i]<=j&&dp[i][j-w[i]]!=-1&&dp[i][j]==-1) dp[i][j]=dp[i][j-w[i]]+f[i];
               // cout<<dp[i][j]<<" ";
            }
          //  cout<<"\n";
        }
        if(dp[n][tw]!=-1&&tw!=0)//forgot this tw part
            cout<< "The minimum amount of money in the piggy-bank is "<<dp[n][tw]<<".\n";
        else
            cout<<"This is impossible.\n";

    }
    return 0;
}
*/
