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
#define loopint(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

ll fast_mul(ll A,ll pow)
{
    ll C=1;


    while(pow>0)
    {
        if(pow&1)
        {
            C=C*A;
            C=C;
            // cout<<C<<" "<<mod1(A)<<endl;
        }
        A=A*A;
        //A=mod1(mod1(A)*mod1(A));
        pow>>=1;
    }
    return C;
}

int main()
{
    int no;
    le(no);
    int dno=no;
    int n=0;
    while(no!=0)
    {
        no=no/10;
        n++;
    }

    ll a[11];
    ll cs[11];
    a[1]=9;
    cs[1]=9;
    cs[0]=0;


    loop(i,2,11)
    {
        a[i]=9*fast_mul(10,i-1);
        cs[i]=cs[i-1]+a[i];
    }


    ll ans=0;
    loop(i,1,n)
    {
        ans=ans+i*a[i];
    }

    ans=ans+n*(dno-cs[n-1]);
    cout<<ans<<"\n";
    return 0;
}


