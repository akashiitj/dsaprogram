

#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1299709;

//cout<<fixed<<setprecision(6)<<output1<<"\n";

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

ll fibo[5000010];
ll csfibo[5000010];
ll s[5000010];
ll cs[5000010];

int n,m;
n=5000010;

void pre()
{
    fibo[1]=1;
    fibo[2]=1;
    loop(i,3,n)
    fibo[i]=(fibo[i-1]+fibo[i-2])%mod;

    csfibo[1]=1;
    csfibo[2]=2;
    loop(i,3,n)
    csfibo[i]=(csfibo[i-1]+fibo[i])%mod;

    ll res=0;
    s[1]=0;
    loop(i,2,n)
    {
        s[i]=(s[i-1]+(fibo[i]*csfibo[i-1])%mod)%mod;

    }
    cs[1]=s[1];
    loop(i,2,n)
    {
        cs[i]=(cs[i-1]+s[i])%mod;

    }
}

int main()
{

    int a,b;

    pre();
    int output1;
    frmlty
    {
        le2(a,b);
        output1=(cs[b]-cs[a-1])%mod;
        while(output1<0)
        {
           output1=(output1+mod)%mod;
        }

        printf("%d\n",output1);
    }
    return 0;
}

