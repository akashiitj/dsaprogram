
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

int isp(int n)
{
    int x=0;
    int dn=n;
    while(n>0)
    {
        x=10*x+(n%10);
        n=n/10;
        //  cout<<x<<"\n";
    }
    //cout<<x<<" "<<(x==dn)<<" "<<dn<<"\n";
    return (x==dn);
}

int a[1000002];
int dp[1000002];
int main()
{
    loop(i,0,1000001)
    {
          if(isp(i))a[i]=i;
    }
    a[1000001]=1000001;
    dp[1000001]=a[1000001];
    for(int i=1000000; i>=1; i--)
    {
         dp[i]=dp[i+1];
        if(a[i]!=0)dp[i]=a[i];
        a[i]=dp[i+1];



    }
    int n;
    frmlty
    {
        le(n);
        printf("%d\n",a[n]);
    }

    return 0;
}

