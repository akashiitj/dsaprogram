
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

int dp[10001][2];
int mem[10001][2]= {};
int ele[101];
int e;
int f(int n,int p)
{
    if(mem[n][p]==1)return dp[n][p];
    if(n<=0)return  dp[n][p]=1-p;
    int ans=1-p;
    loop(i,1,e+1)
    {
        if(n-ele[i]>=0&&f(n-ele[i],1-p)==p)
            ans=p;
        if(ans==p)break;
    }
    mem[n][p]=1;
    return  dp[n][p]=ans;
}

int main()
{
    int n;
    frmlty
    {
        le2(n,e);

        loop(i,1,e+1)
        le(ele[i]);

        loop(i,0,n+1)
        {
            mem[i][0]=0;
            mem[i][1]=0;
        }

        if(f(n,0)==0)
            printf("Little Deepu\n");
        else printf("Kate\n");
    }
    return 0;
}

