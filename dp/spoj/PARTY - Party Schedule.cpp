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

int dp[101][501];

int f[101];
int w[101];

int main()
{
    int n,tw;
    while(true)
    {

        le2(tw,n);
        if(tw==0&&n==0)
            break;

        loop(i,1,n+1)
        le2(w[i],f[i]);
        int ans=0;
        //int x,y;
        loop(i,1,n+1)
        {
            loop(j,0,tw+1)
            {   dp[i][j]=0;
                dp[i][j]=dp[i-1][j];//you forgot this
                if(w[i]<=j) dp[i][j]=maX(dp[i-1][j],dp[i-1][j-w[i]]+f[i]);

            }

        }
        int answ;
        loop(j,0,tw+1)
        {
            if(dp[n][j]==dp[n][tw])
            {answ=j;break;}
        }


        cout<<answ<<" "<<dp[n][tw]<<"\n";
    }
    return 0;
}

