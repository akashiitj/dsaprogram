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

int dp[100001][2];
int mem[100001][2]= {};
int f(int n,int p)
{
    if(mem[n][p]!=0)return dp[n][p];
    mem[n][p]=1;
    if(n==4)return dp[n][p]=1-p;
    if(n==1||n==2||n==3)return dp[n][p]= p;

    if(f(n-1,1-p)==p||f(n-2,1-p)==p||f(n-3,1-p)==p)return dp[n][p]=p;
    else return dp[n][p]=1-p;
}

int main()
{
    int n;
    frmlty
    {
        le(n);
        if(f(n,1)==1)
            printf("First\n");
        else printf("Second\n");

    }
    return 0;
}


