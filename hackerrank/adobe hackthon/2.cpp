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

int ht[1000001];
ll dp[1000001];
ll mod1(ll x)
{
    return x%1000000007;
}

ll fast_mul(ll A,ll pow)
{
    ll C=1;


    while(pow>0)
    {
        if(pow&1)
        {
            C=C*A;
            C=mod1(C);

        }
        A=mod1(A*A);
        pow>>=1;
    }
    return mod1(C);
}

int a[1000001];
int main()
{
    int n;
    le(n);
    int x;

    loop(i,0,n)
    {
        le(x);
        a[i]=x;
        ht[x]++;
    }
    ll sub;
    ll c;
    ll ans;
    for(int i=1000000; i>=1; i--)
    {

        sub=0;
        c=ht[i];

        for(int j=2*i; j<=1000000; j=j+i)
        {
            c+=ht[j];
            sub=mod1(sub+dp[j]);
        }
        ans=fast_mul(2,c)-1;
        while(ans<0)ans+=1000000007;
        ans=ans-sub;
        while(ans<0)ans+=1000000007;
        dp[i]=ans;
    }

    loop(i,0,n)
    printf("%lld ",dp[a[i]]);
    cout<<"\n";
    return 0;
}


