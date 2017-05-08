
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

ll ch[1001];
ll cv[1001];
ll dp[1001][1001];

int main()
{
    int m,n,x;
    int hc,vc;
    frmlty
    {

        le2(m,n);
        m--;
        n--;
        loop(i,0,m)
        {
            le(ch[i+1]);
        }
        loop(i,0,n)
        {
            le(cv[i+1]);
        }
        sort(ch+1,ch+1+m);
        reverse(ch+1,ch+1+m);
        sort(cv+1,cv+1+n);
        reverse(cv+1,cv+1+n);
        dp[0][0]=0;
        loop(i,1,m+1)
        dp[i][0]=dp[i-1][0]+ch[i];
         loop(i,1,n+1)
        dp[0][i]=dp[0][i-1]+cv[i];

        loop(i,1,m+1)
        {
            loop(j,1,n+1)
            {
                dp[i][j]=miN(dp[i-1][j]+((j+1)*ch[i]),dp[i][j-1]+(i+1)*cv[j]);
            }
        }
        cout<<dp[m][n]<<"\n";


    }
    return 0;
}

