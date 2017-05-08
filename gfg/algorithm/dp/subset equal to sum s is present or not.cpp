
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


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

int a[100];
int dp[100][1000]={};//upto elemen i use karke if it is possible to form subset whose sum equal to j
int n;
void f(int sum)
{
    loop(i,1,sum+1)
    dp[0][i]=0;

    loop(i,0,n+1)
    dp[i][0]=1;

    loop(i,1,n+1)
    {
        loop(j,1,sum+1)
        {
            dp[i][j]=dp[i-1][j];
            if(a[i]<=j)dp[i][j]=dp[i][j]|dp[i-1][j-a[i]];
        }
    }
}

int main()
{
    int nl,sum;
    le2(n,sum);
    loop(i,0,n)
    le(a[i+1]);

    f(sum);
    cout<<dp[n][sum];
    return 0;
}

