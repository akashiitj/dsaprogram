

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

double dp[2001][2001]= {0.0};

int main()
{
    int n;
    le(n);
    double p;
    cin>>p;
    int t;
    le(t);

    dp[1][1]=p;
    dp[0][1]=1-p;
    loop(i,2,t+1)
    {
        loop(j,0,min(i+1,n+1))
        {
            if(j-1>=0)dp[j][i]+=dp[j-1][i-1]*p;
            if(j!=n) dp[j][i]+=dp[j][i-1]*(1-p);
            if(j==n)dp[j][i]+=dp[j][i-1];//you forgot this
        }
    }

    double ans=0.0;
    loop(i,1,n+1)
    {
        ans=ans+dp[i][t]*(double)i;
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
    return 0;
}


