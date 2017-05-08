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

int a[100001];
int dp[100001];
int c3[100001]= {};

int main()
{
    int n,q;
    le2(n,q);
    int p1,p2,c=0;
    loop(i,0,n)
    {
        le(a[i]);
        c3[i+1]=c3[i];
        if(a[i]==3)
            c3[i+1]+=1;
    }

    loop(i,1,n+1)
    cout<<c3[i]<<" ";
    cout<<"\n";
    if(a[0]!=3)
        dp[1]=a[0]%3;
    else dp[1]=1;
    loop(i,2,n+1)
    {
        if(a[i-1]!=3) dp[i]=(dp[i-1]*a[i-1])%3;
        else dp[i]=dp[i-1];
    }

    loop(i,1,n+1)
    cout<<dp[i]<<" ";
    cout<<"\n";


    int x,y;
    dp[0]=1;
    loop(i,1,q+1)
    {
        le2(x,y);
        if(c3[y]-c3[x-1]==1)
            printf("0\n");
        else printf("%d\n",(dp[y]*dp[x-1])%3);

    }

    return 0;
}

