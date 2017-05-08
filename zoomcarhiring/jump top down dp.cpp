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

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

double dp[1000005];
double p;
int n;

double f(int n)
{
    if(n<0)return 0.0;
    if(n==0)return 1;
    if(n==1)return 0;
    if(dp[n]!=-1)return dp[n];
    dp[n]=(f(n-2)*(p/100.0))+(f(n-3)*((100.0-p)/100.0));
    // dp[n]=double((double)(f(n-2)*double(p/100.0))+(double)(f(n-3)*(double)((double)(100.0-p)/100.0)));
    return dp[n];
}

int main()
{
    cin>>n>>p;
    loop(i,0,n+1)
    dp[i]=-1;
    dp[0]=1;
    dp[1]=0;
    cout.setf(ios::fixed);
    cout << setprecision(6);
    cout<<f(n)<<"\n";
    return 0;
}


