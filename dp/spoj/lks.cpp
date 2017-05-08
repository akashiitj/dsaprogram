#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);

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

int dp[2][2000001];

int c[501];
int wa[501];

int f(int n,int w)
{
    int pre=0;
    int cur=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=w; j++)
        {
            dp[cur][j]=dp[pre][j];
            if(wa[i]<=j)dp[cur][j]=maX(dp[pre][j],dp[pre][j-wa[i]]+c[i]);

            //cout<<dp[cur][j]<<" ";
        }
        //cout<<"\n";
        swap(pre,cur);
    }
    return dp[pre][w];
}

int main()
{
    int n,w;



    le2(w,n);
    loop(i,0,n)
    {
        le(c[i+1]);
        le(wa[i+1]);
    }

    printf("%d\n",f(n,w));

    return 0;
}


