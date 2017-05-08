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
            // cout<<C<<" "<<mod1(A)<<endl;
        }
        A=mod1(A*A);
        pow>>=1;
    }
    return mod1(C);
}

int main()
{
    ll n;
    frmlty
    {
        lell(n);
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        if(n==2)
        {
            printf("4\n");
            continue;
        }
        ll x1=2*fast_mul(3,n-1)+mod1((fast_mul(3,n-2)-1)*fast_mul(2,mod-2));
        ll x2=fast_mul(2,n-1);
        x1=mod1(x1-x2);
        while(x1<0)x1=x1+mod;

        printf("%lld\n",x1);
    }
    return 0;
}


